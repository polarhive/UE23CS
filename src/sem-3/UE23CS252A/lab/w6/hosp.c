#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { head, data } TYPEFIELD;

struct entrynode {
    int row;
    int col;
    int val;
    char time[10];
};

typedef struct multilist {
    struct multilist* down;
    struct multilist* right;
    TYPEFIELD tag;
    union {
        struct multilist* next;
        struct entrynode* entry;
    };
} MULTILIST;

MULTILIST* init(TYPEFIELD tag) {
    MULTILIST* p = (MULTILIST*)malloc(sizeof(MULTILIST));
    p->down = NULL;
    p->right = NULL;
    p->tag = tag;
    if (tag == data) {
        p->entry = (struct entrynode*)malloc(sizeof(struct entrynode));
        p->entry->row = 0;
        p->entry->col = 0;
        p->entry->val = 0;
        strcpy(p->entry->time, "");
    } else if (tag == head) {
        p->next = NULL;
    }
    return p;
}

int addPatient(MULTILIST* p) {
    MULTILIST* nn = init(head);
    MULTILIST* temp = p->down;
    if (p->down == NULL) {
        p->down = nn;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }
    (p->entry->col)++;
    return (p->entry->col);
}

int addDoctor(MULTILIST* p) {
    MULTILIST* nn = init(head);
    MULTILIST* temp = p->right;
    if (p->right == NULL) {
        p->right = nn;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }
    (p->entry->row)++;
    return (p->entry->row);
}

int addAppointment(MULTILIST* p, int docID, int patID, char* time) {
    if (docID > p->entry->row || patID > p->entry->col) {
        printf("\nInvalid Input");
        return 0;
    }

    MULTILIST* t1 = p->right;
    MULTILIST* t2 = p->down;
    MULTILIST* nn = init(data);
    nn->entry->row = patID;
    nn->entry->col = docID;
    nn->entry->val = 1;
    strcpy(nn->entry->time, time);

    for (int i = 1; i < docID; i++) {
        t1 = t1->next;
    }
    for (int i = 1; i < patID; i++) {
        t2 = t2->next;
    }

    while (t1->down != NULL) {
        t1 = t1->down;
    }
    t1->down = nn;

    while (t2->right != NULL) {
        t2 = t2->right;
    }
    t2->right = nn;

    printf("\nAppointment added for doctor %d and patient %d at %s", docID, patID, time);
    return 1;
}

void deleteAppointment(MULTILIST* p, int docID, int patID) {
    if (docID > p->entry->row || patID > p->entry->col) {
        printf("\nInvalid Appointment");
        return;
    }

    MULTILIST* t1 = p->right;
    MULTILIST* prev1 = NULL;
    MULTILIST* t2 = p->down;
    MULTILIST* prev2 = NULL;

    for (int i = 1; i < docID; i++) {
        prev1 = t1;
        t1 = t1->next;
    }
    for (int i = 1; i < patID; i++) {
        prev2 = t2;
        t2 = t2->next;
    }

    MULTILIST* ap1 = t1->down;
    MULTILIST* ap2 = t2->right;
    MULTILIST* apPrev1 = NULL;
    MULTILIST* apPrev2 = NULL;

    while (ap1 != NULL && (ap1->entry->row != patID || ap1->entry->col != docID)) {
        apPrev1 = ap1;
        ap1 = ap1->down;
    }
    while (ap2 != NULL && (ap2->entry->row != patID || ap2->entry->col != docID)) {
        apPrev2 = ap2;
        ap2 = ap2->right;
    }

    if (ap1 == ap2 && ap1 != NULL) {
        if (apPrev1 != NULL) {
            apPrev1->down = ap1->down;
        } else {
            t1->down = ap1->down;
        }

        if (apPrev2 != NULL) {
            apPrev2->right = ap2->right;
        } else {
            t2->right = ap2->right;
        }

        free(ap1->entry);
        free(ap1);
        printf("\nAppointment for doctor %d and patient %d deleted", docID, patID);
    } else {
        printf("\nAppointment not found");
    }
}

// SRN: PES2UG23CS368
void listAppDoc(MULTILIST* p, int docID) {
    if (docID > p->entry->row) {
        printf("\nInvalid Doctor ID");
        return;
    }

    MULTILIST* t1 = p->right;
    for (int i = 1; i < docID; i++) {
        t1 = t1->next;
    }

    printf("\nAppointments for Doctor ID %d:\n", docID);
    MULTILIST* temp = t1->down;
    while (temp != NULL) {
        printf("Patient ID: %d at %s\n", temp->entry->row, temp->entry->time);
        temp = temp->down;
    }
}

void listAppPat(MULTILIST* p, int patID) {
    if (patID > p->entry->col) {
        printf("\nInvalid Patient ID");
        return;
    }

    MULTILIST* t2 = p->down;
    for (int i = 1; i < patID; i++) {
        t2 = t2->next;
    }

    printf("\nAppointments for Patient ID %d:\n", patID);
    MULTILIST* temp = t2->right;
    while (temp != NULL) {
        printf("Doctor ID: %d at %s\n", temp->entry->col, temp->entry->time);
        temp = temp->right;
    }
}

int main() {
    int ch, docID, patID, cont;
    char time[10];
    MULTILIST* p = init(data);

    printf("\nHOSPITAL MANAGEMENT SYSTEM\n");

    do {
        printf("\nEnter your choice:");
        printf("\n1. Add doctor");
        printf("\n2. Add patient");
        printf("\n3. Add Appointment");
        printf("\n4. Delete Appointment");
        printf("\n5. List Appointments for a Doctor");
        printf("\n6. List Appointments for a Patient");
        printf("\n7. Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                docID = addDoctor(p);
                printf("\nDoctor inserted with doctor ID: %d", docID);
                break;
            case 2:
                patID = addPatient(p);
                printf("\nPatient inserted with patient ID: %d", patID);
                break;
            case 3:
                printf("\nEnter the doctor ID: ");
                scanf("%d", &docID);
                printf("\nEnter the patient ID: ");
                scanf("%d", &patID);
                printf("\nEnter the appointment time (HH:MM): ");
                scanf("%s", time);
                addAppointment(p, docID, patID, time);
                break;
            case 4:
                printf("\nEnter the doctor ID: ");
                scanf("%d", &docID);
                printf("\nEnter the patient ID: ");
                scanf("%d", &patID);
                deleteAppointment(p, docID, patID);
                break;
            case 5:
                printf("\nEnter the doctor ID: ");
                scanf("%d", &docID);
                listAppDoc(p, docID);
                break;
            case 6:
                printf("\nEnter the patient ID: ");
                scanf("%d", &patID);
                listAppPat(p, patID);
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice");
        }

        printf("\nDo you want to continue? Press 1 for Yes, 0 for No: ");
        scanf("%d", &cont);
    } while (cont);

    return 0;
}
