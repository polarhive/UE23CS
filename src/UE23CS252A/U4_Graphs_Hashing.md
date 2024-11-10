# Application of Graphs and Hashing Techniques

> A good hash function should also be fast, simple, and deterministic (i.e. it should always produce the same output for the same input).

In hashing, a **simple mapping** refers to the process of converting a key into an index in a hash table. This process is typically done using a hash function.

## Simple mapping

Here’s a simple example of how you can map a string (key) to an index:

```c
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

// Simple hash function to map string to an index
int simple_hash(char *str) {
    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value += str[i];
    }
    return hash_value % TABLE_SIZE;
}

int main() {
    char *key = "example";
    printf("Hash value for key '%s' is: %d\n", key, simple_hash(key));
    return 0;
}
```

`simple_hash` function calculates the sum of ASCII values of each character in the string and returns the remainder when divided by `TABLE_SIZE`. This remainder gives the index in the hash table.

---
## Hash Function

A **hash function** is an algorithm that maps input data of arbitrary size to fixed-size values. A good hash function minimizes collisions, is fast, simple, and deterministic.

```c
#include <stdio.h>

#define TABLE_SIZE 10

// A basic hash function using modular arithmetic
int hash_function(int key) {
    return key % TABLE_SIZE;
}

int main() {
    int key = 12345;
    printf("Hash value for key %d is: %d\n", key, hash_function(key));
    return 0;
}
```

The `hash_function` takes an integer `key` and returns the index by applying modulo operation with the `TABLE_SIZE`. This is a simple and commonly used hash function.

---
## Hash Table

A **hash table** is a data structure that uses hash functions to store and retrieve values quickly. The key is hashed into an index, where the associated value is stored.

```c
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

// Define a structure for hash table entries
typedef struct {
    char key[100];
    int value;
} HashEntry;

HashEntry hash_table[TABLE_SIZE];

// Simple hash function (modular hashing)
int simple_hash(char *str) {
    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value += str[i];
    }
    return hash_value % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(char *key, int value) {
    int index = simple_hash(key);
    strcpy(hash_table[index].key, key);
    hash_table[index].value = value;
}

// Function to retrieve the value for a given key
int retrieve(char *key) {
    int index = simple_hash(key);
    return hash_table[index].value;
}

int main() {
    // Initialize hash table with default values
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i].key[0] = '\0'; // Empty key indicates unused slot
    }

    insert("apple", 10);
    insert("banana", 20);
    insert("cherry", 30);

    printf("Value for 'apple': %d\n", retrieve("apple"));
    printf("Value for 'banana': %d\n", retrieve("banana"));
    printf("Value for 'cherry': %d\n", retrieve("cherry"));

    return 0;
}
```

- The **hash table** is an array of `HashEntry` structures.
- The `insert` function uses the `simple_hash` function to compute the index for the given key and stores the key-value pair in the table.

---
# Collision Handling in Hash Tables

In a hash table, **collisions** occur when two or more keys hash to the same index. Several methods can be used to handle collisions. These include:

> [!Example]
> 1. **Separate Chaining**: Uses linked lists at each table index to handle collisions.
> 2. **Linear Probing**: Resolves collisions by checking subsequent indices.
> 3. **Quadratic Probing**: Uses a quadratic increment to find the next open index.
> 4. **Double Hashing**: Uses a second hash function to compute the step size for probing.
> 5. **Rehashing**: Involves resizing the table and recalculating hash values when the table becomes too full.
> 

---

## Using Separate Chaining

**Separate chaining** resolves collisions by storing multiple elements at the same index, typically using a linked list. If multiple keys hash to the same index, they are stored in the list at that index.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Define a structure for hash table entries (linked list)
typedef struct HashNode {
    char key[100];
    int value;
    struct HashNode* next;
} HashNode;

HashNode* hash_table[TABLE_SIZE];

// Simple hash function
int simple_hash(char *str) {
    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value += str[i];
    }
    return hash_value % TABLE_SIZE;
}

