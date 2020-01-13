-- Question-1
mysql> create table Student( RegistrationNumber int, FirstName varchar(10), LastName varchar(7), Address text, DoB date, Age smallint, MobileNumber bigint);
Query OK, 0 rows affected (0.31 sec)

mysql> describe Student;
+--------------------+-------------+------+-----+---------+-------+
| Field              | Type        | Null | Key | Default | Extra |
+--------------------+-------------+------+-----+---------+-------+
| RegistrationNumber | int(11)     | YES  |     | NULL    |       |
| FirstName          | varchar(10) | YES  |     | NULL    |       |
| LastName           | varchar(7)  | YES  |     | NULL    |       |
| Address            | text        | YES  |     | NULL    |       |
| DoB                | date        | YES  |     | NULL    |       |
| Age                | smallint(6) | YES  |     | NULL    |       |
| MobileNumber       | bigint(20)  | YES  |     | NULL    |       |
+--------------------+-------------+------+-----+---------+-------+

--Question2
mysql> insert into Student values(1, "A", "Z", "ABC", '2000-08-23', 19, 9876521);
Query OK, 1 row affected (0.05 sec)

mysql> insert into Student values(1, "Abraham", "Z", "ABC", '1998-10-01', 20, 9876521);
Query OK, 1 row affected (0.03 sec)

mysql> insert into Student values(1, "Abraham", "Zeal", "ABC", '1998-10-01', 20, 9874521);
Query OK, 1 row affected (0.03 sec)

mysql> insert into Student values(1, "Abraham", "Zebra", "Russia", '1998-10-01', 20, 9874521);
Query OK, 1 row affected (0.04 sec)

mysql> insert into Student values(1, "Abba", "Zebra", "Kennada", '1997-10-01', 20, 9874521);
Query OK, 1 row affected (0.05 sec)

mysql> insert into Student values(1, "Aole", "Zebra", "Amrika", '1996-10-01', 25, 9874521);
Query OK, 1 row affected (0.03 sec)

mysql> insert into Student values(1, "Aole", "Lantern", "Afrika", '1996-10-01', 25, 9874521);
Query OK, 1 row affected (0.04 sec)

mysql> insert into Student values(1, "Aole", "Lion", "Egypt", '1996-10-01', 25, 9874521);
Query OK, 1 row affected (0.04 sec)

mysql> insert into Student values(9, "Aerial", "Lion", "Egypt", '1996-10-01', 25, 9874521);
Query OK, 1 row affected (0.03 sec)

mysql> insert into Student values(10, "Bush", "Lion", "Egypt", '1996-10-01', 25, 9874521);
Query OK, 1 row affected (0.05 sec)

mysql> select * from Student;
+--------------------+-----------+----------+---------+------------+------+--------------+
| RegistrationNumber | FirstName | LastName | Address | DoB        | Age  | MobileNumber |
+--------------------+-----------+----------+---------+------------+------+--------------+
|                  1 | A         | Z        | ABC     | 2000-08-23 |   19 |      9876521 |
|                  1 | Abraham   | Z        | ABC     | 1998-10-01 |   20 |      9876521 |
|                  1 | Abraham   | Zeal     | ABC     | 1998-10-01 |   20 |      9874521 |
|                  1 | Abraham   | Zebra    | Russia  | 1998-10-01 |   20 |      9874521 |
|                  1 | Abba      | Zebra    | Kennada | 1997-10-01 |   20 |      9874521 |
|                  1 | Aole      | Zebra    | Amrika  | 1996-10-01 |   25 |      9874521 |
|                  1 | Aole      | Lantern  | Afrika  | 1996-10-01 |   25 |      9874521 |
|                  1 | Aole      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |
|                  9 | Aerial    | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |
|                 10 | Bush      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |
+--------------------+-----------+----------+---------+------------+------+--------------+

