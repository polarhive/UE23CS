#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int flag;
};
typedef struct {
    int size;
    struct node *hashTable;
} HASH;

int count = 0; // Initialize count

HASH *createHash(int size) {
    HASH *hash = (HASH *)malloc(sizeof(HASH));
    hash->size = size;
    hash->hashTable=(struct node*)malloc(size*sizeof(struct node));
    return hash;
}

void destroyHash(HASH *hash) {
    free(hash->hashTable);
    free(hash);
}

void rehash(int key, HASH **h); // Declare the rehash function with HASH**

void insert_(int key, HASH *h) {
    int hash;
    int i = 0;
    count++;
    printf("\ncount=%d",count);
    if (count > (float)(0.75 * h->size)) {
        printf("\n***");
        rehash(key, &h);
    } else {
        hash = ((key % h->size) + i) % h->size;
        while (h->hashTable[hash].flag != 0 && i < h->size) {
            i++;
            hash=((key % h->size)+i) % h->size;
        }
        if (h->hashTable[hash].flag == 0) {
            h->hashTable[hash].data = key;
            h->hashTable[hash].flag = 1;
            printf("The data %d is inserted at %d\n", key, hash);
        } else
            printf("\nData cannot be inserted");
    }
}

void rehash(int key, HASH **h) {
    int oldSize = (*h)->size;
    struct node *oldTable = (*h)->hashTable;

    (*h)->size = 2 * oldSize;
    (*h)->hashTable = (struct node *)calloc((*h)->size, sizeof(struct node)); // Initialize all nodes to zero
    count = 0; // Reset count since we are inserting elements again

    for (int i = 0; i < oldSize; i++) {
        if (oldTable[i].flag == 1) {
            insert_(oldTable[i].data, *h);
        }
    }
    insert_(key, *h);
    free(oldTable);
}
void display(HASH *h) {
    printf("\nHash Table size:%d\n", h->size);
    for (int i = 0; i < h->size; i++) {
        if (h->hashTable[i].flag == 1) {
            printf("%d %d\n", i, h->hashTable[i].data);
        }
    }
}

int main() {
    int size = 3; // Set the desired size
    HASH *myHash = createHash(size);
    insert_(2, myHash);
    display(myHash);
    insert_(3, myHash);
    display(myHash);
    insert_(4, myHash);
    display(myHash);
    insert_(5, myHash);
    display(myHash);
    insert_(6, myHash);
    display(myHash);

    destroyHash(myHash); // Don't forget to free the allocated memory
    return 0;
}
