
drop table Team_Table
drop table Coach_Table
drop table Work_Experience_Table
drop table  Bats_Table
drop table Affiliation_Table
drop table Player_Table

create table Team_Table(
TeamNum int primary key,
TeamName varchar(25) unique,
City varchar(25),
Manager varchar(25)
)
create table Coach_Table(
TeamNum  int unique not null foreign key references Team_Table(TeamNum) on delete cascade on update cascade,
CoachName varchar(25) unique not null,
Telephone bigint
primary key(TeamNum,CoachName)
)
create table Work_Expereience_Table(
TeamNum  int unique not null foreign key references Team_Table(TeamNum) on delete cascade on update cascade,
CoachName varchar(25) unique not null foreign key references Coach_Table(CoachName)  on delete cascade on update cascade,
ExperienceType varchar(25) ,
YearsofExperience int,
primary key(TeamNum,CoachName)
)
create table Player_Table(
PlayerNum int  not null primary key,
PlayerName varchar(25),
Age int,
)
create table Affiliation_Table(
PlayerNum int foreign key references Player_Table(PlayerNum) on delete cascade on update cascade,
TeamNum int foreign key references Team_Table(TeamNum) on delete cascade on update cascade,
Years int,
BattingAvg int,
)
create table Bats_Table(
TeamNum int foreign key references Team_Table(TeamNum),
SerialNum int ,
Manufacturer varchar(25)
)
/*Question 1*/
select TeamName,city from Team_Table where TeamNum>15 order by TeamName;

/*Question 2*/
select PlayerName from Player_Table where Age<18

/* Question3*/
select Coach_Table.CoachName from Coach_Table
inner join  Work_Expereience_Table on
Coach_Table.CoachName=Work_Expereience_Table.CoachName 
and Coach_Table.TeamNum=Work_Expereience_Table.TeamNum
where Work_Expereience_Table.ExperienceType='college coaches' 
and (Work_Expereience_Table.YearsofExperience=5 or
Work_Expereience_Table.YearsofExperience=10)

/*Question4*/
select sum(YearsofExperience) as Waqar_Experience from 
Work_Expereience_Table where CoachName='Waqar'and 
TeamNum=25 group by CoachNam

/*Question5*/
select Distinct count(ExperienceType) from Work_Expereience_Table where CoachName='Waqar' and TeamNum=3;

/*Question6*/
select CoachName,sum(yearsofexperience) as Experience 
from Work_Expereience_Table group by CoachName

/*Question7*/
select distinct Manufacturer as Manufacturers
from Bats_Table inner join  Team_Table
on  Bats_Table.TeamNum=Team_Table.TeamNum 
where  TeamName='Leagues';

/*Question8*/ 
select PlayerName from Player_Table as A
inner join Affiliation_Table as B
on A.PlayerNum=B.PlayerNum 
inner join Team_Table as C on B.TeamNum=C.TeamNum 
where TeamName='Yankees' and B.Years>=8

/*Question9*/

select  A.CoachName,sum(YearsofExperience) as Total_years
from Work_Expereience_Table as A
inner join Coach_Table as B on A.CoachName=B.CoachName  
inner join Team_Table as C on B.TeamNum=C.TeamNum
where C.TeamName='Royals' and A.YearsofExperience>8
group by A.CoachName

/*Question10*/
select top(5) playerName from Player_Table order by Age Asc 

/*Question11*/
select top(5) playerName from Player_Table where RIGHT(PlayerName, CHARINDEX(' ', REVERSE(PlayerName)) - 1) LIKE 'M%'order by Age Asc 

/*Question12*/
select PlayerName from Player_Table as A
join(
select PlayerNum,count(Distinct B.Years) as total
from Affiliation_Table as B group by B.PlayerNum having count(Distinct B.Years)>2
) as C
on A.PlayerNum=C.PlayerNum

/*Question 13*/
select PlayerName from Player_Table as A inner join Affiliation_Table as B on  A.PlayerNum=B.PlayerNum Except (select PlayerNum from Affiliation_Table) 

/*Question 14*/

select A.playerName,count(B.TeamNum) as Teams_Played 
from Player_Table as A 
inner join Affiliation_Table as B 
on A.PlayerNum=B.PlayerNum group by A.PlayerName 

/* Question 15*/
select A.TeamName,AVG(B.BattingAvg)  from Team_Table as A
inner join Affiliation_Table as B on A.TeamNum=B.TeamNum
group by A.TeamName


