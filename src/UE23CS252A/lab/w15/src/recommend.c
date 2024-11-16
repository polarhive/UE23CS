#include "../include/common.h"
#include "../include/user.h"
#include "../include/product.h"

void recommend_products(int userId) {
    user_t* user = retreive_user_data(userId);
    if (user == NULL) return;

    printf("Recommendations for %s:\n", user->username);
    char* favoredCategory = NULL;

    if (user->browsing_count > 0) {
        int last_browsed_product_id = user->browsing_hist[user->browsing_count - 1];
        product_t* last_browsed_product = retreive_product_history(last_browsed_product_id);
        if (last_browsed_product) {
            favoredCategory = last_browsed_product->category;
        }
    }

    for (int i = 0; i < MAX_PRODS; i++) {
        product_t* product = product_map[i];
        if (product && favoredCategory && strcmp(product->category, favoredCategory) == 0) {
            printf(" - %s\n", product->product_name);
        }
    }
}
