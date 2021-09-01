# Write your MySQL query statement below
# DELETE FROM `Person`
# WHERE `Id` NOT IN (SELECT DISTINCT `Email` FROM `Person`);
DELETE `p1`
FROM `Person` `p1`, `Person` `p2`
WHERE `p1`.`Email` = `p2`.`Email` AND `p1`.`Id` > `p2`.`Id`;
