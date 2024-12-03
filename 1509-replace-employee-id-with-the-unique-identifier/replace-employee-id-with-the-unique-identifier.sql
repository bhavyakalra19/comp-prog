# Write your MySQL query statement below
select unique_id, name from Employees as a Left Join EmployeeUNI as b on a.id = b.id;