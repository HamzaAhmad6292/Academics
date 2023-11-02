
from pyspark.sql import SparkSession
from pyspark.sql.functions import avg

spark = SparkSession.builder.appName("GPA Calculation and Sorting").getOrCreate()

data = spark.read.text("txt")

data_rdd = data.rdd.map(lambda row: row.value.split(','))

def calculate_gpa(grade):
    grades_to_gpa = {"A": 4, "B": 3, "C": 2, "D": 1, "F": 0}
    return grades_to_gpa.get(grade, 0)

gpa_data = data_rdd.map(lambda x: (x[1], (calculate_gpa(x[2]), 1))) \
    .reduceByKey(lambda x, y: (x[0] + y[0], x[1] + y[1])) \
    .mapValues(lambda x: x[0] / x[1]) \
    .collect()

print("Average GPA (Each Subject):")
for subject, avg_gpa in gpa_data:
    print(f"{subject}: {avg_gpa}")

def sorting_key(roll):
    parts = roll.split("-")
    campus = parts[0]
    year = parts[1][:2]
    last_part = int(parts[1][3:])
    campus_order = {'F': 1, '1': 2, 'k': 3, 'L': 4, 'P': 5}
    return (campus_order.get(campus, 6), int(year), last_part)

sorted_data = data_rdd.sortBy(lambda x: sorting_key(x[0]))

print("\nSorted(Roll Number):")
for entry in sorted_data.collect():
    print(','.join(entry))

