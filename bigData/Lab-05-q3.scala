object GradeFinder {
  def findGrade(score: Double): String = {
    if (score >= 90) {
      "A"
    } else if (score >= 80) {
      "B"
    } else if (score >= 70) {
      "C"
    } else if (score >= 60) {
      "D"
    } else {
      "F"
    }
  }

  def main(args: Array[String]): Unit = {
    val testScores = List(33.0, 52.0, 75.0, 98.0, 45.0)

    for (score <- testScores) {
      val grade = findGrade(score)
      println(s"Score: $score, Grade: $grade")
    }
  }
}
