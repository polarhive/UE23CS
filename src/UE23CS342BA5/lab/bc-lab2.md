#  BC: Lab 2

> Submission Date: 2026-02-13
> Name: **Nathan Matthew Paul**
> SRN: **PES2UG23CS368**
> Section: 6F

---

# 1: Merkel Tree

![[Pasted image 20260215002131.png]]

## 2. Questions

a) Can you identify the leaf nodes of a Merkel tree provided just the root?

> No, we cannot derive a leaf node provided we are only given a merkel root. The root is a cryptographic hash which cannot be back tracked to find what was used to derive the hash

b) If leaf Index 3 ‘s content is altered to 12, then which nodes are affected by this change?

> The internal nodes that are the parents and ancestors to the leaf node are affected, as well as the root hash.

c) Use the visualisation tool provided to identify the new hash values. Take a snapshot of the new Merkel tree construction and attach it into the document here.

![[Pasted image 20260215002356.png]]

> 1. `22f2fe4` -> `3d2a8a99`
> 2. `2b85cfac` -> `23225b9`
> 3. `1f1e701a` -> `67f589ce`

d) The path values are the minimal values required to reconstruct the root value or more intuitively, the path values are the root/leaf values that don't get affected when you update the existing leaf's value. Identify the path values of leaf node 6.

![[Pasted image 20260215002440.png]]

> - **Leaf 5** (sibling of 6)
> - **Hash of leaves 7 & 8 subtree** → `1fa47d7f...`
> - **Hash of the entire left subtree (leaves 1–4)** → `232225b9...`

---

## 3. SHA 256 online generator

a) Paste the text and observe the changes in slightest change in the input text. Text: “Hello”

![[Pasted image 20260215002521.png]]

b) Text: “hello”

![[Pasted image 20260215002533.png]]

c) Text: “”

![[Pasted image 20260215002541.png]]

---

# 4. Merkle Tree Using Python

## (c) Take a Screenshot of the Output and Explain

![[Pasted image 20260215003829.png]]

```python
transactions = [
    "Alice pays Bob $10",
    "Charlie pays Dave $5",
    "Eve pays Frank $10"
]
```

### Step 1: Leaf Nodes

Each transaction is hashed using the SHA-256 algorithm:

```
Leaf 1 = SHA256("Alice pays Bob $10")
Leaf 2 = SHA256("Charlie pays Dave $5")
Leaf 3 = SHA256("Eve pays Frank $10")
```

These hashes form the **leaf nodes** of the Merkle Tree.

Since there are **3 transactions (odd number)**, the algorithm duplicates the last hash to maintain a balanced binary structure.

---

### Step 2: Tree Construction

**Level 1:**

```
H12 = SHA256(Leaf1 + Leaf2)
H33 = SHA256(Leaf3 + Leaf3)   # duplicated because odd
```

**Root:**

```
Merkle Root = SHA256(H12 + H33)
```

The **Merkle Root** is the final hash that represents the entire dataset.

If any transaction changes, the Merkle Root will also change.

---

## (e) Modify Transactions and Observe Changes

### Modified Example

```python
transactions = [
    "Alice pays Bob $100",   # changed from $10 to $100
    "Charlie pays Dave $5",
    "Eve pays Frank $10"
]
```

![[Pasted image 20260215004752.png]]

### Observation

Even though only **one value changed (10 → 100)**:

- The hash of Leaf 1 changes completely.
- The intermediate hash H12 changes.
- The Merkle Root changes completely.
    

### Explanation

This happens due to the **avalanche effect** of SHA-256:

- A tiny change in input produces a completely different output hash.
- Because parent nodes depend on child hashes, the change propagates upward.
- Therefore, the final Merkle Root becomes entirely different.
    

This demonstrates **data integrity protection**.

---

## (f) Add Odd Number of Transactions

### Example with 4 Transactions (Even)

```python
transactions = [
    "Alice pays Bob $10",
    "Charlie pays Dave $5",
    "Eve pays Frank $10",
    "Bob pays Alice $20"
]
```

![[Pasted image 20260215004940.png]]

### Construction

Level 1:

```python
H12 = SHA256(L1 + L2)
H34 = SHA256(L3 + L4)
```

Root:

```python
Merkle Root = SHA256(H12 + H34)
```

Since the number of transactions is **even**, no duplication is required.

---

### If We Use 5 Transactions (Odd)

If the number of transactions is odd:

- The last hash is duplicated.
- This ensures the tree remains balanced.
- The duplication affects only that branch but still produces a valid Merkle Root.

---

## (g) Write a Proof and Verify It

### (i) Selected Transaction

```python
"Alice pays Bob $100"
```

### (ii) Manual Proof Computation

A Merkle Proof consists of the **sibling hashes along the path to the root**.

For verifying the first transaction:

```python
Proof = [hash("Charlie pays Dave $5"), hash_of_other_subtree]
```

Verification steps:

```python
current_hash = SHA256("Alice pays Bob $100")

# Step 1
current_hash = SHA256(current_hash + sibling1)

# Step 2
current_hash = SHA256(current_hash + sibling2)

If final hash == Merkle Root → VALID
```

![[Pasted image 20260215005539.png]]

![[Pasted image 20260215005552.png]]

Combined:

![[Screenshot 2026-02-15 at 00.58.09.png]]

![[Pasted image 20260215010005.png]]

### Explanation

- We start with the hash of the transaction.
- Combine it with its sibling hash.
- Hash the result.
- Repeat until we reach the root.
- If the computed value equals the stored Merkle Root, the transaction is verified.

### (iii) Using `verify_transaction` Function

```python
proof = [sibling_hash1, sibling_hash2]
verify_transaction("Alice pays Bob $100", proof, merkle_root)
```

If the function returns:

```
True
```

The transaction belongs to the Merkle Tree.

### (iv) How `verify_transaction` Works

1. Hash the transaction.
2. Combine with the first sibling hash.
3. Hash the result.
4. Repeat for all proof elements.
5. Compare the final computed hash with the Merkle Root.

```python
If equal → Verified
If not equal → Tampered or Invalid
```

This allows efficient verification **without reconstructing the entire tree**.

---

## 1) What happens to the Merkle Root when you change a transaction?

- Its leaf hash changes completely.
- All parent hashes up to the root change.
- The final Merkle Root becomes completely different.
- SHA-256 produces drastically different outputs even for minor input changes.
- This is known as the **avalanche effect**.
- Because the Merkle Root depends on all transactions, any modification anywhere in the tree alters the final root.