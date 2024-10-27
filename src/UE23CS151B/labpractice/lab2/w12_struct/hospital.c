// You've been tasked with developing a hospital management system in C for
// "Greenwood Hospital." The system needs to efficiently handle patient
// records, including their personal details, diagnosis, and billing information.
// Your program should implement a structure to store patient details such
// as name, age, gender, diagnosis, phone number, and address. Additionally, you need to write functions to calculate the total bill for each patient based
// on the consultation fee, diagnosis cost, and medication expenses.
// Structure:
// Create a structure named Patient with the following members:
// 1. name: Representing the patient's name.
// 2. age: Representing the patient's age.
// 3. gender: Representing the patient's gender (F - Female, M - Male, O - Others).
// 4. diagnosis_cost: Representing the patient's diagnosis cost or medical condition.
// 5. medication_cost: Representing the patient's medication cost.
// 6. contact: A nested structure to store contact information, consisting of:
// • phone: Representing the patient's phone number.
// • email_ID: Representing the patient's email ID.
// Functions to Implement:
// 1. Function to Add Patient Details: add_patient_details()
// • It will read all the details of the patient.
// 2. Function to Display Patient Details: display_patient_details()
// • This function should display all the details of the patient.
// 3. Function to Calculate Bill: calculate_bill()
// • This function should calculate the total bill for a patient based on the
// consultation fee, diagnosis cost, and medication cost.
// • The consultation fee is fixed at Rs. 500. Add the consultation fee, diagnosis
// cost, and medication cost to get the total amount.
// • Then, Add 18% tax to the total amount to generate the total bill.
// • Display an appropriate message along with the total bill amount.

#include <stdio.h>
struct Patient
{
    char name[50];
    int age;
    char gender;
    float diagnosis_cost;
    float medication_cost;
    struct contact
    {
        long long int phone;
        char email_ID[100];
    } c;
};
struct Patient add_patient_details()
{
    struct Patient p;
    scanf("%[^\n]s", p.name);
    scanf("%d", &p.age);
    scanf(" %c", &p.gender);
    scanf("%f", &p.diagnosis_cost);
    scanf("%f", &p.medication_cost);
    scanf("%lld", &p.c.phone);
    scanf("%s", p.c.email_ID);
    return p;
}

void display_patient_details(struct Patient p)
{
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Gender: %c\n", p.gender);
    printf("Diagnosis Cost: %.2f\n", p.diagnosis_cost);
    printf("Medication Cost: %.2f\n", p.medication_cost);
    printf("Phone: %lld\n", p.c.phone);
    printf("Email ID: %s\n", p.c.email_ID);
}
void calculate_bill(struct Patient p)
{
    // Fixed consultation fee
    int consultation_fee = 500;
    float amount, total_bill;
    // Calculate total bill including tax
    amount = consultation_fee + p.diagnosis_cost + p.medication_cost;
    total_bill = amount + amount * 18 / 100; // Adding 18% tax

    printf("Total Bill: %.2f\n", total_bill);
}
int main()
{
    struct Patient p_var;
    p_var = add_patient_details();
    display_patient_details(p_var);
    calculate_bill(p_var);
    return 0;
}