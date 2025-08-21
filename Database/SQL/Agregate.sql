--find the avarage salary of instracor in computer science department 
SELECT avg(salary)
from instracor
WHERE dept_name = 'Comput_Sci';

--Find the total number of instracors who teach a course int spring 2018 semester 


--Find the avarage salary of instractor in each department 
SELECT dept_name, avg(salary) as avg_salary
from instracor group by dept_name;

--find Courses offered in Fall2017 and Spring 2018
--basically here we create a 
SELECT distinct course_id
FROM section WHERE semester = 'Fall' AND year = 2017 AND course_id 
in (SELECT course_id from section WHERE semester = 'spring' AND year = 2018);