--Question3
mysql> select RegistrationNumber,FirstName,Address,Age from Student;
+--------------------+-----------+---------+------+
| RegistrationNumber | FirstName | Address | Age  |
+--------------------+-----------+---------+------+
|                  1 | A         | ABC     |   19 |
|                  1 | Abraham   | ABC     |   20 |
|                  1 | Abraham   | ABC     |   20 |
|                  1 | Abraham   | Russia  |   20 |
|                  1 | Abba      | Kennada |   20 |
|                  1 | Aole      | Amrika  |   25 |
|                  1 | Aole      | Afrika  |   25 |
|                  1 | Aole      | Egypt   |   25 |
|                  9 | Aerial    | Egypt   |   25 |
|                 10 | Bush      | Egypt   |   25 |
+--------------------+-----------+---------+------+

--Question 4
mysql> select * from Student where RegistrationNumber>=5;
+--------------------+-----------+----------+---------+------------+------+--------------+
| RegistrationNumber | FirstName | LastName | Address | DoB        | Age  | MobileNumber |
+--------------------+-----------+----------+---------+------------+------+--------------+
|                  9 | Aerial    | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |
|                 10 | Bush      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |
+--------------------+-----------+----------+---------+------------+------+--------------+
--Question 5
mysql> alter table Student add Marks float;
Query OK, 0 rows affected (0.73 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe Student;
+--------------------+-------------+------+-----+---------+-------+
| Field              | Type        | Null | Key | Default | Extra |
+--------------------+-------------+------+-----+---------+-------+
| RegistrationNumber | int(11)     | YES  |     | NULL    |       |
| FirstName          | varchar(10) | YES  |     | NULL    |       |
| LastName           | varchar(7)  | YES  |     | NULL    |       |
| Address            | text        | YES  |     | NULL    |       |
| DoB                | date        | YES  |     | NULL    |       |
| Age                | smallint(6) | YES  |     | NULL    |       |
| MobileNumber       | bigint(20)  | YES  |     | NULL    |       |
| Marks              | float       | YES  |     | NULL    |       |
+--------------------+-------------+------+-----+---------+-------+

--Question-6
mysql> select * from Student order by Age;
+--------------------+-----------+----------+---------+------------+------+--------------+-------+
| RegistrationNumber | FirstName | LastName | Address | DoB        | Age  | MobileNumber | Marks |
+--------------------+-----------+----------+---------+------------+------+--------------+-------+
|                  1 | A         | Z        | ABC     | 2000-08-23 |   19 |      9876521 |  NULL |
|                  1 | Abraham   | Z        | ABC     | 1998-10-01 |   20 |      9876521 |  NULL |
|                  1 | Abraham   | Zeal     | ABC     | 1998-10-01 |   20 |      9874521 |  NULL |
|                  1 | Abraham   | Zebra    | Russia  | 1998-10-01 |   20 |      9874521 |  NULL |
|                  1 | Abba      | Zebra    | Kennada | 1997-10-01 |   20 |      9874521 |  NULL |
|                  1 | Aole      | Zebra    | Amrika  | 1996-10-01 |   25 |      9874521 |  NULL |
|                  1 | Aole      | Lantern  | Afrika  | 1996-10-01 |   25 |      9874521 |  NULL |
|                  1 | Aole      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |  NULL |
|                  9 | Aerial    | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |  NULL |
|                 10 | Bush      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |  NULL |
+--------------------+-----------+----------+---------+------------+------+--------------+-------+
mysql> select * from Student order by Age DESC;
+--------------------+-----------+----------+---------+------------+------+--------------+-------+
| RegistrationNumber | FirstName | LastName | Address | DoB        | Age  | MobileNumber | Marks |
+--------------------+-----------+----------+---------+------------+------+--------------+-------+
|                  1 | Aole      | Zebra    | Amrika  | 1996-10-01 |   25 |      9874521 |  NULL |
|                  1 | Aole      | Lantern  | Afrika  | 1996-10-01 |   25 |      9874521 |  NULL |
|                  1 | Aole      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |  NULL |
|                  9 | Aerial    | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |  NULL |
|                 10 | Bush      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |  NULL |
|                  1 | Abraham   | Z        | ABC     | 1998-10-01 |   20 |      9876521 |  NULL |
|                  1 | Abraham   | Zeal     | ABC     | 1998-10-01 |   20 |      9874521 |  NULL |
|                  1 | Abraham   | Zebra    | Russia  | 1998-10-01 |   20 |      9874521 |  NULL |
|                  1 | Abba      | Zebra    | Kennada | 1997-10-01 |   20 |      9874521 |  NULL |
|                  1 | A         | Z        | ABC     | 2000-08-23 |   19 |      9876521 |  NULL |
+--------------------+-----------+----------+---------+------------+------+--------------+-------+
--Question-7
mysql> select distinct Address from Student;
+---------+
| Address |
+---------+
| ABC     |
| Russia  |
| Kennada |
| Amrika  |
| Afrika  |
| Egypt   |
+---------+
--Question-8
mysql> select count(*) from Student;
+----------+
| count(*) |
+----------+
|       10 |
+----------+
--Question-9
mysql> update Student set Marks= 100;
Query OK, 11 rows affected (0.05 sec)
Rows matched: 11  Changed: 11  Warnings: 0

mysql> select * from Student;
+--------------------+-----------+----------+---------+------------+------+--------------+-------+
| RegistrationNumber | FirstName | LastName | Address | DoB        | Age  | MobileNumber | Marks |
+--------------------+-----------+----------+---------+------------+------+--------------+-------+
|                  1 | A         | Z        | ABC     | 2000-08-23 |   19 |      9876521 |   100 |
|                  1 | Abraham   | Z        | ABC     | 1998-10-01 |   20 |      9876521 |   100 |
|                  1 | Abraham   | Zeal     | ABC     | 1998-10-01 |   20 |      9874521 |   100 |
|                  1 | Abraham   | Zebra    | Russia  | 1998-10-01 |   20 |      9874521 |   100 |
|                  1 | Abba      | Zebra    | Kennada | 1997-10-01 |   20 |      9874521 |   100 |
|                  1 | Aole      | Zebra    | Amrika  | 1996-10-01 |   25 |      9874521 |   100 |
|                  1 | Aole      | Lantern  | Afrika  | 1996-10-01 |   25 |      9874521 |   100 |
|                  1 | Aole      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |   100 |
|                  9 | Aerial    | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |   100 |
|                 10 | Bush      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |   100 |
|               NULL | NULL      | NULL     | NULL    | NULL       | NULL |         NULL |   100 |
+--------------------+-----------+----------+---------+------------+------+--------------+-------+

mysql> select min(marks) from Student;
+------------+
| min(marks) |
+------------+
|        100 |
+------------+
1 row in set (0.00 sec)

mysql> select max(marks) from Student;
+------------+
| max(marks) |
+------------+
|        100 |
+------------+
1 row in set (0.00 sec)

mysql> select avg(marks) from Student;
+------------+
| avg(marks) |
+------------+
|        100 |
+------------+
1 row in set (0.01 sec)

mysql> select sum(marks) from Student;
+------------+
| sum(marks) |
+------------+
|       1000 |
+------------+
1 row in set (0.00 sec)

--Question10
mysql> select Address,Marks from Student;
+---------+-------+
| Address | Marks |
+---------+-------+
| ABC     |   100 |
| ABC     |   100 |
| ABC     |   100 |
| Russia  |   100 |
| Kennada |   100 |
| Amrika  |   100 |
| Afrika  |   100 |
| Egypt   |   100 |
| Egypt   |   100 |
| Egypt   |   100 |
+---------+-------+
--Question-11
mysql> update Student set Marks=98 where Address="Kennada";
Query OK, 1 row affected (0.03 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from Student;
+--------------------+-----------+----------+---------+------------+------+--------------+-------+
| RegistrationNumber | FirstName | LastName | Address | DoB        | Age  | MobileNumber | Marks |
+--------------------+-----------+----------+---------+------------+------+--------------+-------+
|                  1 | A         | Z        | ABC     | 2000-08-23 |   19 |      9876521 |   100 |
|                  1 | Abraham   | Z        | ABC     | 1998-10-01 |   20 |      9876521 |   100 |
|                  1 | Abraham   | Zeal     | ABC     | 1998-10-01 |   20 |      9874521 |   100 |
|                  1 | Abraham   | Zebra    | Russia  | 1998-10-01 |   20 |      9874521 |   100 |
|                  1 | Abba      | Zebra    | Kennada | 1997-10-01 |   20 |      9874521 |    98 |
|                  1 | Aole      | Zebra    | Amrika  | 1996-10-01 |   25 |      9874521 |   100 |
|                  1 | Aole      | Lantern  | Afrika  | 1996-10-01 |   25 |      9874521 |   100 |
|                  1 | Aole      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |   100 |
|                  9 | Aerial    | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |   100 |
|                 10 | Bush      | Lion     | Egypt   | 1996-10-01 |   25 |      9874521 |   100 |
+--------------------+-----------+----------+---------+------------+------+--------------+-------+

--Question12
mysql> alter table Student modify column Marks int;
Query OK, 10 rows affected (0.95 sec)
Records: 10  Duplicates: 0  Warnings: 0

mysql> describe Student;
-- +--------------------+-------------+------+-----+---------+-------+
-- | Field              | Type        | Null | Key | Default | Extra |
-- +--------------------+-------------+------+-----+---------+-------+
-- | RegistrationNumber | int(11)     | YES  |     | NULL    |       |
-- | FirstName          | varchar(10) | YES  |     | NULL    |       |
-- | LastName           | varchar(7)  | YES  |     | NULL    |       |
-- | Address            | text        | YES  |     | NULL    |       |
-- | DoB                | date        | YES  |     | NULL    |       |
-- | Age                | smallint(6) | YES  |     | NULL    |       |
-- | MobileNumber       | bigint(20)  | YES  |     | NULL    |       |
-- | Marks              | int(11)     | YES  |     | NULL    |       |
-- +--------------------+-------------+------+-----+---------+-------+

--Question13
mysql> update Student set Marks = 94 where FirstName="Jacky";
Query OK, 1 row affected (0.03 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from Student;
-- +--------------------+-----------+----------+----------------+------------+------+--------------+-------+
-- | RegistrationNumber | FirstName | LastName | Address        | DoB        | Age  | MobileNumber | Marks |
-- +--------------------+-----------+----------+----------------+------------+------+--------------+-------+
-- |                  1 | A         | Z        | ABC            | 2000-08-23 |   19 |      9876521 |   100 |
-- |                  1 | Abraham   | Z        | ABC            | 1998-10-01 |   20 |      9876521 |   100 |
-- |                  1 | Abraham   | Zeal     | ABC            | 1998-10-01 |   20 |      9874521 |   100 |
-- |                  1 | Abraham   | Zebra    | Russia         | 1998-10-01 |   20 |      9874521 |   100 |
-- |                  1 | Abba      | Zebra    | Kennada        | 1997-10-01 |   20 |      9874521 |    98 |
-- |                  1 | Aole      | Zebra    | Amrika         | 1996-10-01 |   25 |      9874521 |   100 |
-- |                  1 | Aole      | Lantern  | Afrika         | 1996-10-01 |   25 |      9874521 |   100 |
-- |                  1 | Aole      | Lion     | Egypt          | 1996-10-01 |   25 |      9874521 |   100 |
-- |                  9 | Aerial    | Lion     | Egypt          | 1996-10-01 |   25 |      9874521 |   100 |
-- |                 10 | Bush      | Lion     | Egypt          | 1996-10-01 |   25 |      9874521 |   100 |
-- |                 11 | Jacky     | Dacky    | Czech Republic | 1995-01-09 |   30 |       987261 |    94 |
-- +--------------------+-----------+----------+----------------+------------+------+--------------+-------+

--Question14
mysql> delete from Student where RegistrationNumber=9;
Query OK, 1 row affected (0.04 sec)

mysql> select * from Student;
-- +--------------------+-----------+----------+----------------+------------+------+--------------+-------+
-- | RegistrationNumber | FirstName | LastName | Address        | DoB        | Age  | MobileNumber | Marks |
-- +--------------------+-----------+----------+----------------+------------+------+--------------+-------+
-- |                  1 | A         | Z        | ABC            | 2000-08-23 |   19 |      9876521 |   100 |
-- |                  1 | Abraham   | Z        | ABC            | 1998-10-01 |   20 |      9876521 |   100 |
-- |                  1 | Abraham   | Zeal     | ABC            | 1998-10-01 |   20 |      9874521 |   100 |
-- |                  1 | Abraham   | Zebra    | Russia         | 1998-10-01 |   20 |      9874521 |   100 |
-- |                  1 | Abba      | Zebra    | Kennada        | 1997-10-01 |   20 |      9874521 |    98 |
-- |                  1 | Aole      | Zebra    | Amrika         | 1996-10-01 |   25 |      9874521 |   100 |
-- |                  1 | Aole      | Lantern  | Afrika         | 1996-10-01 |   25 |      9874521 |   100 |
-- |                  1 | Aole      | Lion     | Egypt          | 1996-10-01 |   25 |      9874521 |   100 |
-- |                 10 | Bush      | Lion     | Egypt          | 1996-10-01 |   25 |      9874521 |   100 |
-- |                 11 | Jacky     | Dacky    | Czech Republic | 1995-01-09 |   30 |       987261 |    94 |
-- +--------------------+-----------+----------+----------------+------------+------+--------------+-------+

--Question15
mysql> alter table Student Change DoB DOB date;
Query OK, 0 rows affected (0.50 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe Student;
-- +--------------------+-------------+------+-----+---------+-------+
-- | Field              | Type        | Null | Key | Default | Extra |
-- +--------------------+-------------+------+-----+---------+-------+
-- | RegistrationNumber | int(11)     | YES  |     | NULL    |       |
-- | FirstName          | varchar(10) | YES  |     | NULL    |       |
-- | LastName           | varchar(7)  | YES  |     | NULL    |       |
-- | Address            | text        | YES  |     | NULL    |       |
-- | DOB                | date        | YES  |     | NULL    |       |
-- | Age                | smallint(6) | YES  |     | NULL    |       |
-- | MobileNumber       | bigint(20)  | YES  |     | NULL    |       |
-- | Marks              | int(11)     | YES  |     | NULL    |       |
-- +--------------------+-------------+------+-----+---------+-------+

--Question16
mysql> alter table Student drop column DOB;
Query OK, 0 rows affected (0.66 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe Student;
-- +--------------------+-------------+------+-----+---------+-------+
-- | Field              | Type        | Null | Key | Default | Extra |
-- +--------------------+-------------+------+-----+---------+-------+
-- | RegistrationNumber | int(11)     | YES  |     | NULL    |       |
-- | FirstName          | varchar(10) | YES  |     | NULL    |       |
-- | LastName           | varchar(7)  | YES  |     | NULL    |       |
-- | Address            | text        | YES  |     | NULL    |       |
-- | Age                | smallint(6) | YES  |     | NULL    |       |
-- | MobileNumber       | bigint(20)  | YES  |     | NULL    |       |
-- | Marks              | int(11)     | YES  |     | NULL    |       |
-- +--------------------+-------------+------+-----+---------+-------+

--Question17
mysql> delete from Student;
Query OK, 10 rows affected (0.05 sec)

mysql> select * from Student;
Empty set (0.00 sec)

--Question18
mysql> drop table Student;
Query OK, 0 rows affected (0.17 sec)
