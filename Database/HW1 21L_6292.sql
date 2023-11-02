
/* Q1*/
create table Department(
ID int NULL ,
Name varchar(25) NULL
)
/* Q3*/
Create table  Employee(
ID_Number int not null,
First_Name varchar(25),
Last_Name varchar(25),
Dept_Id int not null
);
/* Q4*/
create table MY_Employee(
ID int not null,
Last_Name varchar(25),
First_Name varchar(25),
UserID varchar(25),
Salary int
)
/* Q5*/
insert into MY_Employee values(1,'Patel','Ralph','rpatel',795);
/* Q6*/
insert into MY_Employee(ID,Last_Name,First_Name,UserID,Salary) values(2,'Dancs','Betty','bdancs',860)
/* Q7*/
select * from MY_Employee

/* Q8*/
update MY_Employee SET Last_Name='Hammad' where Last_Name='Dancs'
/* Q9*/
update My_Employee Set Salary=3000 where Salary>=500 and Salary<=2000 and (First_Name='%t%' or Last_Name='%t%');
  /* Q10*/
Delete MY_Employee where Salary>5000
/* Q11 */


create table MYDEPT1_21L6292(
Department_ID numeric(3) Primary key,
Name varchar(25),
Location varchar(15)
)

create table MYEMP1_21L6292(
ID numeric(7) primary key ,
Name varchar(25),
Dept_ID numeric(3) Foreign Key References MYDEPT1_21L6292(Department_ID) on update cascade
)
/*Q12*/

ALTER TABLE MYDEPT1_21L6292 ALTER COLUMN Name varchar(30);
/*Q13*/
ALter table employee alter column ID_Number numeric(12)

/*Q15  */
insert into MYDEPT1_21L6292(Department_ID) values(100)
insert into MYEMP1_21L6292 values(123,'Hamza',100)
/*if we try to insert a value in the foreign key which is not in the priamry key of the oter table we will get an error */

/*Q16  */

EXEC sp_rename 'MYEMP1_21L6292', 'EMP1_21L6292';
/*17*/
EXEC sp_columns @table_name = 'EMP1_21L6292';
/*18*/
drop table EMP1_21L6292
