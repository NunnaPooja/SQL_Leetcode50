# Write your MySQL query statement below
select r.contest_id,round(COUNT(r.user_id)/(select count(Users.user_id) from Users)*100,2) as percentage 
from Register r
group by contest_id
order by percentage desc,contest_id




