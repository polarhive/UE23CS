#include "../include/common.h"
#include "../include/user.h"

int hash_product(int product_id) {
    return product_id % MAX_PRODS;
}

void add_product(char* product_name, int product_id, char* category) {
    product_t* newProduct = (product_t*)malloc(sizeof(product_t));
    newProduct->product_id = product_id;
    strcpy(newProduct->product_name, product_name);
    strcpy(newProduct->category, category);
    int index = hash_product(product_id);
    product_map[index] = newProduct;
}

void add_purchase_history(int userId, int product_id) {
    int index = hash_user(userId);
    user_t* user = user_map[index];
    if (user && user->purchase_count < MAX_HISTORY) {
        user->purchase_hist[user->purchase_count++] = product_id;
    }
}

product_t* retreive_product_history(int product_id) {
    int index = hash_product(product_id);
    product_t* product = product_map[index];
    if (product == NULL) {
        printf("No Product Found\n");
    }
    return product;
}

void updateProduct(char *newName, int productId, char *category)
{
    int index = hash_product(productId);
    product_t *product = product_map[index];
    strcpy(product->product_name, newName);
    strcpy(product->category, category);
}