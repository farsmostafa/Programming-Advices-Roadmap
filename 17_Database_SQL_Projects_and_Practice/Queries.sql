Use VehicleMakesDB

------------------------------------------------------------------

-- Notes
-- 1. Where For Data and Having For Results
-- 2. When you searh word in arabic use N'Word'
--		ex:- Where Name = N'فارس'


------------------------------------------------------------------

--  Problem 1: Create Master View 

Create View VehicleMasterDetails As
SELECT      VehicleDetails.ID, VehicleDetails.MakeID, Makes.Make, VehicleDetails.ModelID, MakeModels.ModelName, VehicleDetails.SubModelID, SubModels.SubModelName, VehicleDetails.BodyID, Bodies.BodyName, VehicleDetails.Vehicle_Display_Name, VehicleDetails.Year, VehicleDetails.DriveTypeID, 
                   DriveTypes.DriveTypeName, VehicleDetails.Engine, VehicleDetails.Engine_CC, VehicleDetails.Engine_Cylinders, VehicleDetails.Engine_Liter_Display, VehicleDetails.FuelTypeID, FuelTypes.FuelTypeName, VehicleDetails.NumDoors
FROM         FuelTypes INNER JOIN
                   Bodies INNER JOIN
                   Makes INNER JOIN
                   MakeModels ON Makes.MakeID = MakeModels.MakeID INNER JOIN
                   SubModels ON MakeModels.ModelID = SubModels.ModelID INNER JOIN
                   VehicleDetails ON Makes.MakeID = VehicleDetails.MakeID AND MakeModels.ModelID = VehicleDetails.ModelID AND SubModels.SubModelID = VehicleDetails.SubModelID ON Bodies.BodyID = VehicleDetails.BodyID INNER JOIN
                   DriveTypes ON VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID ON FuelTypes.FuelTypeID = VehicleDetails.FuelTypeID

Select * From VehicleMasterDetails

------------------------------------------------------------------

-- Problem 2: Get all vehicles made between 1950 and 2000 

Select *
From VehicleDetails
Where Year Between 1950 and 2000

------------------------------------------------------------------

-- Problem 3 : Get number vehicles made between 1950 and 2000 

Select Count(*) as NumberOfVehicles
From VehicleDetails
Where Year Between 1950 and 2000

------------------------------------------------------------------

-- Problem 4 : Get number vehicles made between 1950 and 2000 per
--             make and order them by Number Of Vehicles Descending 

Select Makes.Make , Count(*) as NumberOfVehicles
From VehicleDetails Join Makes On VehicleDetails.MakeID = Makes.MakeID
Where Year Between 1950 and 2000
Group By Make
Order By Count(*) Desc

-- OR

Select Make , Count(*) as NumberOfVehicles
From VehicleMasterDetails
Where Year Between 1950 and 2000
Group By Make
Order By Count(*) Desc

------------------------------------------------------------------

-- Problem 5 : Get All Makes that have manufactured more than 
--             12000 Vehicles in years 1950 to 2000

Select Makes.Make , Count(*) as NumberOfVehicles
From VehicleDetails Join Makes On VehicleDetails.MakeID = Makes.MakeID
Where Year Between 1950 and 2000
Group By Make
Having Count(*) > 12000
Order By Count(*) Desc

-- OR [Without Having]

Select * From (
Select Makes.Make , Count(*) as NumberOfVehicles
From VehicleDetails Join Makes On VehicleDetails.MakeID = Makes.MakeID
Where Year Between 1950 and 2000
Group By Make
) R1
Where NumberOfVehicles > 12000
Order By NumberOfVehicles Desc

------------------------------------------------------------------

-- Problem 6: Get number of vehicles made between 1950 and 2000
--            per make and add total vehicles column beside 


Select Makes.Make , Count(*) as NumberOfVehicles , (Select Count(*) From VehicleDetails) As TotalVehicles 
From VehicleDetails Join Makes On VehicleDetails.MakeID = Makes.MakeID
Where Year Between 1950 and 2000
Group By Make
Order By NumberOfVehicles Desc

