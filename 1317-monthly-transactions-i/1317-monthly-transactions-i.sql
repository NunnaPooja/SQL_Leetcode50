# Write your MySQL query statement below
select  DATE_FORMAT(trans_date, '%Y-%m') as month,
country,
count(state) as trans_count,
count(if(state='approved',1,null)) as approved_count, /*if u use count(if(....,1,0)) then count cannot ignore 0,it will ignore if it null*/
/*sum(if(state='approved',1,0)) can also be used instead of before line*/
sum(amount) as trans_total_amount,
sum(if(state='approved',amount,0)) as approved_total_amount
from Transactions
group by month,country
order by month,country desc
