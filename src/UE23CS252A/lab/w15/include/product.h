#pragma once

#include "common.h"
#include "user.h"

int hash_product(int product_id);
void add_product(char* product_name, int product_id, char* category);
void add_purchase_history(int userId, int product_id);
product_t* retreive_product_history(int product_id);
