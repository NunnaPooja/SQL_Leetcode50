# Write your MySQL query statement below
select employee_id,department_id
from Employee e
where primary_flag='Y'
group by employee_id
union
select employee_id,department_id
from Employee e
group by employee_id
having count(primary_flag)=1