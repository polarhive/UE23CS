#  OOAD: Lab 2

> Submission Date: 2026-01-16
> Name: **Nathan Matthew Paul**
> SRN: **PES2UG23CS368**
> Section: 6F

---

# **1: Hotel Reservation System**

![[Screenshot 2026-01-16 at 10.11.33.png]]

## **Use Case 1: Room Reservation**

| **Field**                      | **Description**                                                                                                                                                                                                |
| ------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Title / Reference Name**     | Room Reservation                                                                                                                                                                                               |
| **Author / Date**              | Nathan / 16-01-2026                                                                                                                                                                                            |
| **Modification / Date**        | None / 16-01-2026                                                                                                                                                                                              |
| **Purpose**                    | To allow a customer to book an available hotel room                                                                                                                                                            |
| **Overview**                   | Describes how a customer searches for rooms, checks availability, and completes a reservation                                                                                                                  |
| **Actors**                     | Customer                                                                                                                                                                                                       |
| **Pre-Conditions**             | Customer is registered and logged in. Room data is available in the system                                                                                                                                     |
| **Post-Conditions**            | Room reservation is confirmed and stored in the system                                                                                                                                                         |
| **Normal Flow of Events**      | 1. Customer searches rooms based on preferences<br>2. System checks room availability<br>3. Customer selects a room<br>4. Customer confirms booking<br>5. System records reservation and displays confirmation |
| **Alternative Flow of Events** | 3a. Selected room not available → system displays alternative rooms                                                                                                                                            |
| **Exceptional Flow of Events** | 4a. Payment failure → reservation is not confirmed                                                                                                                                                             |
| **Implementation Issues**      | Real-time availability check, prevention of overbooking                                                                                                                                                        |

## **Use Case 2: Cancel Reservation**

| **Field**                      | **Description**                                                                                                                             |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------- |
| **Title / Reference Name**     | Cancel Reservation                                                                                                                          |
| **Author / Date**              | Nathan / 16-01-2026                                                                                                                         |
| **Modification / Date**        | None / 16-01-2026                                                                                                                           |
| **Purpose**                    | To allow a customer to cancel an existing reservation                                                                                       |
| **Overview**                   | Describes how a customer cancels a booking and how cancellation charges are applied                                                         |
| **Actors**                     | Customer                                                                                                                                    |
| **Pre-Conditions**             | Customer is logged in. Reservation exists                                                                                                   |
| **Post-Conditions**            | Reservation is cancelled and system is updated                                                                                              |
| **Normal Flow of Events**      | 1. Customer selects reservation<br>2. Customer requests cancellation<br>3. System checks cancellation policy<br>4. Reservation is cancelled |
| **Alternative Flow of Events** | 3a. Cancellation within free period → no charges applied                                                                                    |
| **Exceptional Flow of Events** | 3b. Cancellation after deadline → cancellation charges applied                                                                              |
| **Implementation Issues**      | Cancellation deadline validation, refund handling                                                                                           |

---

---

# **2: Online Hospital Appointment & Care Management System**

![[Pasted image 20260116113248.png]]

## **Use Case 1: Book Appointment**

| **Field**                      | **Description**                                                                                                                  |
| ------------------------------ | -------------------------------------------------------------------------------------------------------------------------------- |
| **Title / Reference Name**     | Book Appointment                                                                                                                 |
| **Author / Date**              | Nathan / 16-01-2026                                                                                                              |
| **Modification / Date**        | None / 16-01-2026                                                                                                                |
| **Purpose**                    | To allow a patient to book a doctor appointment online                                                                           |
| **Overview**                   | Describes how a patient selects a doctor, chooses a time slot, and confirms an appointment                                       |
| **Actors**                     | Patient                                                                                                                          |
| **Pre-Conditions**             | Patient is registered and logged in                                                                                              |
| **Post-Conditions**            | Appointment is scheduled and confirmation is sent                                                                                |
| **Normal Flow of Events**      | 1. Patient searches for doctor<br>2. System shows available slots<br>3. Patient selects time slot<br>4. Appointment is confirmed |
| **Alternative Flow of Events** | 3a. Selected slot unavailable → patient selects another slot                                                                     |
| **Exceptional Flow of Events** | 4a. System error → appointment not booked                                                                                        |
| **Implementation Issues**      | Slot allocation, real-time availability                                                                                          |

## **Use Case 2: Update Diagnosis & Prescription**

| **Field**                      | **Description**                                                                                               |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------- |
| **Title / Reference Name**     | Update Diagnosis and Prescription                                                                             |
| **Author / Date**              | Nathan / 16-01-2026                                                                                           |
| **Modification / Date**        | None / 16-01-2026                                                                                             |
| **Purpose**                    | To allow doctors to update diagnosis and prescribe medication                                                 |
| **Overview**                   | Describes how doctors access patient records and update medical details                                       |
| **Actors**                     | Doctor                                                                                                        |
| **Pre-Conditions**             | Appointment is completed. Doctor is logged in                                                                 |
| **Post-Conditions**            | Patient medical record is updated                                                                             |
| **Normal Flow of Events**      | 1. Doctor accesses appointment<br>2. Views patient history<br>3. Updates diagnosis<br>4. Uploads prescription |
| **Alternative Flow of Events** | 4a. Prescription updated later                                                                                |
| **Exceptional Flow of Events** | 3a. Record access failure                                                                                     |
| **Implementation Issues**      | Data security, record consistency                                                                             |
