--
-- @lc app=leetcode.cn id=184 lang=mysql
--
-- [184] 部门工资最高的员工
--

-- @lc code=start
# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary
from Employee e, Department d, (select departmentId, max(salary) salary from Employee group by departmentId) m 
where e.departmentId = d.id 
and e.departmentId = m.departmentId 
and e.salary = m.salary;
-- @lc code=end

