# Write your MySQL query statement below
select a.id as ID from Weather a JOIN Weather b on a.temperature > b.temperature and DATEDIFF(a.recordDate,b.recordDate) = 1;