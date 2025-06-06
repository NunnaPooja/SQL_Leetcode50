# Write your MySQL query statement below
select e1.name /*u need to return manager name not e2.name*/
from Employee e1
left join Employee e2
on e1.id=e2.managerId
group by e1.id,e1.name /*grouping criteria by which u will perform count function*/
having count(e2.managerId)>=5