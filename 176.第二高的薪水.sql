--
-- @lc app=leetcode.cn id=176 lang=mysql
--
-- [176] 第二高的薪水
--

-- @lc code=start
# Write your MySQL query statement below
-- 方法1.在小于最大值的 salary 里找 max
-- 方法2.利用 ifnull 和 limit，可以看题解
select max(salary) SecondHighestSalary 
from Employee 
where salary < (select max(salary) from Employee);
-- @lc code=end

