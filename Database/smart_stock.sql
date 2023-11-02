
/****** Object:  Database [Project1]    Script Date: 3/19/2023 11:06:45 PM ******/
CREATE DATABASE [Project1]




GO
ALTER DATABASE [Project1] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [Project1] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [Project1] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [Project1] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [Project1] SET ARITHABORT OFF 
GO
ALTER DATABASE [Project1] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [Project1] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [Project1] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [Project1] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [Project1] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [Project1] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [Project1] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [Project1] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [Project1] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [Project1] SET  DISABLE_BROKER 
GO
ALTER DATABASE [Project1] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [Project1] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [Project1] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [Project1] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [Project1] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [Project1] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [Project1] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [Project1] SET RECOVERY FULL 
GO
ALTER DATABASE [Project1] SET  MULTI_USER 
GO
ALTER DATABASE [Project1] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [Project1] SET DB_CHAINING OFF 
GO
ALTER DATABASE [Project1] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [Project1] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [Project1] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [Project1] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
EXEC sys.sp_db_vardecimal_storage_format N'Project1', N'ON'
GO
ALTER DATABASE [Project1] SET QUERY_STORE = OFF
GO
USE [Project1]
GO
/****** Object:  Table [dbo].[categories]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[categories](
	[No] [int] NULL,
	[Category] [varchar](100) NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Client]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Client](
	[Client] [varchar](100) NULL,
	[No] [int] NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[company]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[company](
	[No] [int] NULL,
	[Company] [varchar](100) NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[DC]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DC](
	[No] [int] NULL,
	[Name] [varchar](100) NOT NULL,
	[Size] [varchar](100) NOT NULL,
	[Quantity] [int] NOT NULL,
	[Date] [datetime] NULL,
	[Client] [varchar](100) NOT NULL,
	[Company] [varchar](100) NULL,
	[DC_No] [int] NOT NULL,
	[category] [varchar](100) NULL,
	[Q_No] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[DC_No] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[IC]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[IC](
	[No] [int] NULL,
	[IC_no] [int] NOT NULL,
	[Name] [varchar](100) NOT NULL,
	[Size] [varchar](100) NOT NULL,
	[Quantity] [int] NOT NULL,
	[Client] [varchar](100) NOT NULL,
	[Date] [datetime] NULL,
	[Company] [varchar](100) NOT NULL,
	[category] [varchar](100) NULL,
PRIMARY KEY CLUSTERED 
(
	[IC_no] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ID]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ID](
	[No] [int] NULL,
	[ID] [int] NOT NULL,
	[Date] [date] NULL,
	[Q_No] [int] NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[inventory]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[inventory](
	[No] [int] NULL,
	[Name] [varchar](100) NOT NULL,
	[Price] [int] NOT NULL,
	[Quantity] [int] NOT NULL,
	[Size] [varchar](100) NOT NULL,
	[Company] [varchar](100) NOT NULL,
	[Quote] [int] NULL,
	[Category] [varchar](100) NULL,
 CONSTRAINT [PK_inventory] PRIMARY KEY CLUSTERED 
(
	[Name] ASC,
	[Size] ASC,
	[Company] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[invoice]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[invoice](
	[No] [int] NULL,
	[Name] [varchar](100) NOT NULL,
	[Quantity] [int] NOT NULL,
	[Price] [int] NOT NULL,
	[invoice_no] [int] NOT NULL,
	[client] [varchar](100) NOT NULL,
	[Date] [datetime] NULL,
	[Company] [varchar](100) NULL,
	[Size] [varchar](100) NULL,
	[Discount] [float] NULL,
	[category] [varchar](100) NULL,
PRIMARY KEY CLUSTERED 
(
	[invoice_no] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ledgers_1]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ledgers_1](
	[No] [int] NULL,
	[Client] [varchar](100) NOT NULL,
	[Date] [datetime] NULL,
	[Debit] [int] NULL,
	[DC_No] [int] NULL,
	[Invoice_No] [int] NULL,
	[Balance] [bigint] NULL,
	[Price] [int] NULL,
	[Voucher_No] [varchar](100) NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Name]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Name](
	[Name] [varchar](100) NOT NULL,
	[No] [int] NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Quotations]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Quotations](
	[No] [int] NULL,
	[Size] [varchar](100) NOT NULL,
	[Company] [varchar](100) NOT NULL,
	[Client] [varchar](100) NULL,
	[Date] [datetime] NULL,
	[Quantity] [int] NULL,
	[Name] [varchar](100) NOT NULL,
	[category] [varchar](100) NULL,
	[Price] [int] NULL,
	[Q_No] [int] NOT NULL,
	[Discount] [float] NULL,
PRIMARY KEY CLUSTERED 
(
	[Q_No] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Quote_No]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Quote_No](
	[Q_No] [int] NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[sizes]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[sizes](
	[No] [int] NULL,
	[Size] [varchar](100) NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[T_Invoice]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[T_Invoice](
	[No] [int] NULL,
	[Invoice_No] [int] NOT NULL,
	[Name] [varchar](100) NOT NULL,
	[Size] [varchar](100) NOT NULL,
	[Company] [varchar](100) NOT NULL,
	[Quantity] [int] NULL,
	[Client] [varchar](100) NULL,
	[Price] [int] NULL,
	[Discount] [float] NULL,
	[Date] [datetime] NULL,
	[DC_No] [int] NULL,
	[category] [varchar](100) NULL,
	[Q_No] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[Invoice_No] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[T_ledgers]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[T_ledgers](
	[No] [int] NOT NULL,
	[DC_No] [int] NULL,
	[Invoice_No] [int] NULL,
	[Client] [varchar](100) NULL,
	[Price] [int] NULL,
	[Debit] [int] NULL,
	[Balance] [int] NULL,
	[Date] [datetime] NULL,
	[Voucher_No] [varchar](100) NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[T_Quote]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[T_Quote](
	[No] [int] NULL,
	[Name] [varchar](100) NULL,
	[Size] [varchar](100) NULL,
	[Company] [varchar](100) NULL,
	[Category] [varchar](100) NULL,
	[Client] [varchar](100) NULL,
	[date] [datetime] NULL,
	[Quantity] [varchar](100) NULL,
	[Price] [int] NULL,
	[Discount] [float] NULL,
	[Q_No] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[Q_No] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TDC]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TDC](
	[No] [int] NULL,
	[IC_No] [int] NOT NULL,
	[Date] [datetime] NULL,
	[Client] [varchar](100) NULL,
	[Company] [varchar](100) NULL,
	[Price] [int] NULL,
	[Total_Price] [int] NULL,
	[Discount] [float] NULL,
	[Invoice_No] [int] NULL,
	[DC_No] [int] NULL,
	[Debit] [int] NULL,
	[Balance] [int] NULL,
	[Name] [varchar](100) NULL,
	[Size] [varchar](100) NULL,
	[Quantity] [int] NULL,
	[category] [varchar](100) NULL,
	[Q_No] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[IC_No] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Temp]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Temp](
	[Name] [varchar](100) NULL,
	[Client] [varchar](100) NULL,
	[No] [int] NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TIC]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TIC](
	[Name] [varchar](100) NULL,
	[IC_No] [int] NULL,
	[SIze] [varchar](100) NULL,
	[Company] [varchar](100) NULL,
	[Quantity] [int] NULL,
	[Client] [varchar](100) NULL,
	[Date] [datetime] NULL,
	[category] [varchar](100) NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[user1]    Script Date: 3/19/2023 11:06:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[user1](
	[No] [int] NULL,
	[UserName] [varchar](100) NOT NULL,
	[Password] [int] NOT NULL
) ON [PRIMARY]
GO
ALTER TABLE [dbo].[ledgers_1] ADD  CONSTRAINT [DF_ledgers_1_Voucher_No]  DEFAULT ('NA') FOR [Voucher_No]
GO
ALTER TABLE [dbo].[T_ledgers] ADD  CONSTRAINT [DF_T_ledgers_Voucher_No]  DEFAULT ('NA') FOR [Voucher_No]
GO
ALTER TABLE [dbo].[DC]  WITH CHECK ADD FOREIGN KEY([Name], [Size], [Company])
REFERENCES [dbo].[inventory] ([Name], [Size], [Company])
GO
ALTER TABLE [dbo].[IC]  WITH CHECK ADD FOREIGN KEY([Name], [Size], [Company])
REFERENCES [dbo].[inventory] ([Name], [Size], [Company])
GO
ALTER TABLE [dbo].[invoice]  WITH CHECK ADD FOREIGN KEY([Name], [Size], [Company])
REFERENCES [dbo].[inventory] ([Name], [Size], [Company])
GO
ALTER TABLE [dbo].[ledgers_1]  WITH CHECK ADD FOREIGN KEY([DC_No])
REFERENCES [dbo].[DC] ([DC_No])
GO
ALTER TABLE [dbo].[ledgers_1]  WITH CHECK ADD FOREIGN KEY([Invoice_No])
REFERENCES [dbo].[invoice] ([invoice_no])
GO
ALTER TABLE [dbo].[Quotations]  WITH CHECK ADD FOREIGN KEY([Name], [Size], [Company])
REFERENCES [dbo].[inventory] ([Name], [Size], [Company])
GO
ALTER TABLE [dbo].[T_Invoice]  WITH CHECK ADD FOREIGN KEY([Name], [Size], [Company])
REFERENCES [dbo].[inventory] ([Name], [Size], [Company])
GO
ALTER TABLE [dbo].[T_Invoice]  WITH CHECK ADD FOREIGN KEY([DC_No])
REFERENCES [dbo].[DC] ([DC_No])
GO
ALTER TABLE [dbo].[T_ledgers]  WITH CHECK ADD FOREIGN KEY([DC_No])
REFERENCES [dbo].[DC] ([DC_No])
GO
ALTER TABLE [dbo].[T_ledgers]  WITH CHECK ADD FOREIGN KEY([Invoice_No])
REFERENCES [dbo].[invoice] ([invoice_no])
GO
ALTER TABLE [dbo].[T_Quote]  WITH CHECK ADD FOREIGN KEY([Name], [Size], [Company])
REFERENCES [dbo].[inventory] ([Name], [Size], [Company])
GO
ALTER TABLE [dbo].[TDC]  WITH CHECK ADD FOREIGN KEY([Name], [Size], [Company])
REFERENCES [dbo].[inventory] ([Name], [Size], [Company])
GO
ALTER TABLE [dbo].[TDC]  WITH CHECK ADD FOREIGN KEY([DC_No])
REFERENCES [dbo].[invoice] ([invoice_no])
GO
ALTER TABLE [dbo].[TDC]  WITH CHECK ADD FOREIGN KEY([Invoice_No])
REFERENCES [dbo].[invoice] ([invoice_no])
GO
USE [master]
GO
ALTER DATABASE [Project1] SET  READ_WRITE 
GO