------------------------------------------------------------------

--  Problem 7: Get number of vehicles made between 1950 and 2000
--             per make and add total vehicles column beside it,
--             then calculate it's percentage

Select * , (NumberOfVehicles* 1.0 / TotalVehicles ) as Perc 
From   (Select Makes.Make , Count(*) as NumberOfVehicles , (Select Count(*) From VehicleDetails) As TotalVehicles
		From VehicleDetails Join Makes On VehicleDetails.MakeID = Makes.MakeID
		Where Year Between 1950 and 2000
		Group By Make
		) R1
Order By NumberOfVehicles Desc

-- OR

Select * , Cast(NumberOfVehicles as float ) / Cast(TotalVehicles as float) as Perc 
From   (Select Makes.Make , Count(*) as NumberOfVehicles , (Select Count(*) From VehicleDetails) As TotalVehicles
		From VehicleDetails Join Makes On VehicleDetails.MakeID = Makes.MakeID
		Where Year Between 1950 and 2000
		Group By Make
		) R1
Order By NumberOfVehicles Desc

------------------------------------------------------------------

--  Problem 8: Get Make, FuelTypeName and Number of Vehicles per 
--             FuelType per Make between 1950 and 2000

Select M.Make , F.FuelTypeName , Count(*)
From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
					  Join FuelTypes F on V.FuelTypeID = F.FuelTypeID
Where V.Year Between 1950 and 2000
Group By M.Make , F.FuelTypeName
Order By M.Make   

------------------------------------------------------------------

-- Problem 9: Get all vehicles that runs with GAS

Select V.* ,F.FuelTypeName 
From VehicleDetails V Join FuelTypes F on V.FuelTypeID = F.FuelTypeID
Where F.FuelTypeName = N'GAS'

------------------------------------------------------------------

-- Problem 10: Get all Makes that runs with GAS

Select distinct M.Make , F.FuelTypeName 
From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
					  Join FuelTypes F on V.FuelTypeID = F.FuelTypeID
Where F.FuelTypeName = N'GAS'
Order By M.Make   

------------------------------------------------------------------

-- Problem 11: Get Total Makes that runs with GAS

Select Count(Make) as TotalMakesRunsOnGas 
From (
		Select distinct M.Make , F.FuelTypeName 
		From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
								Join FuelTypes F on V.FuelTypeID = F.FuelTypeID
		Where F.FuelTypeName = N'GAS'
	 ) R1

------------------------------------------------------------------

--  Problem 12: Count Vehicles by make and order them by 
--              NumberOfVehicles from high to low. 

Select M.Make , Count(*) As NumberOfVehicles
From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
Group By M.Make
Order By Count(*) Desc 

------------------------------------------------------------------

-- Problem 13: Get all Makes/Count Of Vehicles that 
--             manufactures more than 20K Vehicles 

Select M.Make , Count(*) As NumberOfVehicles
From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
Group By M.Make
Having Count(*) > 20000
Order By Count(*) Desc 

-- OR without Having

Select * From (
	Select M.Make , Count(*) As NumberOfVehicles
	From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
	Group By M.Make
) R1
Where NumberOfVehicles > 20000
Order By NumberOfVehicles Desc

------------------------------------------------------------------

-- Problem 14: Get all Makes with make starts with 'B'

Select distinct Make
From Makes
Where Make Like 'B%'
Order By Make   

------------------------------------------------------------------

-- Problem 15: Get all Makes with make ends with 'W'

Select distinct Make
From Makes
Where Make Like '%W'
Order By Make  

------------------------------------------------------------------

-- Problem 16: Get all Makes that manufactures DriveTypeName = FWD

Select distinct M.Make , D.DriveTypeName
From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
					  Join DriveTypes D on V.DriveTypeID = D.DriveTypeID
