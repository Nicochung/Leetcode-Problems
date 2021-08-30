# Write your MySQL query statement below
# SELECT `class`
# FROM (SELECT `class`, COUNT(`class`) AS cnt
#     FROM (SELECT DISTINCT * FROM `courses`) AS T
#     GROUP BY `class`) AS TEMP
# WHERE `cnt` >= 5;

# SELECT
#     class
# FROM
#     (SELECT
#         class, COUNT(DISTINCT student) AS num
#     FROM
#         courses
#     GROUP BY class) AS temp_table
# WHERE
#     num >= 5
# ;

SELECT
    class
FROM
    courses
GROUP BY class
HAVING COUNT(DISTINCT student) >= 5
;
