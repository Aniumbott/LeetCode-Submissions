# Write your MySQL query statement below
select employee_id
from (select * from  employees e 
      union select * from  salaries s ) 
t where employee_id not in
(
    select e.employee_id from employees e 
        join salaries s
        on e.employee_id = s.employee_id
        where e.name is not null
        and s.salary is not null
) 
order by  1