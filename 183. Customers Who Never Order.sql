# Write your MySQL query statement below
# SELECT `Name` AS `Customers`
# FROM `Customers`
# LEFT JOIN `Orders`
# ON `Customers`.`id` = `Orders`.`CustomerId`
# WHERE `CustomerId` IS NULL;

select customers.name as 'Customers'
from customers
where customers.id not in
(
    select customerid from orders
);
