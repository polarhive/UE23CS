# Properties of Context Free Languages and Turing Machines

## Context-Free Grammar (CFG): `S -> aS | b`

> A **context-free grammar (CFG)** is a formal way to describe the syntax of languages. It consists of:

1. A set of **production rules**, like `S -> aS | b`, which dictate how strings in the language are formed.
2. **Terminals**: The actual characters in the language (e.g., `a`, `b`).
3. **Non-terminals**: Variables (e.g., `S`) that are placeholders for patterns in the language.
4. **Start symbol**: The initial non-terminal that generates strings.

For example, in the rule `S -> aS | b`, we have:

- **`S`**: A non-terminal that can generate more characters.
- **`a`** and **`b`**: Terminals (characters from the language).
- `|`: Means "or", so `S` can either become `aS` or `b`.

> [!Info] Types of CFG
> A CFG can be:
>
> - linear: `S->aSb|L` one non terminal on RHS
> - non-linear: `S->aSb|bSa|SS|L` more than one non terminal on RHS

---

### Example Rule: `S -> aS | b`

This rule generates strings that consist of one or more `a`s followed by a single `b`. Here's how it works:

1. **Start with `S`**:

``` python
S
```

2. **Apply the rule `S -> aS`**:

``` python
aS
```

3. **Apply the rule again `S -> aS`**:

``` python
aaS
```

4. **Keep applying until you want to stop with `S -> b`**:

``` python
aaab
```

Thus, the string `aaab` is generated by applying the production rules step-by-step.

---

### Derivations

A sequence of applications of production rules. For the above rule, here’s an example:

1. Start with `S`.
2. Apply `S -> aS`:

``` python
S -> aS
```

3. Apply `S -> aS` again:

``` python
aS -> aaS
```

4. Finally, apply `S -> b`:

``` python
aaS -> aaab
```

So, the derivation for `aaab` is:

```python
S -> aS -> aaS -> aaab
```

---

### Example Strings

Using the rule `S -> aS | b`, the following strings can be generated:

- `b` (by directly applying `S -> b`)
- `ab` (by applying `S -> aS`, then `S -> b`)
- `aab` (by applying `S -> aS -> aS -> b`)
- `aaab`, `aaaab`, and so on (more `a`s followed by one `b`).

---

- **Recursion**: The rule `S -> aS` is recursive because `S` can call itself. This allows for generating strings with any number of `a`s.
- **Termination**: The recursion stops when we use the rule `S -> b`, ensuring that the string eventually ends with a `b`.

---

# String belongs to Grammar or not?

1. Start with the S start symbol and choose the closest production that matches to the given string.
2. Replace the Variables with its most appropriate production. Repeat the process until the string is generated or until no other productions are left.

---

> [!Example] Left and Rightmost
>
> ### Leftmost derivation
>
> ![[Pasted image 20241109101225.png]]
>
> ### Rightmost Derivation
>
> ![[Pasted image 20241109101338.png]]

---

## Ambiguous Grammar

![[Pasted image 20241109101939.png]]

> [!Warning]
> The left one is the right one!
> A compiler can not understand ambiguous grammar.

> [!Example] a+bc
> ![[Pasted image 20241109102800.png]]

> [!Example] Regex
> ![[Pasted image 20241109103029.png]]

> [!Example] aab
> ![[Pasted image 20241109103150.png]]

---

# Grammar vs Language Ambiguity

---

# Normal Forms

To sanitize grammar for the compiler.

- CNF
- GNF

1. Membership problem: a string is a part of the language or not?
2. Enabled parsing: you must stop after K steps, quit if over limit.

## CNF

1. Eliminate `L` productions
2. Eliminate unit productions: each step must increase the length of the sentencial form or the number of terminals.
3. Eliminate useless productions and symbols.
	1. Deriviablility: each variable must derive a string / end with set of terminals or `L`
	2. Reachability: each variable must be reachable from `S`

### CNF Examples