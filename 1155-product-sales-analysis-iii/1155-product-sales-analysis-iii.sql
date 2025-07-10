# Write your MySQL query statement below
select s.product_id,s.year as first_year,s.quantity,s.price
from Sales s
JOIN (select product_id,min(year) as fy 
from Sales 
group by product_id) as new_table
on s.year=new_table.fy and s.product_id=new_table.product_id


