# SQL Lab 6: Triggers, Functions, Procedures

> Name: Nathan Matthew Paul
> SRN: PES2UG23CS368
> Section: 5F

# SQL File

```sql
-- Drop and recreate database
DROP DATABASE IF EXISTS CS368_FestDB;;
CREATE DATABASE CS368_FestDB;;
USE CS368_FestDB;;

-- Tables
CREATE TABLE Event (
    Event_ID INT PRIMARY KEY,
    Name VARCHAR(100),
    Price DECIMAL(10,2)
);

CREATE TABLE Item (
    Name VARCHAR(100) PRIMARY KEY,
    Type VARCHAR(50)
);

CREATE TABLE Stall_items (
    Stall_ID INT,
    Item_name VARCHAR(100),
    Total_quantity INT,
    Price_per_unit DECIMAL(10,2),
    PRIMARY KEY (Stall_ID, Item_name),
    FOREIGN KEY (Item_name) REFERENCES Item(Name)
);

CREATE TABLE Registration (
    RegistrationID INT PRIMARY KEY AUTO_INCREMENT,
    Event_ID INT,
    SRN CHAR(13),
    FOREIGN KEY (Event_ID) REFERENCES Event(Event_ID)
);

CREATE TABLE Purchased (
    PurchaseID INT PRIMARY KEY AUTO_INCREMENT,
    SRN CHAR(13),
    Stall_ID INT,
    Item_name VARCHAR(100),
    Timestamp DATETIME,
    Quantity INT,
    FOREIGN KEY (Item_name) REFERENCES Item(Name),
    FOREIGN KEY (Stall_ID, Item_name) REFERENCES Stall_items(Stall_ID, Item_name)
);

-- Drop any old objects if present
DROP TRIGGER IF EXISTS dec_quant;
DROP TRIGGER IF EXISTS i_lim;
DROP PROCEDURE IF EXISTS GetStallSales;
DROP PROCEDURE IF EXISTS RegisterParticipant;
DROP FUNCTION IF EXISTS GetEventCost;
DROP FUNCTION IF EXISTS GetParticipantPurchaseTotal;

-- Triggers and routines
DELIMITER $$

-- ------------------------------
-- TASK 1: TRIGGERS
-- ------------------------------

-- Trigger 1: Automatically decreases the total_quantity of an item in the stall_items table whenever a new row is inserted into the purchased table.
CREATE TRIGGER dec_quant AFTER INSERT ON Purchased
FOR EACH ROW BEGIN
    UPDATE Stall_items
    SET Total_quantity = Total_quantity - NEW.Quantity
    WHERE Stall_ID = NEW.Stall_ID AND Item_name = NEW.Item_name;
END$$

-- Trigger 2: Prevents a participant from purchasing more than 5 units of any single item in a single transaction.
CREATE TRIGGER i_lim
BEFORE INSERT ON Purchased
FOR EACH ROW
BEGIN
    IF NEW.Quantity > 5 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Quantity cannot be greater than 5 units per transaction.';
    END IF;
END$$

-- ------------------------------
-- TASK 2: PROCEDURES
-- ------------------------------

-- Procedure 1: Takes a stall_id as input and prints the total revenue generated from that stall.
CREATE PROCEDURE GetStallSales(IN in_stall_id INT) BEGIN
    DECLARE tot DECIMAL(15,2) DEFAULT 0.00;

    SELECT SUM(si.price_per_unit * p.quantity) INTO tot
    FROM Purchased p
    JOIN Stall_items si ON p.Stall_ID = si.Stall_ID AND p.Item_name = si.Item_name
    WHERE p.Stall_ID = in_stall_id;

    IF tot IS NULL THEN
        SET tot = 0.00;
    END IF;

    SELECT CONCAT('Total revenue for stall ', in_stall_id, ' = ') AS Info, tot AS Total;
END$$

-- Procedure 2: Registers a participant (SRN) for an event (event_id) by inserting a new row into the registration table.
CREATE PROCEDURE RegisterParticipant(
    IN in_event_id INT,
    IN in_srn CHAR(13),
    IN in_reg_id INT
) BEGIN
    IF in_reg_id IS NULL THEN
        INSERT INTO Registration(Event_ID, SRN) VALUES (in_event_id, in_srn);
    ELSE
        INSERT INTO Registration(RegistrationID, Event_ID, SRN) VALUES (in_reg_id, in_event_id, in_srn);
    END IF;
END$$

-- ------------------------------
-- TASK 3: FUNCTIONS
-- ------------------------------

-- Function 1: Accepts an event_id and returns the total price a participant would pay to register for that event.
CREATE FUNCTION GetEventCost(in_event_id INT) RETURNS DECIMAL(10,2)
DETERMINISTIC BEGIN
    DECLARE e_price DECIMAL(10,2) DEFAULT 0.00;

    SELECT Price INTO e_price FROM Event WHERE Event_ID = in_event_id LIMIT 1;

    IF e_price IS NULL THEN
        SET e_price = 0.00;
    END IF;

    RETURN e_price;
END$$

-- Function 2: Returns the total amount a participant has spent across all stalls based on their SRN.
CREATE FUNCTION GetParticipantPurchaseTotal(in_srn CHAR(13)) RETURNS DECIMAL(15,2)
DETERMINISTIC BEGIN
    DECLARE spent DECIMAL(15,2) DEFAULT 0.00;
    SELECT SUM(si.Price_per_unit * p.Quantity) INTO spent FROM Purchased p
    JOIN Stall_items si ON p.Stall_ID = si.Stall_ID AND p.item_name = si.item_name
    WHERE p.srn = in_srn;

    IF spent IS NULL THEN
        SET spent = 0.00;
    END IF;
    RETURN spent;
END$$

DELIMITER ;

-- Test Inserts
INSERT INTO Purchased(SRN, Stall_ID, Item_name, Timestamp, Quantity)
VALUES ('CS368_FestDB;', 301, 'Pulao', '2025-10-11 09:32:00', 2);

-- Tests and Checks
SELECT * FROM Stall_items WHERE Stall_ID = 301 AND Item_name = 'Pulao';
SELECT * FROM Purchased WHERE SRN='CS368_FestDB;';

CALL GetStallSales(301);

CALL RegisterParticipant(205, 'CS368_FestDB;', 1991);
SELECT * FROM Registration WHERE RegistrationID = 1991;

SELECT * FROM Event;
SELECT GetEventCost(201) AS price201;
SELECT GetParticipantPurchaseTotal('CS368_FestDB;') AS Spent_by_CS368_FestDB;

SELECT p.SRN, p.Item_name, p.Quantity, si.Price_per_unit, (si.Price_per_unit * p.Quantity) AS Amount
FROM Purchased p
JOIN Stall_items si ON p.Stall_ID = si.Stall_ID AND p.Item_name = si.Item_name
ORDER BY p.SRN;

SELECT SRN, GetParticipantPurchaseTotal(SRN) AS total_spent
FROM ( SELECT DISTINCT SRN FROM Purchased) t;
```

![[Screenshot 2025-09-18 at 14.37.33.png]]

![[Screenshot 2025-09-18 at 14.37.52.png]]

![[Screenshot 2025-09-18 at 15.00.36.png]]

![[Screenshot 2025-09-18 at 15.00.49.png]]

![[Screenshot 2025-09-18 at 15.01.08.png]]

![[Screenshot 2025-09-18 at 15.01.18.png]]

![[Screenshot 2025-09-18 at 15.01.48.png]]

![[Screenshot 2025-09-18 at 15.01.56.png]]

![[Screenshot 2025-09-18 at 15.02.02.png]]

![[Screenshot 2025-09-18 at 15.03.27.png]]

![[Screenshot 2025-09-18 at 15.03.41.png]]