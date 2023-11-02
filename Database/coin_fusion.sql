USE [master]
GO
/****** Object:  Database [se proj]    Script Date: 3/19/2023 2:27:30 PM ******/
CREATE DATABASE [proj]



USE [proj]



CREATE TABLE [dbo].[Wallet](
	[Wallet_Id] [varchar](50) NOT NULL Primary key,
	[Currency_code] [varchar](50) NULL,
	[Balance] [float] NULL,
	[Last_update] [datetime] NULL,

) ON [PRIMARY]
CREATE TABLE [dbo].[Users](
	[User_Id] [varchar](50) NOT NULL primary key ,
	[Name] [varchar](50) NOT NULL,
	[Email] [varchar](50) NULL,
	[Password] [varchar](50) NULL,
	[Wallet_Id] [varchar](50) NULL,
	[Date_of_birth] [date] NULL,
	foreign key (Wallet_Id) references Wallet(Wallet_Id) 

) ON [PRIMARY]


CREATE TABLE [dbo].[Currency](
	[Name] [varchar](50) NOT NULL ,
	[Price] [float] NOT NULL,
	[Market_cap] [float] NULL,
	[Volume] [nchar](10) NULL,
	[Total_supply] [float] NULL,
	[Minimum_Price] [float] NULL,
	[Max_Price] [float] NULL
) ON [PRIMARY]

/****** Object:  Table [dbo].[Deposit]    Script Date: 3/19/2023 2:27:30 PM ******/


CREATE TABLE [dbo].[Deposit](
	[Deposit_Id] [varchar](50) NOT NULL primary key,
	[Wallet_Id] [varchar](50) NOT NULL,
	[user_Id] [varchar](50) NULL,
	[currency] [varchar](50) NULL,
	[ammount] [float] NULL,
	[date] [datetime] NULL,
	foreign key (Wallet_Id) references Wallet(Wallet_Id),
	foreign key (User_Id) references Users(User_Id)
) ON [PRIMARY]

CREATE TABLE [dbo].[Order](
	[Order_Id] [varchar](50) NOT NULL primary key,
	[User_Id] [varchar](50) NULL,
	[Wallet_Id] [varchar](50) NULL,
	[Order_type] [varchar](50) NULL,
	[Currency_from] [varchar](50) NULL,
	[Currency_to] [varchar](50) NULL,
	[Price] [float] NULL,
	[Quantity] [float] NULL,
	[Status] [varchar](50) NULL,
	foreign key (User_Id) references Users(User_Id),
	foreign key (Wallet_Id) references Wallet(Wallet_Id) 
) ON [PRIMARY]

CREATE TABLE [dbo].[transaction](
	[Transaction_Id] [varchar](50)not  NULL primary key ,
	[Wallet_Id_from] [varchar](50) NULL,
	[Wallet_Id_to] [varchar](50) NULL,
	[Price] [float] NULL,
	[Currency] [varchar](50) NULL,
	[Quantity] [float] NULL,
	[date] [datetime] NULL,
		foreign key (Wallet_Id_from) references Wallet(Wallet_Id),
		foreign key (Wallet_Id_to) references Wallet(Wallet_Id) 


) ON [PRIMARY]



CREATE TABLE [dbo].[withdrawal](
	[withdrawl_id] [int] NOT NULL primary key,
	[User_id] [varchar](50) NULL,
	[ammount] [float] NULL,
	[currency] [varchar](50) NULL,
	[method] [varchar](50) NULL,
	[date] [date] NULL,
	[wallet_id] [varchar](50) NULL,
	foreign key (User_Id) references Users(User_Id)
) ON [PRIMARY]