// Function to insert key-value pair into the hash table using separate chaining
void insert(char *key, int value) {
    int index = simple_hash(key);
    HashNode *new_node = (HashNode*)malloc(sizeof(HashNode));
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

// Function to retrieve value for a given key
int retrieve(char *key) {
    int index = simple_hash(key);
    HashNode *node = hash_table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // Key not found
}

int main() {
    // Initialize hash table with NULL pointers
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }

    insert("apple", 10);
    insert("banana", 20);
    insert("cherry", 30);

    printf("Value for 'apple': %d\n", retrieve("apple"));
    printf("Value for 'banana': %d\n", retrieve("banana"));
    printf("Value for 'cherry': %d\n", retrieve("cherry"));

    return 0;
}
```

- Each index in the hash table holds a linked list (`HashNode`).
- When a collision occurs, new elements are added to the front of the list at the corresponding index.

---
## Using Linear/Quadratic Probing

**Linear probing** and **quadratic probing** are methods of **open addressing**, where colliding elements are placed in the next available slot within the hash table.

> [!Important]
> - **Linear Probing**: If a collision occurs, the algorithm checks the next consecutive index until an empty slot is found.
> - **Quadratic Probing**: Similar to linear probing but with a quadratic increment (i.e., checking i+1, i+4, i+9, etc.).

```c
#include <stdio.h>

#define TABLE_SIZE 10

// Define a structure for hash table entries
typedef struct {
    char key[100];
    int value;
    int is_occupied; // Flag to indicate if the slot is occupied
} HashEntry;

HashEntry hash_table[TABLE_SIZE];

// Simple hash function (modular hashing)
int simple_hash(char *str) {
    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value += str[i];
    }
    return hash_value % TABLE_SIZE;
}

// Function to insert key-value pair using linear probing
void insert(char *key, int value) {
    int index = simple_hash(key);
    while (hash_table[index].is_occupied) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }
    strcpy(hash_table[index].key, key);
    hash_table[index].value = value;
    hash_table[index].is_occupied = 1;
}

// Function to retrieve value for a given key
int retrieve(char *key) {
    int index = simple_hash(key);
    while (hash_table[index].is_occupied) {
        if (strcmp(hash_table[index].key, key) == 0) {
            return hash_table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1; // Key not found
}

int main() {
    // Initialize hash table with default values
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i].is_occupied = 0; // Mark slots as empty
    }

    insert("apple", 10);
    insert("banana", 20);
    insert("cherry", 30);

    printf("Value for 'apple': %d\n", retrieve("apple"));
    printf("Value for 'banana': %d\n", retrieve("banana"));
    printf("Value for 'cherry': %d\n", retrieve("cherry"));

    return 0;
}
```

- **Linear probing** is used when a collision occurs by moving to the next index in a circular manner.
- The `is_occupied` flag ensures we skip over empty slots.

---
## Using Double Hashing and Rehashing

**Double hashing** uses a second hash function to compute the step size for probing. It is used to resolve collisions and is often more effective than linear or quadratic probing.

**Rehashing** involves resizing the hash table and recalculating hash values when the load factor exceeds a certain threshold.

```c
#include <stdio.h>

#define TABLE_SIZE 10

// Define a structure for hash table entries
typedef struct {
    char key[100];
    int value;
    int is_occupied;
} HashEntry;

HashEntry hash_table[TABLE_SIZE];

// Simple hash function
int simple_hash(char *str) {
    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value += str[i];
    }
    return hash_value % TABLE_SIZE;
}

// Second hash function for double hashing
int double_hash(char *str) {
    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value += str[i];
    }
    return 1 + (hash_value % (TABLE_SIZE - 1)); // Ensure non-zero step size
}

// Function to insert key-value pair using double hashing
void insert(char *key, int value) {
    int index = simple_hash(key);
    int step_size = double_hash(key);
    while (hash_table[index].is_occupied) {
        index = (index + step_size) % TABLE_SIZE; // Double hashing
    }
    strcpy(hash_table[index].key, key);
    hash_table[index].value = value;
    hash_table[index].is_occupied = 1;
}

// Function to retrieve value for a given key
int retrieve(char *key) {
    int index = simple_hash(key);
    int step_size = double_hash(key);
    while (hash_table[index].is_occupied) {
        if (strcmp(hash_table[index].key, key) == 0) {
            return hash_table[index].value;
        }
        index = (index + step_size) % TABLE_SIZE;
    }
    return -1; // Key not found
}

