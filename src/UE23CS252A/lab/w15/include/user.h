#pragma once

#include "common.h"

int hash_user (int user_id);
int add_user(char* username, int user_id);
user_t* retreive_user_data(int user_id);
void add_browsing_history(int user_id, int product_id);
