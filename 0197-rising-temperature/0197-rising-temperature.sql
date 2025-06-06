# Write your MySQL query statement below
select w1.id
from Weather w1
left join Weather w2 /* we are creating same table to attach with w1*/
ON DATE_SUB(w1.recordDate, INTERVAL 1 DAY) = w2.recordDate /*DATE_SUB(w1.recordDate, INTERVAL 1 DAY) subtracts 1 day from w1.recordDate.*/
where w1.temperature>w2.temperature
order by w1.recordDate /*is this line necessary?If you want your query results to be returned in chronological order by date, then yes, you need ORDER BY w1.recordDate.*/
/*we can use left join as well as for table2 we get null for first row and Comparing w1.temperature > NULL results in UNKNOWN (which behaves like false in WHERE),
 so those rows are excluded.
 So effectively:
The LEFT JOIN acts like an INNER JOIN here because the WHERE clause filters out rows with no matching w2 (since comparison with NULL fails).
Therefore, in this query, using LEFT JOIN or INNER JOIN will give the same result.*/
