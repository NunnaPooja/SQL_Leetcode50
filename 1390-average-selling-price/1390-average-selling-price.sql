# Write your MySQL query statement below
select p.product_id, 
ifnull(round(sum(p.price*u.units)/sum(u.units),2),0) as average_price
/*if there is no units sold then the sum returns null and if it is null then we need to return it as 0
so the function isnull(....,0) is used*/
from Prices p
left join UnitsSold u
on p.product_id=u.product_id
and u.purchase_date between start_date and end_date
group by p.product_id