CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      select distinct x.salary from (
        select salary, dense_rank() over(order by salary desc) as rn from Employee
      ) x
      where x.rn = N
  );
END