int main() {
    // Initialize hash table with default values
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i].is_occupied = 0;
    }

    insert("apple", 10);
    insert("banana", 20);
    insert("cherry", 30);

    printf("Value for 'apple': %d\n", retrieve("apple"));
    printf("Value for 'banana': %d\n", retrieve("banana"));
    printf("Value for 'cherry': %d\n", retrieve("cherry"));

    return 0;
}
```

- **Double hashing** uses a second hash function to compute the step size, which reduces clustering problems compared to linear and quadratic probing.
- When a collision occurs, the algorithm moves `step_size` positions forward until an empty slot is found.

---
# Tries

A **Trie** (or prefix tree) is a specialized tree-like data structure that stores a set of strings, where each node represents a single character of the string. Tries are particularly useful for tasks involving prefix matching, such as autocomplete or spell-checking.

> [!Info]
> - **Nodes**: Each node contains a character and a reference to its child nodes.
> - **Root**: The root of a trie is an empty node.
> - **Leaf Nodes**: A leaf node represents the end of a word (usually marked with a special flag).
> - **Edge**: The edge from one node to another represents a character in the string.
> - **Efficiency**: Tries provide efficient search, insertion, and deletion operations compared to other string matching algorithms.

---
## Applications of Tries

1. **Word Searching**: Tries provide an efficient way to store and search for words in a dictionary.
2. **Autocomplete**: Tries are often used in applications like search engines and text editors for autocomplete functionality.
3. **Spell Checking**: Tries help in verifying if a word exists in the dictionary by checking the prefix structure.

---
## Insert, Search, and Delete Operations

> [!Example]
> 1. **Insert**: Adds a word to the trie by creating nodes for each character.
> 2. **Search**: Looks for a word in the trie by following nodes.
> 3. **Delete**: Removes a word from the trie by deleting nodes as necessary.
> 4. **Display Words in Lexicographical Order**: Traverse the trie in depth-first order and print words when reaching the end of a word.
> 5. **Word Completion (Autocomplete)**: Use a given prefix to find matching words in the trie and suggest completions.

### Insert Operation

To insert a word into a trie, we start from the root and follow the characters of the word. If a character doesn't exist in the current node, we create a new node for it.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie Node structure
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int is_end_of_word; // 1 if the node is the end of a word
} TrieNode;

// Function to create a new trie node
TrieNode* create_node() {
    TrieNode* new_node = (TrieNode*)malloc(sizeof(TrieNode));
    new_node->is_end_of_word = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

// Function to insert a word into the trie
void insert(TrieNode* root, const char* word) {
    TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a'; // Convert char to index (assuming lowercase)
        if (current->children[index] == NULL) {
            current->children[index] = create_node();
        }
        current = current->children[index];
    }
    current->is_end_of_word = 1; // Mark the end of the word
}

int main() {
    TrieNode* root = create_node();

    insert(root, "apple");
    insert(root, "banana");
    insert(root, "app");

    printf("Words inserted into the trie\n");

    return 0;
}
```

### Search Operation

To search for a word, we start at the root and follow the characters of the word, checking each corresponding child node. If we reach the end of the word and the node is marked as the end of the word, the word exists in the trie.

```c
// Function to search for a word in the trie
int search(TrieNode* root, const char* word) {
    TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0; // Word not found
        }
        current = current->children[index];
    }
    return current->is_end_of_word; // Return true if it's the end of a word
}
```

### Delete Operation

To delete a word, we first perform a search to check if the word exists. Then, we recursively remove the nodes that are no longer needed.

```c
// Helper function to delete a word recursively
int delete_helper(TrieNode* root, const char* word, int depth) {
    if (root == NULL) {
        return 0; // Word doesn't exist
    }

    if (word[depth] != '\0') {
        int index = word[depth] - 'a';
        if (delete_helper(root->children[index], word, depth + 1) == 0) {
            return 0; // Word doesn't exist
        }
    } else {
        if (root->is_end_of_word) {
            root->is_end_of_word = 0; // Mark as not end of word
        }

        // If the node has no children, it can be deleted
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root->children[i] != NULL) {
                return 1; // Word is still present
            }
        }
        return 0; // Can delete this node
    }
    return 1;
}

// Function to delete a word from the trie
void delete(TrieNode* root, const char* word) {
    delete_helper(root, word, 0);
}
```

