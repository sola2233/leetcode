--
-- @lc app=leetcode.cn id=627 lang=mysql
--
-- [627] 变更性别
--

-- @lc code=start
# Write your MySQL query statement below
# 方法1.利用 case 函数
# 方法2.char(ascii('m') + ascii('f') - ascii(sex)) 或 异或
update Salary 
set sex = (case sex when 'm' then 'f' else 'm' end);
-- @lc code=end

