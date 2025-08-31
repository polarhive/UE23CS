-- Task 1.0
DROP DATABASE IF EXISTS CS368_FestMgmt;
CREATE DATABASE CS368_FestMgmt;
USE CS368_FestMgmt;

CREATE TABLE Fest (
fest_id INT PRIMARY KEY,
fest_name VARCHAR(100) NOT NULL,
year YEAR NOT NULL,
head_team_id INT
);
DESC Fest;

CREATE TABLE Team(
team_id INT PRIMARY KEY,
team_name VARCHAR(100) NOT NULL,
team_type ENUM('MNG', 'ORG') DEFAULT 'ORG',
fest_id INT,
FOREIGN KEY (fest_id) REFERENCES Fest(fest_id)
);
DESC Team;

CREATE TABLE Member (
member_id INT PRIMARY KEY,
mem_name VARCHAR(100) NOT NULL,
age INT,
dob DATE,
team_id INT,
head_id INT,
FOREIGN KEY (team_id) REFERENCES Team(team_id),
FOREIGN KEY (head_id) REFERENCES Member(member_id)
);
DESC Member;
  
CREATE TABLE Participant(
srn VARCHAR(20) PRIMARY KEY,
name VARCHAR(100) NOT NULL,
gender ENUM('M', 'F', 'O'),
department VARCHAR(10),
semester INT
);
DESC Participant;

CREATE TABLE Event (
event_id INT PRIMARY KEY,
event_name VARCHAR(100) NOT NULL,
building VARCHAR(50) NOT NULL,
floor VARCHAR(20) NOT NULL,
room_no VARCHAR(20) NOT NULL,
price DECIMAL(8,2) CHECK (price <= 1500)
);
DESC Event;
  
CREATE TABLE Event_conduction(
event_id INT,
date_of_conduction DATE NOT NULL,
PRIMARY KEY (event_id, date_of_conduction),
FOREIGN KEY (event_id) REFERENCES Event(event_id)
);
DESC Event_conduction;
 
CREATE TABLE Visitor(
name VARCHAR(100) PRIMARY KEY,
gender ENUM ('M', 'F', 'O'),
age INT,
participant_srn VARCHAR(20),
FOREIGN KEY (participant_srn) REFERENCES Participant(srn)
);
DESC Visitor;
  
CREATE TABLE Registration(
event_id INT PRIMARY KEY,
reg_no INT,
srn VARCHAR(20),
FOREIGN KEY (srn) REFERENCES Participant(srn),
FOREIGN KEY (event_id) REFERENCES Event(event_id)
);
DESC Registration;
  
CREATE TABLE Stall(
stall_id INT PRIMARY KEY,
name VARCHAR(100),
fest_id INT,
FOREIGN KEY (fest_id) REFERENCES Fest(fest_id)
);
DESC Stall;
  
CREATE TABLE Item(
name VARCHAR(100) PRIMARY KEY,
type ENUM('VEG', 'NONVEG')
);
DESC Item;
  
CREATE TABLE Stall_items(
stall_id INT,
item_name VARCHAR(100),
PRIMARY KEY (stall_id, item_name),
FOREIGN KEY (stall_id) REFERENCES Stall(stall_id),
FOREIGN KEY (item_name) REFERENCES Item(name)
);
DESC Stall_items;

CREATE TABLE Purchased(
srn VARCHAR(20),
stall_id INT,
item_name VARCHAR(20),
time_stamp TIMESTAMP,
quantity INT,
PRIMARY KEY(srn, stall_id, item_name, time_stamp),
FOREIGN KEY (srn) REFERENCES Participant(srn),
FOREIGN KEY (stall_id) REFERENCES Stall(stall_id),
FOREIGN KEY (item_name) REFERENCES Item(name)
);  
DESC Purchased;

-- TASK 2.1: Modify gender attribute
DESCRIBE Participant;
ALTER TABLE Participant
MODIFY gender ENUM('M', 'F', 'O') AFTER name;
DESCRIBE Participant;

-- TASK 2.2: Add price with a default value and NOT NULL constraint
DESCRIBE Item;
ALTER TABLE Item
ADD price INT NOT NULL DEFAULT 50;
DESCRIBE Item;  

-- TASK 2.3: Max stock condition
-- The `ADD` statement is used to both add a new column and add a `CHECK` constraint.
DESCRIBE Stall_items;
ALTER TABLE Stall_items
ADD stock INT,
ADD CONSTRAINT check_max_stock CHECK (stock <= 150);
DESCRIBE Stall_items;
  

-- TASK 2.4: Rename table
-- The `RENAME TABLE` statement is the correct syntax for renaming a table.
DESCRIBE Event_conduction;
RENAME TABLE Event_conduction TO Event_schedule;
DESCRIBE Event_schedule;
  

-- TASK 2.5: Move Date_of_conduction to first column
DESCRIBE Event_schedule;
ALTER TABLE Event_schedule
MODIFY date_of_conduction DATE FIRST;
DESCRIBE Event_schedule;
