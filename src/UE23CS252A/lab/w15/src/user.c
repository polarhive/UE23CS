#include "../include/common.h"

int hash_user (int user_id) {
    return user_id % MAX_USRS;
}

int add_user(char* username, int user_id) {
    user_t* new_user = (user_t *)malloc( sizeof(user_t) );
    if (new_user == NULL) {
      return 0;
    }

    new_user->user_id = user_id;
    strncpy(new_user->username, username, MAX_NAME);

    new_user->browsing_count = 0;
    new_user->purchase_count = 0;

    int index = hash_user(user_id);
    user_map[index] = new_user;

    return 0;
}

user_t* retreive_user_data(int user_id) {
    int index = hash_user(user_id);
    user_t* user = user_map[index];
    if (user == NULL) {
        printf("No User Found\n");
    }
    return user;
}

void add_browsing_history(int user_id, int product_id) {
    int index = hash_user(user_id);
    user_t* user = user_map[index];
    if (user && user->browsing_count < MAX_HISTORY) {
        user->browsing_hist[user->browsing_count++] = product_id;
    }
}

void updateUser(char *newName, int userId){
    int index = hash_user(userId);
    user_t* user = user_map[index];
    strcpy(user -> username, newName);
}