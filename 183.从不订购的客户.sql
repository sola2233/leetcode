--
-- @lc app=leetcode.cn id=183 lang=mysql
--
-- [183] 从不订购的客户
--

-- @lc code=start
# Write your MySQL query statement below
# 方法1.子查询
-- select name as Customers
-- from Customers 
-- where Id not in (select CustomerId from Orders);
# 方法2.左外连接
select c.Name as Customers 
from Customers c 
left join Orders o 
on c.Id = o.CustomerId 
where o.CustomerId is NULL;
-- @lc code=end