Where D.DriveTypeName = N'FWD'
Order By M.Make   

------------------------------------------------------------------

--  Problem 17: Get total Makes that Mantufactures DriveTypeName=FWD

Select Count(*) as MakeWithFHD From 
(
	Select distinct M.Make , D.DriveTypeName
	From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
						  Join DriveTypes D on V.DriveTypeID = D.DriveTypeID
	Where D.DriveTypeName = N'FWD'
) R1

------------------------------------------------------------------

-- Problem 18: Get total vehicles per DriveTypeName Per Make and 
--             order them per make asc then per total Desc

Select distinct M.Make , D.DriveTypeName , Count(*) Total
From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
					  Join DriveTypes D on V.DriveTypeID = D.DriveTypeID
Group By M.Make , D.DriveTypeName
Order by M.Make asc , Total desc

------------------------------------------------------------------

-- Problem 19: Get total vehicles per DriveTypeName Per Make
--             then filter only results with total > 10,000

Select distinct M.Make , D.DriveTypeName , Count(*) Total
From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
					  Join DriveTypes D on V.DriveTypeID = D.DriveTypeID
Group By M.Make , D.DriveTypeName
Having Count(*) > 10000
Order by M.Make asc , Total desc

------------------------------------------------------------------

-- Problem 20: Get all Vehicles that number of doors is not specified

Select * 
From VehicleDetails
Where NumDoors is Null

------------------------------------------------------------------

-- Problem 21: Get Total Vehicles that number of doors is not specified

Select Count(*) TotalWithNoSpecifiedDoors 
From VehicleDetails
Where NumDoors is Null

------------------------------------------------------------------

-- Problem 22: Get percentage of vehicles that has no doors specified

Select Cast(TotalWithNoSpecifiedDoors As Float)  / Cast (TotalVehicles As Float)
From (
	Select Count(*) as TotalWithNoSpecifiedDoors , (Select Count(*) From VehicleDetails) as TotalVehicles
	From VehicleDetails
	Where NumDoors is Null
)R1


-- OR

select 
(
	CAST(	(select count(*) as TotalWithNoSpecifiedDoors from VehicleDetails
	where NumDoors is Null) as float)
	/
	Cast( (select count(*) from VehicleDetails as TotalVehicles) as float)
) as PercOfNoSpecifiedDoors

------------------------------------------------------------------

-- Problem 23: Get MakeID , Make, SubModelName for all vehicles
--             that have SubModelName 'Elite'

Select distinct M.MakeID, M.Make, S.SubModelName 
From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
					  Join SubModels S on V.SubModelID = S.SubModelID
Where S.SubModelName = 'Elite'
Order By M.Make   

------------------------------------------------------------------

-- Problem 24: Get all vehicles that have Engines > 3 Liters 
--             and have only 2 doors

Select * 
From VehicleDetails
Where Engine_Liter_Display > 3 and NumDoors = 2 

------------------------------------------------------------------

-- Problem 25: Get make and vehicles that the engine contains
--             'OHV' and have Cylinders = 4

Select M.Make , V.* 
From VehicleDetails V Join Makes M on V.MakeID = M.MakeID 
Where V.Engine Like '%OHV%' and V.Engine_Cylinders = 4

------------------------------------------------------------------

--  Problem 26: Get all vehicles that their body is 'Sport Utility'
--              and Year > 2020

Select B.BodyName , V.* 
From VehicleDetails V Join Bodies B on V.BodyID = B.BodyID 
Where B.BodyName = 'Sport Utility' and V.Year > 2020

------------------------------------------------------------------

-- Problem 27: Get all vehicles that their Body is 'Coupe'
--             or 'Hatchback' or 'Sedan'

Select B.BodyName , V.* 
From VehicleDetails V Join Bodies B on V.BodyID = B.BodyID 
Where B.BodyName in ('Coupe','Hatchback','Sedan')

------------------------------------------------------------------

