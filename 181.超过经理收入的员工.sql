--
-- @lc app=leetcode.cn id=181 lang=mysql
--
-- [181] 超过经理收入的员工
--

-- @lc code=start
# Write your MySQL query statement below
# 自连接，内连接
select e1.name as Employee
from Employee e1, Employee e2 
where e1.salary > e2.salary 
and e1.managerId = e2.id;
-- @lc code=end

