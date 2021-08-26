# # Write your MySQL query statement below
# SELECT DISTINCT `A`.`Email`
# FROM `Person` `A`, `PERSON` `B`
# WHERE `A`.`Email` = `B`.`Email`
# AND `A`.`Id` <> `B`.`Id`;

# select Email from
# (
#   select Email, count(Email) as num
#   from Person
#   group by Email
# ) as statistic
# where num > 1
# ;

select Email
from Person
group by Email
having count(Email) > 1;
