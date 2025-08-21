SELECT SupplierName
FROM Suppliers
WHERE EXISTS (SELECT ProductName FROM Products WHERE Products.SupplierID = Suppliers.supplierID AND Price < 20);


SELECT SupplierName 
FROM Suppliers
WHERE EXISTS (SELECT ProductName FROM Products WHERE Products.supplierID=Suppliers.supplierID AND Price < 20);

SELECT SupplierName 
FROM Suppliers
WHERE EXISTS (SELECT ProductName FROM Products WHERE Products.supplierID=Suppliers.supplierID AND Price < 40);


SELECT SupplierName 
FROM Suppliers
WHERE EXISTS (SELECT ProductName FROM Products WHERE Products.supplierID = Suppliers.supplierID AND Price < 60);


