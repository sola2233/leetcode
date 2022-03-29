--
-- @lc app=leetcode.cn id=178 lang=mysql
--
-- [178] 分数排名
--

-- @lc code=start
-- 好难。。。
# Write your MySQL query statement below
select 
    s1.score 'score', 
    count(distinct s2.score) 'rank' 
from Scores s1 
    inner join Scores s2 
    on s1.score <= s2.score 
group by 
    s1.id, s1.score 
order by 
    s1.score desc;
-- @lc code=end

