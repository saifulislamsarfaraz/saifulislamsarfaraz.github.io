SELECT COUNT(Customer_ID),Country
FROM Customers
GROUP BY Country
HAVING COUNT(Customer_ID)>5;


