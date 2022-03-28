--
-- @lc app=leetcode.cn id=175 lang=mysql
--
-- [175] 组合两个表
--

-- @lc code=start
# Write your MySQL query statement below
# 左外连接
select p.firstName, p.lastName, a.city, a.state 
from Person p left join Address a 
on p.personId = a.personId;
-- @lc code=end

