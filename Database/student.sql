

SELECT Country FROM Customers;
SELECT DISTINCT Country FROM Customers;
SELECT COUNT(DISTINCT Country) FROM Customers;


USE sql_store;
SELECT * 
FROM customers
WHERE customers_id = 1;
ORDER BY first_name;

SELECT * FROM Customers
WHERE Country = 'Mexico';