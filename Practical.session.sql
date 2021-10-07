create table st(
    student_id INT,
    name varchar(20),
    major varchar(20),
    primary KEY (student_id)
);

DESCRIBE st;

ALTER TABLE st ADD gpa DECIMAL(2,2);
ALTER TABLE st ADD gpa DECIMAL(2,2);