/* Question 1*/

CREATE TABLE Student
	(
	RollNum varchar(50), 
	Name varchar(50) ,
	Gender varchar(50), 
	Phone bigint 
	)
	CREATE TABLE Attendance
	(
	RollNum varchar(50) ,
	Date date NULL,
	Status char(10) NULL,
	ClassVenue smallint NULL
	)
	CREATE TABLE ClassVenue
	(
	ID int ,
	Building varchar(50) NULL,
	RoomNum smallint NULL,
	Teacher varchar(50) NULL
	)
	CREATE TABLE Teacher
	(
	Name varchar(50) ,
	Designation varchar(50), 
	Department varchar(50) 
	)

insert into Student values ('L216260','ALiAhmed','male',033323333)
insert into Student values ('L216234','Zain','male',033323333)
insert into Student values ('L216222','Hania','female',033323333)
insert into Student values ('L216292','Hania','female',033323333)



insert into Attendence values ('L216292','02-02-2016','P',2)
insert into Attendence values ('L216260','02-22-2016','P',1)
insert into Attendence values ('L216234','02-22-2016','A',2)

insert into ClassVenue values(1,'CS',2,'Sarim')
insert into ClassVenue values(3,'civil',7,'Bismillah')
insert into ClassVenue values(3,'civil',7,'Samia')


insert into Teacher values('Sarim','Assis Prof','Com sic')
insert into Teacher values('Bismillah','Lecturer','Civil Eng')
insert into Teacher values('Samia','Prof','Elec eng')
insert into Teacher values('Kashif Zafar','Prof','Elec eng')



/* Question 2*/
ALter table Student alter column Roll_No varchar(50) not null
ALter table  Student add primary key(Roll_No)

ALter table ClassVenue alter column ID int not null
ALter table ClassVenue add primary key(ID)

Alter table Teacher alter column Name varchar(50) not null
ALter table Teacher add primary key(Name)

/*Question 3*/

ALTER TABLE Attendence
ADD CONSTRAINT FK_Attendence
FOREIGN KEY (Roll_Num) REFERENCES Student(Roll_No) on delete  cascade;

ALTER TABLE ClassVenue
ADD CONSTRAINT FK_Name
FOREIGN KEY (Teacher) REFERENCES Teacher(Name) on update cascade;

/*Question 4*/
ALTER TABLE Student
ADD warning_count INT NULL;

alter table student drop column phone_no

/*Question 5*/
/* i)*/
insert into student values('L2162334','Fozan','Male',3.2)

/* ii)*/
insert into Teacher(Name) values('Ali')   
insert into ClassVenue values(3,'CS',5,'Ali') /* this is invalid until we insert Name ali in the Priamry key of Teachers table*/

/* iii)*/
update Teacher set Name='Dr Kashif Zafar' where Name='Kashif Zafar' 

/* iv)*/
delete  Student where Roll_No='L144124'

/* v)*/
delete  Student where Roll_No='L164123'

/*vi)*/
delete Attendence where Roll_Num='l164124' and status='A';



/*Question 6*/
/*i)*/
ALter table Teacher add constraint UN_Name unique(Name)

/*ii)*/
ALTER TABLE Students
ALTER COLUMN Gender varchar(50) NULL

ADD CONSTRAINT CK_Gender CHECK (Gender IN ('male', 'female'));









