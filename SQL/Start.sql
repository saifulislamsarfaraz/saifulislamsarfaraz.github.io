SELECT * FROM Customers
WHERE Country='Germany' AND City='Berlin';

SELECT * FROM Customers 
WHERE City = 'Berlin'OR City='Munchen';

SELECT * FROM Customers 
WHERE Country= 'Germany' OR Country='Spain';


SELECT * FROM Customers
WHERE NOT Countr='Germany';

SELECT * FROM Customers
WHERE Country='Germany' AND (City='Berlin' OR City='Munchin');

SELECT * FROM Customers
WHERE NOT Country='Germany' AND NOT Country='USA';


