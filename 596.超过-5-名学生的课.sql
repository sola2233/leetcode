--
-- @lc app=leetcode.cn id=596 lang=mysql
--
-- [596] 超过5名学生的课
--

-- @lc code=start
# Write your MySQL query statement below
select class 
from Courses 
group by class 
having count(student) >= 5;
-- @lc code=end

