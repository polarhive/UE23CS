# Jackfruit Problem

## Development of an E-commerce Platform with a Recommendation System

## Team details

```plain
PES2UG23CS340 Mithun N
PES2UG23CS357 Jeel Nada
PES2UG23CS368 Nathan Paul
PES2UG23CS371 Navneet Nayak
```

- Team no: 3
- Section F

## Structure

```sh
├── a.out <- run this 
├── include
│   ├── common.h
│   ├── product.h
│   ├── recommend.h
│   └── user.h
├── README.md
└── src
    ├── main.c
    ├── product.c
    ├── recommend.c
    └── user.c
```

---

## Flow of program

This program demonstrates a simple user and product management system. It

includes functionalities to add users, add products, record browsing and

purchase history, and recommend products to users based on their

history.

1. Initialize user and product maps.
2. Add users with unique IDs.
   line: `add_user("Jeel", 1);`

3. Add products with unique IDs and categories.
   line: `add_product("Laptop", 101, "Electronics");`

4. Record browsing history for users.
   line: `add_browsing_history(1, 101);`

   Record purchase history for users.

   line: `add_purchase_history(3, 102);`

5. **Recommending Products**:
   line: `recommend_products(1);`

6. **Program Termination**:
    The program terminates after recommending products to all users.

---

## How to Run?

Use gcc runs throught the `src/` directory and compiles all the `.c` and `.h` files.

```
gcc src/*.c -I./include
./a.out (OR) ./a.exe
```
