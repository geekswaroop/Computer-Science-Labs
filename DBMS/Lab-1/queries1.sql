mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
| veena              |
+--------------------+
5 rows in set (0.00 sec)

mysql> create table student_info
    -> (id varchar(10),
    -> name varchar(20),
    -> age int,
    -> phone int);
Query OK, 0 rows affected (0.42 sec)

mysql> describe  student_info;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| id    | varchar(10) | YES  |     | NULL    |       |
| name  | varchar(20) | YES  |     | NULL    |       |
| age   | int(11)     | YES  |     | NULL    |       |
| phone | int(11)     | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+

mysql> insert into student_info(id, name, age, phone) values('181CO135', 'Narayan Pai', 19, 123456);
Query OK, 1 row affected (0.04 sec)

mysql> insert into student_info(id, name, age, phone) values('181CO136', 'Niranjan', 19, 123456);
Query OK, 1 row affected (0.04 sec)

mysql> insert into student_info(id, name, age, phone) values('181CO134', 'Varun', 19, 123456);
Query OK, 1 row affected (0.44 sec)

mysql> insert into student_info(id, name, age, phone) values('181CO149', 'Sai Sree Harsha', 19, 123456);
Query OK, 1 row affected (0.04 sec)

mysql> select * from student_info;
+----------+-----------------+------+--------+
| id       | name            | age  | phone  |
+----------+-----------------+------+--------+
| 181CO125 | Krishna Swaroop |   19 | 123456 |
| 181CO135 | Narayan Pai     |   19 | 123456 |
| 181CO136 | Niranjan        |   19 | 123456 |
| 181CO134 | Varun           |   19 | 123456 |
| 181CO149 | Sai Sree Harsha |   19 | 123456 |
+----------+-----------------+------+--------+

mysql> create table course(
    -> courseName varchar(30),
    -> course_id varchar(30),
    -> instructor  varchar(30));

mysql> insert into course(courseName, course_id, instructor) values('COA', 'CS251', 'BT');
Query OK, 1 row affected (0.05 sec)

mysql> insert into course(courseName, course_id, instructor) values('OS', 'CS253', 'SK');
Query OK, 1 row affected (0.06 sec)


mysql> insert into course(courseName, course_id, instructor) values('NLP', 'CS224n', 'Manning');
Query OK, 1 row affected (0.05 sec)

mysql> select * from course;                                                       +------------+-----------+------------+
| courseName | course_id | instructor |
+------------+-----------+------------+
| DAA        | CS250     | Vani       |
| COA        | CS251     | BT         |
| DBMS       | CS252     | VKT        |
| OS         | CS253     | SK         |
| NLP        | CS224n    | Manning    |
+------------+-----------+------------+
