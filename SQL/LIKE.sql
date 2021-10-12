SELECT * FROM Customers
WHERE CustomerName LIKE 'a%';

SELECT * FROM Customers
WHERE CustomerName LIKE '%a';


SELECT * FROM Customers
WHERE CustomerName LIKE '%or%';

SELECT * FROM Customers
WHERE CustomerName LIKE '_r%';


SELECT * FROM Customers
WHERE CustomerName LIKE 'a_%';


SELECT * FROM Customers
WHERE CustomerName LIKE 'a__%';

SELECT * FROM Customers
WHERE CustomerName LIKE 'a%o';



SELECT * FROM Customers
WHERE CustomerName NOT LIKE 'a%o';