-- Problem 28: Get all vehicles that their body is 'Coupe' or
--             'Hatchback' or 'Sedan' and manufactured in year
--             2008 or 2020 or 2021

Select B.BodyName , V.* 
From VehicleDetails V Join Bodies B on V.BodyID = B.BodyID 
Where B.BodyName in ('Coupe','Hatchback','Sedan') and V.Year in (2008,2020,2021)

------------------------------------------------------------------

--  Problem 29: Return found=1 if there is any vehicle made 
--              in year 1950

-- With Case When
	Select Case 
			When Count(*) > 0 Then 1
			Else 0
		End As Found
	From VehicleDetails 
	Where Year = 1950

-- OR With If Exists & Print

If Exists
(
	Select Top 1 *
	From VehicleDetails 
	Where Year = 1950
)
Begin
	Print 1;
End
Else
Begin
	print 0
End

-- OR

select found=1 
where 
exists (
        select top 1 * from VehicleDetails where Year =1950
      )

------------------------------------------------------------------

-- Problem 30: Get all Vehicle_Display_Name, NumDoors and
--             add extra column to describe number of doors 
--             by words, and if door is null display 'Not Set'

Select Vehicle_Display_Name , NumDoors ,
		Case 
			When NumDoors = 0 Then 'Zero Doors'
			When NumDoors = 1 Then 'One Door'
			When NumDoors = 2 Then 'Two Doors'
			When NumDoors = 3 Then 'Three Doors'
			When NumDoors = 4 Then 'Four Doors'
			When NumDoors = 5 Then 'Five Doors'
			When NumDoors = 6 Then 'Sex Doors'
			When NumDoors = 8 Then 'Eight Doors'
			When NumDoors is Null Then 'Not Set'
			Else 'UnKnown'
		End As DoorDescription
From VehicleDetails 

------------------------------------------------------------------

--   Problem 31: Get all Vehicle_Display_Name, year and add extra
--               column to calculate the age of the car then sort
--               the results by age desc.

-- that YEAR in capital Letters is built in function in SQL Server that will give you the year of the given date :-) , 
-- and the year in small letters is the column name

Select Vehicle_Display_Name ,VehicleDetails.Year, YEAR(Getdate())- VehicleDetails.Year as Age
From VehicleDetails 
Order By Age Desc

------------------------------------------------------------------

-- Problem 32: Get all Vehicle_Display_Name, year, Age for vehicles 
--             that their age between 15 and 25 years old

Select * From
(
	Select Vehicle_Display_Name ,VehicleDetails.Year, YEAR(Getdate())- VehicleDetails.Year as Age
	From VehicleDetails 
)R1
where R1.Age Between 15 and 25
Order By Age asc

------------------------------------------------------------------

-- Problem 33: Get Minimum Engine CC , Maximum Engine CC , and
--             Average Engine CC of all Vehicles

Select 
	Min(Engine_CC) MinimimEngineCC, 
	Max(Engine_CC) MaximumEngineCC, 
	Avg(Engine_CC) AverageEngineCC
From VehicleDetails

------------------------------------------------------------------

--  Problem 34: Get all vehicles that have the minimum Engine_CC

Select Vehicle_Display_Name
From VehicleDetails
Where Engine_CC = 
				(
					Select Min(Engine_CC)
					From VehicleDetails
				)
------------------------------------------------------------------

-- Problem 35: Get all vehicles that have the Maximum Engine_CC

Select Vehicle_Display_Name
From VehicleDetails
Where Engine_CC = 
				(
					Select Max(Engine_CC)
					From VehicleDetails
				)

------------------------------------------------------------------

 -- Problem 36: Get all vehicles that have Engin_CC below average

Select Vehicle_Display_Name
From VehicleDetails
Where Engine_CC < 
				(
					Select Avg(Engine_CC)
					From VehicleDetails
				)

------------------------------------------------------------------

-- Problem 37: Get total vehicles that have Engin_CC above average

