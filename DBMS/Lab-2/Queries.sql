mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| 181CO228           |
| hospital           |
| mysql              |
| nani               |
| performance_schema |
| student            |
| sys                |
| veena              |
+--------------------+

mysql> create database lab2;
Query OK, 1 row affected (0.00 sec)

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| 181CO228           |
| hospital           |
| lab2               |
| mysql              |
| nani               |
| performance_schema |
| student            |
| sys                |
| veena              |
+--------------------+

mysql> create table lab2(
    -> id int PRIMARY KEY,
    -> name varchar(30),
    -> branch varchar(30),
    -> marks int);
Query OK, 0 rows affected (0.39 sec)

mysql> describe lab2;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| id     | int(11)     | NO   | PRI | NULL    |       |
| name   | varchar(30) | YES  |     | NULL    |       |
| branch | varchar(30) | YES  |     | NULL    |       |
| marks  | int(11)     | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+




mysql> create table Student(
    -> id int PRIMARY KEY,
    -> name varchar(30));
Query OK, 0 rows affected (0.29 sec)

mysql> alter table Student add branch varchar(30);

mysql> describe Student;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| id     | int(11)     | NO   | PRI | NULL    |       |
| name   | varchar(30) | YES  |     | NULL    |       |
| branch | varchar(30) | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+

mysql> alter table Student add marks int;
Query OK, 0 rows affected (0.56 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe student;
ERROR 1146 (42S02): Table 'lab2.student' doesn't exist
mysql> describe Student;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| id     | int(11)     | NO   | PRI | NULL    |       |
| name   | varchar(30) | YES  |     | NULL    |       |
| branch | varchar(30) | YES  |     | NULL    |       |
| marks  | int(11)     | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+

mysql> alter table Student modify column marks varchar(50);
Query OK, 0 rows affected (0.70 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe Student;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| id     | int(11)     | NO   | PRI | NULL    |       |
| name   | varchar(30) | YES  |     | NULL    |       |
| branch | varchar(30) | YES  |     | NULL    |       |
| marks  | varchar(50) | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+


