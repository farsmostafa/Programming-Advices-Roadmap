-- ==============================================================================
-- SQL Data Manipulation Language (DML) Reference
-- ==============================================================================

-- ------------------------------------------------------------------------------
-- 1. Insert Into Statement
-- Description: Adds new rows (records) into a table. You can specify the columns
-- or omit them if you are providing values for all columns in exact order.
-- Syntax: INSERT INTO [TableName] (Col1, Col2) VALUES (Val1, Val2);
-- ------------------------------------------------------------------------------
INSERT INTO Employees (FullName, Salary, IsActive)
VALUES ('Fars Mostafa', 8500.00, 1);
GO

-- Multiple rows insertion example:
INSERT INTO Employees (FullName, Salary, IsActive)
VALUES 
    ('Ahmed Ali', 6000.00, 1),
    ('Omar Khaled', 4500.00, 0);
GO

-- ------------------------------------------------------------------------------
-- 2. Update Statement
-- Description: Modifies existing records in a table. 
-- WARNING: Always use a WHERE clause. If omitted, ALL records will be updated!
-- Syntax: UPDATE [TableName] SET [ColumnName] = NewValue WHERE Condition;
-- ------------------------------------------------------------------------------
UPDATE Employees 
SET Salary = 9500.00, IsActive = 1 
WHERE EmployeeID = 1;
GO

-- ------------------------------------------------------------------------------
-- 3. Delete Statement
-- Description: Removes existing records from a table.
-- WARNING: Always use a WHERE clause. If omitted, ALL records will be deleted!
-- Syntax: DELETE FROM [TableName] WHERE Condition;
-- ------------------------------------------------------------------------------
DELETE FROM Employees 
WHERE IsActive = 0;
GO

-- ------------------------------------------------------------------------------
-- 4. Select Into Statement
-- Description: Creates a BRAND NEW table on the fly and populates it with the 
-- result set of a SELECT statement. Commonly used for quick backups or archiving.
-- Syntax: SELECT Col1, Col2 INTO [NewTableName] FROM [ExistingTable] WHERE Condition;
-- ------------------------------------------------------------------------------
SELECT EmployeeID, FullName, Salary 
INTO Employees_Backup 
FROM Employees 
WHERE IsActive = 1;
GO

-- ------------------------------------------------------------------------------
-- 5. Insert Into .. Select From Statement
-- Description: Copies data from a source table and inserts it into an ALREADY 
-- EXISTING table. The columns in both tables must have matching data types.
-- Syntax: INSERT INTO [ExistingTable] (Col1, Col2) SELECT Col1, Col2 FROM [SourceTable];
-- ------------------------------------------------------------------------------
-- Assuming 'ArchivedEmployees' table already exists in the database:
INSERT INTO ArchivedEmployees (EmployeeID, FullName)
SELECT EmployeeID, FullName 
FROM Employees 
WHERE IsActive = 0;
GO