Select Vehicle_Display_Name
From VehicleDetails
Where Engine_CC > 
				(
					Select Avg(Engine_CC)
					From VehicleDetails
				)

------------------------------------------------------------------
-- Problem 38: Get all unique Engin_CC and sort them Desc

Select Distinct Engine_CC
From VehicleDetails
Order By Engine_CC desc


------------------------------------------------------------------

-- Problem 39: Get the maximum 3 Engine CC

Select Distinct Top 3 Engine_CC
From VehicleDetails
Order By Engine_CC desc

------------------------------------------------------------------

-- Problem 40: Get all vehicles that has one of the Max 3 Engine CC

Select Vehicle_Display_Name
From VehicleDetails
Where Engine_CC in (
						Select Distinct Top 3 Engine_CC
						From VehicleDetails
						Order By Engine_CC desc
					)

------------------------------------------------------------------

-- Problem 41: Get all Makes that manufactures one of the Max 3 Engine CC

Select Distinct M.Make
From VehicleDetails V Join Makes M On V.MakeID = M.MakeID
Where Engine_CC in (
						Select Distinct Top 3 Engine_CC
						From VehicleDetails
						Order By Engine_CC desc
					)

------------------------------------------------------------------

-- Problem 42: Get a table of unique Engine_CC and calculate tax per Engine CC
	-- 0 to 1000    Tax = 100
	-- 1001 to 2000 Tax = 200
	-- 2001 to 4000 Tax = 300
	-- 4001 to 6000 Tax = 400
	-- 6001 to 8000 Tax = 500
	-- Above 8000   Tax = 600
	-- Otherwise    Tax = 0

Select  Engine_CC , 
	Case
		When Engine_CC Between 0 and 1000 Then 100
		When Engine_CC Between 1001 and 2000 Then 200
		When Engine_CC Between 2001 and 4000 Then 300
		When Engine_CC Between 4001 and 6000 Then 400
		When Engine_CC Between 6001 and 8000 Then 500
		When Engine_CC > 8000 Then 600
		Else  0
	End As Tax
From 
(
	Select Distinct  Engine_CC
	From VehicleDetails					
)R1
Order By Engine_CC desc

------------------------------------------------------------------

--  Problem 43: Get Make and Total Number Of Doors Manufactured Per Make
 
 Select M.Make , Sum(V.NumDoors) TotalNumberOfDoors
 From VehicleDetails V Join Makes M On V.MakeID = M.MakeID
 Group By M.Make
 Order By TotalNumberOfDoors desc

------------------------------------------------------------------

 -- Problem 44: Get Total Number Of Doors Manufactured by 'Ford'
 
 Select M.Make , Sum(V.NumDoors) TotalNumberOfDoors
 From VehicleDetails V Join Makes M On V.MakeID = M.MakeID
 Group By M.Make
 Having M.Make = 'Ford'

------------------------------------------------------------------

 -- Problem 45: Get Number of Models Per Make

 Select M.Make , Count(*) NumberOfModels
 From  Makes M Join MakeModels O on M.MakeID = O.MakeID
 Group By M.Make 
 Order By Count(*) desc

------------------------------------------------------------------
 
 -- Problem 46: Get the highest 3 manufacturers that make the 
 --             highest number of models

 Select Top 3 M.Make , Count(*) NumberOfModels
 From  Makes M Join MakeModels O on M.MakeID = O.MakeID
 Group By M.Make 
 Order By Count(*) desc

------------------------------------------------------------------
 
 -- Problem 47: Get the highest number of models manufactured

 Select Top 1 Count(*) MaxNumberOfModels
 From MakeModels O Join Makes M on M.MakeID = O.MakeID
 Group By M.Make 
 order by Count(*)  Desc

 -- OR

select Max(NumberOfModels) as MaxNumberOfModels
from
(
	SELECT        Makes.Make, COUNT(*) AS NumberOfModels
	FROM            Makes INNER JOIN MakeModels 
					ON Makes.MakeID = MakeModels.MakeID
	GROUP BY Makes.Make	
) R1

