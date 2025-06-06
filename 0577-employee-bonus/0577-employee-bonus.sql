# Write your MySQL query statement below
select e.name,b.bonus
from Employee e
left join Bonus b
on e.empId=b.empId
where b.bonus<1000 or b.bonus is null 
/*Condition in WHERE:
The condition b.bonus < 1000 OR b.bonus IS NULL ensures that:
Rows with bonuses less than 1000 are included.
Rows with no bonus (i.e., b.bonus IS NULL) are also included.*/
/*if we do and b.bonus<1000 then it will include thomas as well as even that is of >1000 and it stores null*/