--
-- @lc app=leetcode.cn id=177 lang=mysql
--
-- [177] 第N高的薪水
--

-- @lc code=start
-- 利用 order by 降序，distinct 去重，limit 分页
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set N := N - 1;
  RETURN (
      # Write your MySQL query statement below.
      -- ifnull(
      -- (select distinct salary from Employee order by salary desc limit 1 offset N), 
      -- NULL) 
      --- 为什么不加 ifnull 也可以
      SELECT DISTINCT Salary 
      FROM Employee 
      ORDER BY Salary DESC 
      LIMIT N, 1 
  );
END
-- @lc code=end

