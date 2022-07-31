# Write your MySQL query statement below
SELECT name Customers
FROM Customers c
WHERE c.id NOT IN (SELECT o.customerId FROM Orders o)