---

## Application: Display Words in Trie in Lexicographical Order

To display words in lexicographical order, we perform a depth-first traversal of the trie, and for each leaf node (end of a word), we print the word.

```c
// Function to display words in lexicographical order
void display_words(TrieNode* root, char* word, int level) {
    if (root == NULL) {
        return;
    }

    if (root->is_end_of_word) {
        word[level] = '\0';
        printf("%s\n", word); // Print the word
    }

    // Recur for all child nodes
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            word[level] = 'a' + i; // Add character to word
            display_words(root->children[i], word, level + 1);
        }
    }
}

int main() {
    TrieNode* root = create_node();

    insert(root, "apple");
    insert(root, "banana");
    insert(root, "app");

    char word[100];
    printf("Words in lexicographical order:\n");
    display_words(root, word, 0);

    return 0;
}
```

---

## Application: Word Completion (Autocomplete Feature)

To implement autocomplete, we find the node corresponding to the prefix and display all words that can be formed from that node.

```c
// Function to display all words starting from a given prefix
void autocomplete(TrieNode* root, char* prefix, int index, char* word, int level) {
    if (root == NULL) {
        return;
    }

    if (prefix[index] != '\0') {
        int child_index = prefix[index] - 'a';
        autocomplete(root->children[child_index], prefix, index + 1, word, level);
        return;
    }

    // If prefix is found, print all words starting from this node
    if (root->is_end_of_word) {
        word[level] = '\0';
        printf("%s\n", word); // Print the word
    }

    // Recur for all child nodes
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            word[level] = 'a' + i; // Add character to word
            autocomplete(root->children[i], prefix, index, word, level + 1);
        }
    }
}

int main() {
    TrieNode* root = create_node();

    insert(root, "apple");
    insert(root, "banana");
    insert(root, "app");
    insert(root, "bat");

    char prefix[] = "app";
    char word[100];
    printf("Autocomplete suggestions for '%s':\n", prefix);
    autocomplete(root, prefix, 0, word, 0);

    return 0;
}
```

---

# Suffix Tree

A **Suffix Tree** for a string `S` of length `n` is a compressed trie that contains all the suffixes of the string. Each leaf node represents a suffix, and the internal nodes represent common prefixes among the suffixes. The tree structure allows for efficient substring searches and many other string processing operations.

> [!NOTE]
> 1. **Definition**: A suffix tree is a compressed trie that stores all suffixes of a given string.
> 2. **Properties**:
>    - Stores all suffixes.
>    - Efficient for substring searching, pattern matching, and finding repeated substrings.
>    - Each leaf node corresponds to a suffix.
> 3. **Construction**:
>    - Naive approach builds the tree by inserting each suffix one by one.
>    - Ukkonen's Algorithm provides an optimal construction in **O(n)** time.
> 4. **Applications**:
>    - Substring search
>    - Pattern matching
>    - Finding repeated substrings
>    - Text compression
>    - Longest common substring problem

### Properties of a Suffix Tree

1. **Compact Representation**: It stores all suffixes of a string in a compressed manner.
2. **Leaf Nodes**: Each leaf node corresponds to a suffix of the string, and it contains the starting index of the suffix in the original string.
3. **Internal Nodes**: Internal nodes represent common prefixes between two or more suffixes.
4. **Edge Labels**: Edges in the suffix tree are labeled with substrings of the original string.
5. **Time Complexity**: Construction of the suffix tree can be done in **O(n)** time (where n is the length of the string) with the help of advanced algorithms like Ukkonen's algorithm.

---
## Construction of a Suffix Tree

There are multiple algorithms for constructing a suffix tree, with the most efficient being **Ukkonen’s Algorithm**, which constructs the tree in **O(n)** time. However, constructing a suffix tree can be complex, so we’ll start with a basic, conceptual approach before delving into more optimized algorithms.