------------------------------------------------------------------
 
 -- Problem 48: Get the highest Manufacturers manufactured the 
 --             highest number of models
 -- !!! remember that they could be more than one manufacturer
 --     have the same high number of models

 Select M.Make , Count(*) MaxNumberOfModels
 From MakeModels O Join Makes M on M.MakeID = O.MakeID
 Group By M.Make 
 Having Count(*) = 
 (
	 Select Top 1 Count(*) MaxNumberOfModels
	 From MakeModels O Join Makes M on M.MakeID = O.MakeID
	 Group By M.Make 
	 Order By Count(*) desc
 )

 -- OR

 SELECT Makes.Make, COUNT(*) AS NumberOfModels
FROM            Makes INNER JOIN MakeModels 
				ON Makes.MakeID = MakeModels.MakeID
GROUP BY Makes.Make
having COUNT(*) = (
	select Max(NumberOfModels) as MaxNumberOfModels
	from
	(
			SELECT MakeID, COUNT(*) AS NumberOfModels
			FROM MakeModels
			GROUP BY MakeID									
	) R1
)

------------------------------------------------------------------

-- Problem 49: Get the Lowest Manufacturers manufactured 
--             the lowest number of models
-- !!! remember that they could be more than one manufacturer 
--     have the same Lowest  number of models

 Select M.Make , Count(*) MaxNumberOfModels
 From MakeModels O Join Makes M on M.MakeID = O.MakeID
 Group By M.Make 
 Having Count(*) = 
 (
	 Select Top 1 Count(*) MaxNumberOfModels
	 From MakeModels O Join Makes M on M.MakeID = O.MakeID
	 Group By M.Make 
	 Order By Count(*) Asc
 )

 -- OR

 SELECT Makes.Make, COUNT(*) AS NumberOfModels
FROM            Makes INNER JOIN MakeModels 
				ON Makes.MakeID = MakeModels.MakeID
GROUP BY Makes.Make
having COUNT(*) = (
	select Min(NumberOfModels) as MaxNumberOfModels
	from
	(
			SELECT MakeID, COUNT(*) AS NumberOfModels
			FROM MakeModels
			GROUP BY MakeID									
	) R1
)


------------------------------------------------------------------

-- Problem 50: Get all Fuel Types , each time the result should
--             be showed in random order Self Referential Queries
--             Restore this simple Database First.
-- !!! Note that the NewID() function will generate GUID for each row 

Select *
From FuelTypes
Order By NewID()

------------------------------------------------------------------
 
Use EmployeesDB

Select * From Employees

-- Problem 51: Get all employees that have manager along with Manager's name.

Select E.EmployeeID , E.Name ,  E.Salary ,M.Name as ManagerName
From Employees E Join Employees M on E.ManagerID = M.EmployeeID

------------------------------------------------------------------
 
-- Problem 52: Get all employees that have manager or does not have manager
--             along with Manager's name, incase no manager name show null

Select E.EmployeeID , E.Name ,  E.Salary , M.Name as ManagerName
From Employees E Left Join Employees M on E.ManagerID = M.EmployeeID

------------------------------------------------------------------
 
-- Problem 53: Get all employees that have manager or does not have manager
--             along with Manager's name, incase no manager name the same
--             employee name as manager to himself

Select E.EmployeeID , E.Name ,  E.Salary ,
	Case
		When M.Name is Null Then E.Name
		Else M.Name
	End As ManagerName
From Employees E Left Join Employees M on E.ManagerID = M.EmployeeID

------------------------------------------------------------------
 
-- Problem 54: Get All Employees managed by 'Mohammed'

Select E.EmployeeID , E.Name ,  E.Salary , M.Name
From Employees E Join Employees M on E.ManagerID = M.EmployeeID
Where M.Name = 'Mohammed'

------------------------------------------------------------------

























