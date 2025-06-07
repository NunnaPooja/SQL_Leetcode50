# Write your MySQL query statement below
select round(avg(if(min_customer_pref_delivery_date=min_order_date,1,0))*100,2) as immediate_percentage
from (select min(order_date) as min_order_date,
min(customer_pref_delivery_date) as min_customer_pref_delivery_date
from Delivery 
group by customer_id) as min_delivery_table



