/* Task 1: DML (Data Manipulation Language) & JOIN Commands */

-- 1. Insert a new event called "AI Hackathon" conducted by team 'T4' in 'Seminar Hall', floor '2', room 205, priced at 900.00.
INSERT INTO event (event_id, event_name, building, floor, room_no, price, team_id) VALUES ('E33', 'AI Hackathon', 'Seminar Hall', '2', 205, 900.00, 'T4');
INSERT INTO event_conduction(event_id, date_of_conduction) VALUES ('E33', '2025-09-02');

-- 2. Update the quantity of 'Mushroom Risotto' in stall 'S1' to 25.
UPDATE stall_items SET total_quantity = 25 WHERE stall_id = 'S1' AND item_name = 'Mushroom Risotto';

-- 3. Delete all registrations where the event ID is 'E1' and SRN starts with 'P100'.
DELETE FROM registration WHERE event_id = 'E1' AND srn LIKE 'P100%';

-- 4. Insert a new purchase: 'P1017' buys 3 'Fish Tacos' from stall 'S6' at '2025-07-10 14:00:00'.
INSERT INTO purchased (SRN, stall_id, item_name, timestamp, quantity) VALUES ('P1017', 'S6', 'Fish Tacos', '2025-07-10 14:00:00', 3);

/* Task 2: DML & JOIN Commands */

-- 5. Retrieve participants's SRN who are registered only for event 'E2' or 'E5', but not both (using SET operations).
(SELECT srn FROM registration WHERE event_id = 'E2')
UNION
(SELECT srn FROM registration WHERE event_id = 'E5')
EXCEPT
(SELECT srn FROM registration WHERE event_id = 'E2' INTERSECT SELECT srn FROM registration WHERE event_id = 'E5');

-- 6. Display all participants and the names of all their visitors(if any) with a count of visitors.
SELECT p.srn, p.name, GROUP_CONCAT(v.name SEPARATOR ', ') AS visitor_names, COUNT(v.name) AS visitor_count
FROM participant AS p
LEFT JOIN visitor AS v ON p.srn = v.srn
GROUP BY p.srn, p.name;

-- 7. List events that have equal number of male and female participants.
SELECT e.event_id, e.event_name
FROM event AS e
JOIN registration AS r ON e.event_id = r.event_id
JOIN participant AS p ON r.srn = p.srn
GROUP BY e.event_id, e.event_name
HAVING SUM(CASE WHEN p.gender = 'Male' THEN 1 ELSE 0 END) = SUM(CASE WHEN p.gender = 'Female' THEN 1 ELSE 0 END);

-- 8. Display each event's name and a binary indicator of whether it occurred after the Golden Jubilee (year > 2047).
SELECT e.event_name, CASE WHEN YEAR(ec.date_of_conduction) > 2047 THEN 1 ELSE 0 END AS after_golden_jubilee
FROM event AS e
JOIN event_conduction AS ec ON e.event_id = ec.event_id;
