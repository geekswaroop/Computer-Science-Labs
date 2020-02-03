-- Question 1 (Create/Describe)
mysql> use week5;
Database changed
mysql> create table Faculty(
    -> FacultyID int, 
    -> Name varchar(40),
    -> Department varchar(40),
    -> Gender varchar(2));
Query OK, 0 rows affected (0.30 sec)

mysql> describe Faculty;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| FacultyID  | int(11)     | YES  |     | NULL    |       |
| Name       | varchar(40) | YES  |     | NULL    |       |
| Department | varchar(40) | YES  |     | NULL    |       |
| Gender     | varchar(2)  | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+
4 rows in set (0.01 sec)

--**(VVIMP)Question 2A (USE CASE)
mysql> insert into Faculty values(1,'Ram', 'Computer Science', 'M');
Query OK, 1 row affected (0.04 sec)

mysql> insert into Faculty values(1,'Raj', 'CS', 'M');
Query OK, 1 row affected (0.04 sec)

mysql> insert into Faculty values(3,'Radha', 'CE', 'F');
Query OK, 1 row affected (0.04 sec)

mysql> insert into Faculty values(4,'Radhakrishna', 'CS', 'M');
Query OK, 1 row affected (0.04 sec)

mysql> insert into Faculty values(5,'Ramakrishna', 'CE', 'M');
Query OK, 1 row affected (0.05 sec)

mysql> insert into Faculty values(6,'Seetha', 'CS', 'F');
Query OK, 1 row affected (0.04 sec)

mysql> select * from Faculty;
+-----------+--------------+------------------+--------+
| FacultyID | Name         | Department       | Gender |
+-----------+--------------+------------------+--------+
|         1 | Ram          | Computer Science | M      |
|         1 | Raj          | CS               | M      |
|         3 | Radha        | CE               | F      |
|         4 | Radhakrishna | CS               | M      |
|         5 | Ramakrishna  | CE               | M      |
|         6 | Seetha       | CS               | F      |
+-----------+--------------+------------------+--------+
mysql> update Faculty  set Department = CASE
    -> when Department='CS' then 'Computer Science'
    -> when Department='CE' then 'Computer Engineering'
    -> else Department
    -> end;
Query OK, 5 rows affected (0.04 sec)
Rows matched: 6  Changed: 5  Warnings: 0

mysql> select * from Faculty;
+-----------+--------------+----------------------+--------+
| FacultyID | Name         | Department           | Gender |
+-----------+--------------+----------------------+--------+
|         1 | Ram          | Computer Science     | M      |
|         1 | Raj          | Computer Science     | M      |
|         3 | Radha        | Computer Engineering | F      |
|         4 | Radhakrishna | Computer Science     | M      |
|         5 | Ramakrishna  | Computer Engineering | M      |
|         6 | Seetha       | Computer Science     | F      |
+-----------+--------------+----------------------+--------+
-- Question 2B (CASE)
mysql> update Faculty set Gender=CASE
    -> when Gender = 'M' then 'Male'
    -> when Gender = 'F' then 'Female'
    -> else Gender
    -> end;
Query OK, 6 rows affected (0.05 sec)
Rows matched: 6  Changed: 6  Warnings: 0

mysql> select * from Faculty;
+-----------+--------------+----------------------+--------+
| FacultyID | Name         | Department           | Gender |
+-----------+--------------+----------------------+--------+
|         1 | Ram          | Computer Science     | Male   |
|         1 | Raj          | Computer Science     | Male   |
|         3 | Radha        | Computer Engineering | Female |
|         4 | Radhakrishna | Computer Science     | Male   |
|         5 | Ramakrishna  | Computer Engineering | Male   |
|         6 | Seetha       | Computer Science     | Female |
+-----------+--------------+----------------------+--------+

--**Question 3 (RENAME, ALTER TABLE)
mysql> rename table Faculty to FacultyDetails;
Query OK, 0 rows affected (0.13 sec)

mysql> show tables;
+-----------------+
| Tables_in_week5 |
+-----------------+
| FacultyDetails  |
+-----------------+

mysql> alter table FacultyDetails change Name FirstName varchar(30);
Query OK, 6 rows affected (0.93 sec)
mysql> describe FacultyDetails;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| FacultyID  | int(11)     | YES  |     | NULL    |       |
| FirstName  | varchar(30) | YES  |     | NULL    |       |
| Department | varchar(40) | YES  |     | NULL    |       |
| Gender     | varchar(10) | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+

