#include "common.h"
#include "user.h"
#include "product.h"
#include "recommend.h"

user_t *user_map[MAX_USRS] = {NULL};
product_t *product_map[MAX_PRODS] = {NULL};

int main()
{
    // add users)
    add_user("Jeel", 1);
    add_user("Mithun", 2);
    add_user("Navneet", 3);
    add_user("Nathan", 4);

    // add products
    add_product("Laptop", 101, "Electronics");
    add_product("Headphones", 102, "Electronics");
    add_product("Keyboard", 103, "Electronics");
    add_product("Fiction Book", 201, "Books");
    add_product("Science Book", 202, "Books");

    // add browsing and purchase history
    add_browsing_history(1, 101);
    add_browsing_history(2, 103);
    add_browsing_history(4, 102);
    add_purchase_history(3, 102);
    add_purchase_history(2, 102);
    add_purchase_history(1, 102);
    add_purchase_history(4, 102);

    // feed in the browsing history data
    add_browsing_history(1, 201);
    add_browsing_history(3, 201);
    add_purchase_history(2, 202);

    // recommend products to users
    recommend_products(1);
    recommend_products(2);
    recommend_products(3);
    recommend_products(4);

    return 0;
}