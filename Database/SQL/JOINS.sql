SELECT Orders.OrderID, Employees.LastName, Employees.FirstName
FROM Orders
INNER JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID
ORDER BY Orders.OrderID;

SELECT Orders.OrderID, Employees.LastName, Employees.FirstName
FROM Orders
LEFT JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID
ORDER BY Orders.OrderID;

SELECT Orders.OrderID, Employees.LastName, Employees.FirstName
FROM Orders
RIGHT JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID
ORDER BY Orders.OrderID;

SELECT Orders.OrderID, Employees.LastName, Employees.FirstName
FROM Orders
FULL OUTER JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID
ORDER BY Orders.OrderID;

--SELF JOIN 
