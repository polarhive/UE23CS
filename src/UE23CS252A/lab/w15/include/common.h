#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USRS 128
#define MAX_PRODS 128
#define MAX_HISTORY 16
#define MAX_NAME 32

// struct to store user data
typedef struct {
    int user_id;
    char username[MAX_NAME];
    int browsing_hist[MAX_HISTORY];
    int purchase_hist[MAX_HISTORY];
    int browsing_count;
    int purchase_count;
} user_t;

// struct to store product data
typedef struct {
    int product_id;
    char product_name[MAX_NAME];
    char category[MAX_NAME];
} product_t;

// hash function for users
extern user_t* user_map[MAX_USRS];
extern product_t* product_map[MAX_PRODS];
