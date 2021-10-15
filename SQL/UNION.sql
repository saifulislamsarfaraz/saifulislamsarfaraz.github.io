SELECT City FROM Customers
UNION
SELECT City FROM Suppliers
ORDER BY City;


SELECT City, Country FROM Customers
WHERE Country='Germany'
UNION
SELECT City, Country FROM Suppliers
WHERE Country='Germany'
ORDER BY City;