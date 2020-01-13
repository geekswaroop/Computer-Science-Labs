mysql> use hospital;
Database changed
mysql> create table patient_info(
    -> name varchar(30),
    -> age int,
    -> sex varchar(10),
    -> contact int);
Query OK, 0 rows affected (0.43 sec)

mysql> create table doctor_info(
    -> name varchar(30),
    -> age int, 
    -> sex varchar(10),
    -> contact int);
Query OK, 0 rows affected (0.32 sec)

mysql> create table employee_list(
    -> employee_type varchar(30),
    -> pay int,
    -> experience int);
Query OK, 0 rows affected (0.31 sec)

mysql> create table department_list(
    -> name varchar(30),
    -> head varchar(30));
Query OK, 0 rows affected (0.74 sec)

mysql> insert into patient_info(name, age, sex, contact) values('Ram', 30, 'M', 12345);
Query OK, 1 row affected (0.45 sec)

mysql> insert into patient_info(name, age, sex, contact) values('Sham', 35, 'M', 12346);
Query OK, 1 row affected (0.04 sec)

mysql> insert into patient_info(name, age, sex, contact) values('Biggie', 20, 'M', 12146);
Query OK, 1 row affected (0.03 sec)

mysql> insert into patient_info(name, age, sex, contact) values('Tupac', 40, 'F', 16146);
Query OK, 1 row affected (0.04 sec)

mysql> insert into patient_info(name, age, sex, contact) values('Tiru', 50, 'F', 99876);
Query OK, 1 row affected (0.05 sec)

mysql> select * from patient_info;
-- +--------+------+------+---------+
-- | name   | age  | sex  | contact |
-- +--------+------+------+---------+
-- | Ram    |   30 | M    |   12345 |
-- | Sham   |   35 | M    |   12346 |
-- | Biggie |   20 | M    |   12146 |
-- | Tupac  |   40 | F    |   16146 |
-- | Tiru   |   50 | F    |   99876 |
-- +--------+------+------+---------+
-- 5 rows in set (0.00 sec)

mysql> insert into doctor_info(name, age, sex, contact) values('John', 50, 'M', 99876);
Query OK, 1 row affected (0.04 sec)

mysql> insert into doctor_info(name, age, sex, contact) values('Abraham', 40, 'M', 998
Query OK, 1 row affected (0.04 sec)

mysql> insert into doctor_info(name, age, sex, contact) values('Seung', 45, 'M', 99888);
Query OK, 1 row affected (0.03 sec)

mysql> insert into doctor_info(name, age, sex, contact) values('Jeff', 70, 'M', 9988865);
Query OK, 1 row affected (0.04 sec)

mysql> insert into doctor_info(name, age, sex, contact) values('Wei', 30, 'F', 998886512);
Query OK, 1 row affected (0.04 sec)

mysql> select * from doctor_info;
+---------+------+------+-----------+
| name    | age  | sex  | contact   |
+---------+------+------+-----------+
| John    |   50 | M    |     99876 |
| Abraham |   40 | M    |     99876 |
| Seung   |   45 | M    |     99888 |
| Jeff    |   70 | M    |   9988865 |
| Wei     |   30 | F    | 998886512 |
+---------+------+------+-----------+

mysql> insert into employee_list(employee_type, pay, experience) values('Doctor', 1234, 4);
Query OK, 1 row affected (0.45 sec)

mysql> insert into employee_list(employee_type, pay, experience) values('Surgeon', 999234, 10);
Query OK, 1 row affected (0.04 sec)

mysql> insert into employee_list(employee_type, pay, experience) values('Janitor', 234, 1);
Query OK, 1 row affected (0.05 sec)

mysql> insert into employee_list(employee_type, pay, experience) values('Research Intern', 1134, 0);
Query OK, 1 row affected (0.04 sec)

mysql> select * from employee_list;
+-----------------+--------+------------+
| employee_type   | pay    | experience |
+-----------------+--------+------------+
| Doctor          |   1234 |          4 |
| Surgeon         | 999234 |         10 |
| Janitor         |    234 |          1 |
| Research Intern |   1134 |          0 |
+-----------------+--------+------------+
4 rows in set (0.00 sec)
mysql> insert into department_list(name, head) values('a', 'b');
Query OK, 1 row affected (0.45 sec)

mysql> insert into department_list(name, head) values('Anaesthesiology', 'Brown');
Query OK, 1 row affected (0.04 sec)

mysql> insert into department_list(name, head) values('Cardiology', 'White');
Query OK, 1 row affected (0.06 sec)

mysql> insert into department_list(name, head) values('Neurology', 'Violet');
Query OK, 1 row affected (0.05 sec)

mysql> insert into department_list(name, head) values('Gen Surgery', 'Victro');
Query OK, 1 row affected (0.46 sec)

mysql> insert into department_list(name, head) values('Neuro Surgery', 'Victor');
Query OK, 1 row affected (0.05 sec)

mysql> select * from department_list;
+-----------------+--------+
| name            | head   |
+-----------------+--------+
| a               | b      |
| Anaesthesiology | Brown  |
| Cardiology      | White  |
| Neurology       | Violet |
| Gen Surgery     | Victro |
| Neuro Surgery   | Victor |
+-----------------+--------+
6 rows in set (0.00 sec)
