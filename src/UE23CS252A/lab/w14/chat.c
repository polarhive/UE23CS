#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100  // Maximum number of users

// Structure for a message in a doubly linked list
typedef struct Message {
    char content[256];
    char sender[50];
    struct Message* next;
    struct Message* prev;
} Message;

// Structure for the chat history (Doubly linked list of messages)
typedef struct Chat {
    Message* head;
    Message* tail;
} Chat;

// Structure for a user
typedef struct User {
    char userId[50];
    char username[50];
    Chat chatHistory;
} User;

// HashMap for storing users
User* userDirectory[MAX_USERS];

// Hash function to calculate the index for user storage
int hashFunction(char* userId) {
    int i, hash = 0;
    for (i=0; userId[i] != '\0'; i++){
        hash = (hash+userId[i]) % MAX_USERS;
    }
    return hash;
}

// Function to create a new user
void createUser(char* userId, char* username) {
    int index = hashFunction(userId);
    User* newUser = malloc(sizeof(User));
    strcpy(newUser -> userId, userId);
    strcpy(newUser -> username, username);

    newUser -> chatHistory.head = newUser -> chatHistory.tail = NULL;
    userDirectory[index] = newUser;
}

// Function to find a user by userId
User* findUser(char* userId) {
    int index = hashFunction(userId);
    return userDirectory[index];
}

// Function to create a new message
Message* createMessage(char* content, char* senderId) {
    Message* newMessage = (Message*)malloc(sizeof(Message));
    strcpy(newMessage -> content, content);
    strcpy(newMessage -> sender, senderId);
    newMessage->next = NULL;
    newMessage->prev = NULL;

    return newMessage;
}

// Function to send a message (add to chat history)
void sendMessage(User* user, char* content, char* senderId) {
    Message* newMessage = createMessage(content, senderId);
    if(user->chatHistory.tail == NULL){
        user->chatHistory.head = user->chatHistory.tail = newMessage;
    } else {
        user->chatHistory.tail->next = newMessage;
        newMessage->prev = user->chatHistory.tail;
        user->chatHistory.tail = newMessage;
    }
}

// Function to list all messages in a chat
void listMessages(User* user) {
    Message* current = user->chatHistory.head;

    if(current == NULL){
        printf("No messages in chat\n");
        return;
    }
    printf("Chat history: \n");

    while(current!=NULL){
        printf("%s: %s \n", current->sender, current->content);
        current = current->next;
    }
}

int main() {
    int i;

    for (i=0; i<MAX_USERS; i++){
        userDirectory[i] = NULL;
    }

    int choice, numUsers, numMessages;
    char userId[50], username[50], senderId[50], messageContent[256];
 
    printf("Enter number of users to create: ");
    scanf("%d", &numUsers);

    for (i=0; i<numUsers; i++){
        printf("\nEnter User ID: ");
        scanf("%s", userId);
        printf("Enter Username: "); 
        scanf("%s", username);

        createUser(userId, username);
    }
 
    printf("\nEnter number of messages to send: ");
    scanf("%d", &numMessages);

    for (i=0; i<numMessages; i++){
        printf("\nEnter Sender ID: ");
        scanf("%s", senderId);
        printf("Enter Message Content: ");
        getchar();
        fgets(messageContent, sizeof(messageContent), stdin);
        messageContent[strcspn(messageContent, "\n")] = 0;

        User* sender = findUser(senderId);
        if (sender == NULL){
            printf("User not found. \n");
            continue;
        }

        sendMessage(sender, messageContent, senderId);

    }

    printf("\nEnter User ID to display chat history: ");
    scanf("%s", userId);

    User* user = findUser(userId);
    if(user!=NULL){
        listMessages(user);
    }
    else{
        printf("User not found.\n");
    }

    return 0;
}
