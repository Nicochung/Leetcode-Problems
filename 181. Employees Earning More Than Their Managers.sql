# Write your MySQL query statement below
# SELECT `Employee`
# FROM (SELECT `A`.`Name` AS `Employee`, `A`.`Salary` AS `Salary`, `B`.`Salary` AS `ManagerSalary`   
#       FROM `Employee` AS `A`
#       JOIN `Employee` AS `B`
#       ON `A`.`ManagerId` = `B`.`Id`) AS `Self Join Table`
# WHERE `Salary` > `ManagerSalary`;

# SELECT
#     a.Name AS 'Employee'
# FROM
#     Employee AS a,
#     Employee AS b
# WHERE
#     a.ManagerId = b.Id
#         AND a.Salary > b.Salary
# ;

SELECT
     a.NAME AS Employee
FROM Employee AS a JOIN Employee AS b
     ON a.ManagerId = b.Id
     AND a.Salary > b.Salary
;
