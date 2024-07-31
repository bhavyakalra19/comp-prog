# Write your MySQL query statement below
select a.name from Employee a JOIN Employee b on a.id = b.managerId group by b.managerID having count(*) >= 5;