1. **Add a Special Character**: First, we append a special character (usually '$') to the string to ensure that no suffix is a prefix of another. This special character helps avoid ambiguity when constructing the tree.
2. **Insert Suffixes**: We then insert each suffix of the string into the tree. Each suffix is inserted by following the characters one by one, creating nodes as necessary.

### Example: Construction of a Suffix Tree (Naive Approach)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Define the structure for a Suffix Tree Node
typedef struct SuffixTreeNode {
    struct SuffixTreeNode* children[MAX_CHAR];
    int start_index;
    int *end_index;
} SuffixTreeNode;

// Function to create a new node in the suffix tree
SuffixTreeNode* create_node(int start, int *end) {
    SuffixTreeNode* node = (SuffixTreeNode*)malloc(sizeof(SuffixTreeNode));
    node->start_index = start;
    node->end_index = end;
    
    for (int i = 0; i < MAX_CHAR; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to build the suffix tree for a given string
SuffixTreeNode* build_suffix_tree(char *str) {
    int n = strlen(str);
    int *end_index = (int*)malloc(sizeof(int));
    *end_index = -1;
    SuffixTreeNode* root = create_node(-1, end_index); // Root node with a special start index
    
    // Insert each suffix of the string into the tree
    for (int i = 0; i < n; i++) {
        SuffixTreeNode* current = root;
        int j = i;
        while (j < n) {
            int index = str[j] - 'a'; // Convert char to index
            if (current->children[index] == NULL) {
                current->children[index] = create_node(j, end_index); // Create new node
            }
            current = current->children[index];
            j++;
        }
    }
    return root;
}

// Helper function to print the suffix tree
void print_suffix_tree(SuffixTreeNode* root, char *str, char* current_str, int level) {
    if (root == NULL) return;

    // If the node represents a suffix, print it
    if (root->start_index != -1) {
        current_str[level] = str[root->start_index];
        current_str[level + 1] = '\0';
        printf("%s\n", current_str);
    }

    // Recursively print the children
    for (int i = 0; i < MAX_CHAR; i++) {
        if (root->children[i] != NULL) {
            current_str[level] = 'a' + i; // Add current character to the string
            print_suffix_tree(root->children[i], str, current_str, level + 1);
        }
    }
}

int main() {
    char str[] = "banana$"; // Append $ to mark the end of the string
    SuffixTreeNode* root = build_suffix_tree(str);
    char current_str[100];
    printf("Suffix Tree (in order of suffixes):\n");
    print_suffix_tree(root, str, current_str, 0);
    return 0;
}
```

- **Node Structure**: Each node has a `start_index` to mark the beginning of a substring and an `end_index` that points to the end of the substring.
- **Building the Tree**: The `build_suffix_tree` function inserts each suffix of the string into the tree by iterating through the string and creating new nodes as necessary.
- **Printing the Tree**: The `print_suffix_tree` function recursively prints each suffix stored in the leaf nodes of the tree.

```
Suffix Tree (in order of suffixes):
banana$
anana$
nana$
ana$
na$
a$
```

---
### Optimized Suffix Tree Construction

While the above naive method builds a simple suffix tree, it is not efficient for large strings due to its time complexity. The optimal construction algorithm is **Ukkonen's Algorithm**, which builds the suffix tree in **O(n)** time by using the following ideas:

1. **Implicit Suffix Tree**: Instead of building the full suffix tree at once, Ukkonen builds an **implicit suffix tree** where only the necessary suffixes are stored at each step.
2. **Active Point**: The algorithm uses an active point (a combination of an active node, edge, and position) to traverse the tree efficiently.
3. **Suffix Links**: These are used to speed up the tree construction process by pointing to the longest suffix that can be shared with the current suffix.

> [!Info]
> Implementing **Ukkonen's Algorithm** is more involved and requires careful handling of active points and suffix links. The general steps of the algorithm include:
> 
> - Iterating over each character in the string.
> - Maintaining an active point, which helps to minimize redundant work when inserting new suffixes.
> - Handling edge cases, such as when a new character introduces a new suffix or when an internal node is split.

