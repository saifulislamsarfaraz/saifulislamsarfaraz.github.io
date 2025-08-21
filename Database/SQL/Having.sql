SELECT COUNT(Customer_ID),Country
FROM Customers
GROUP BY Country
HAVING COUNT(Customer_ID)>5;

SELECT COUNT(Customer_ID),Country
FROM Customers
GROUP BY Country
HAVING COUNT(Customer_ID)>5
ORDER BY COUNT(Customer_ID) DESC;


SELECT Employees.LastName, COUNT(Orders.OrderID) AS NumberOfOrders
FROM (Orders
LEFT JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID)
GROUP BY LastName
HAVING COUNT(Orders.OrderID) > 10
ORDER BY COUNT(Orders.OrderID) DESC;
