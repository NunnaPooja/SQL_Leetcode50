# Write your MySQL query statement below
select st.student_id,
st.student_name ,
su.subject_name ,/*Use su.subject_name instead of e.subject_name*/
COUNT(e.subject_name) as attended_exams

from Students st
cross join Subjects su
left outer join Examinations e
on su.subject_name=e.subject_name and st.student_id=e.student_id 
group by st.student_id,st.student_name,su.subject_name
order by st.student_id,su.subject_name


