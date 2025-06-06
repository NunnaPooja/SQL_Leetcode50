# Write your MySQL query statement below
select s.user_id, round(AVG(if(c.action='confirmed',1,0)),2) as confirmation_rate /*round(AVG(Count(c.user_id)),2)  this cannot be performed as count is already an aggregate fucntion and avg of that cannot be performed in sql*/
from Signups s
left join Confirmations c
on s.user_id=c.user_id
group by s.user_id
