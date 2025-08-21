SELECT ProductName 
FROM Products
WHERE ProductID = ANY (SELECT ProductID FROM OrderDetails WHERE Quantity = 10);

SELECT ProductName
FROM Products
WHERE ProductID = AMY (SELECT ProductID FROM OrderDetails WHERE Quantity= 10);