-- Question 4A
mysql> alter table FacultyDetails add Age int(3);
Query OK, 0 rows affected (0.70 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> alter table FacultyDetails add Course varchar(30);
Query OK, 0 rows affected (0.89 sec)
Records: 0  Duplicates: 0  Warnings: 0

-- Question 4B
mysql> alter table FacultyDetails modify course varchar(40);
Query OK, 0 rows affected (0.13 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe FacultyDetails;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| FacultyID  | int(11)     | YES  |     | NULL    |       |
| FirstName  | varchar(30) | YES  |     | NULL    |       |
| Department | varchar(40) | YES  |     | NULL    |       |
| Gender     | varchar(10) | YES  |     | NULL    |       |
| Age        | int(3)      | YES  |     | NULL    |       |
| course     | varchar(40) | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+

--Question 4C
mysql> alter table FacultyDetails drop column course;
Query OK, 0 rows affected (0.69 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe FacultyDetails;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| FacultyID  | int(11)     | YES  |     | NULL    |       |
| FirstName  | varchar(30) | YES  |     | NULL    |       |
| Department | varchar(40) | YES  |     | NULL    |       |
| Gender     | varchar(10) | YES  |     | NULL    |       |
| Age        | int(3)      | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+

--Question 5A
mysql> select Department from FacultyDetails  where FirstName like 'a%';
Empty set (0.00 sec)
--Question 5B
mysql> select Department from FacultyDetails  where FirstName like 'a%';
Empty set (0.00 sec)
--Question 5C
mysql> select Department from FacultyDetails  where FirstName like 'a%h';
Empty set (0.01 sec)
--Question 5D
mysql> select Department from FacultyDetails  where FirstName like '%ab%';
Empty set (0.01 sec)
--Question 5E
mysql> select Department from FacultyDetails  where FirstName like '__c%';
Empty set (0.00 sec)
--Question 5F
mysql> select Department from FacultyDetails  where FirstName like 'k__%';
Empty set (0.00 sec)

--Question 6 (Update)
mysql> update FacultyDetails set Age = 21 where FirstName='Ram';
Query OK, 1 row affected (0.06 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> update FacultyDetails set Age = 22 where FirstName='Raj';
Query OK, 1 row affected (0.04 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> update FacultyDetails set Age = 32 where FirstName='Radha';
Query OK, 1 row affected (0.05 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> update FacultyDetails set Age = 21 where FirstName='Radhakrishna';
Query OK, 1 row affected (0.08 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> update FacultyDetails set Age = 27 where FirstName='Ramakrishna';
Query OK, 1 row affected (0.04 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> update FacultyDetails set Age = 19 where FirstName='Seetha';
Query OK, 1 row affected (0.04 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from FacultyDetails;
+-----------+--------------+----------------------+--------+------+
| FacultyID | FirstName    | Department           | Gender | Age  |
+-----------+--------------+----------------------+--------+------+
|         1 | Ram          | Computer Science     | Male   |   21 |
|         1 | Raj          | Computer Science     | Male   |   22 |
|         3 | Radha        | Computer Engineering | Female |   32 |
|         4 | Radhakrishna | Computer Science     | Male   |   21 |
|         5 | Ramakrishna  | Computer Engineering | Male   |   27 |
|         6 | Seetha       | Computer Science     | Female |   19 |
+-----------+--------------+----------------------+--------+------+

mysql> select FirstName from FacultyDetails where Age>25;
+-------------+
| FirstName   |
+-------------+
| Radha       |
| Ramakrishna |
+-------------+
2 rows in set (0.00 sec)
mysql> select FirstName from FacultyDetails where age > any(select age from FacultyDetails where Department='ComputerScience');
Empty set (0.00 sec)

--**Question 7
mysql> select FirstName from FacultyDetails where FacultyID = any(select FacultyID from FacultyAddressDetails where city='Chennai' or city='Calcutta');
+--------------+
| FirstName    |
+--------------+
| Ram          |
| Radhakrishna |
+--------------+

--Question 8A
mysql> select Fname, Lname from Faculty where exists (select FacultyID from FacultyLoad);
+----------+-------+
| Fname    | Lname |
+----------+-------+
| Ram      | Sham  |
| Ram      | Shamu |
| Raju     | Sham  |
| Rajendra | Sham  |
| harpreet | Sham  |
+----------+-------+

--Question 8B
mysql> select Fname, Lname from Faculty where not exists (select FacultyID from FacultyLoad);
Empty set (0.00 sec)

--Question 8C
mysql> delete from Faculty where Lname='Jha';
Query OK, 0 rows affected (0.00 sec)


--Question 8D
mysql> update Faculty set Lname='Mishra' where FacultyID = 1;
Query OK, 1 row affected (0.05 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from Faculty;
+-----------+----------+--------+------------------+
| FacultyID | Fname    | Lname  | Website          |
+-----------+----------+--------+------------------+
|         1 | Ram      | Mishra | www.ram.com      |
|         2 | Ram      | Shamu  | www.shamu.com    |
|         3 | Raju     | Sham   | www.raju.com     |
|         3 | Rajendra | Sham   | www.rajendra.com |
|         3 | harpreet | Sham   | www.harpreet.com |
+-----------+----------+--------+------------------+

-- Question 9A
mysql> select sum(Salary) from Faculty where Lname = 'Sham';
+-------------+
| sum(Salary) |
+-------------+
|       66000 |
+-------------+

--Question 9B
mysql> select count(*) from Student where Subject='COA' and Year=2020;
+----------+
| count(*) |
+----------+
|        2 |
+----------+



