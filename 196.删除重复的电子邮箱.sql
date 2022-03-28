--
-- @lc app=leetcode.cn id=196 lang=mysql
--
-- [196] 删除重复的电子邮箱
--

-- @lc code=start
# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
# [理解](https://leetcode-cn.com/problems/delete-duplicate-emails/solution/dui-guan-fang-ti-jie-zhong-delete-he-de-jie-shi-by/)
delete p1
from Person p1, Person p2 
where p1.email = p2.email 
and p1.id > p2.id;
-- @lc code=end

