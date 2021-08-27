# Write your MySQL query statement below
SELECT `w2`.`id` AS `Id`
FROM `Weather` `w1`, `Weather` `w2`
WHERE DATEDIFF(`w1`.`recordDate`,`w2`.`recordDate`) = -1
AND `w1`.`Temperature` < `w2`.`Temperature`;
