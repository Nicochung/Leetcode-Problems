CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE `offset` INT DEFAULT 0;
  SET `offset` = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT IFNULL ( 
          (SELECT DISTINCT `Salary`
           FROM `Employee`
           ORDER BY `Salary` DESC
           LIMIT 1 OFFSET `offset`), 
          NULL
      )
  );
END
