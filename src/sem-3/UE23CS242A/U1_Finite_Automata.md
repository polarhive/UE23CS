# Mathematical Preliminaries and Notation

## Set theory

Basics of set theory

## What is a FSM/A

- States
- - Non-final state
- - Final state

## Acceptors / Transducers

#### Finite Automata: Deterministic Finite Accepters, Non-Deterministic Finite Accepters

#### Equivalence of Deterministic and Non-Deterministic Finite Accepters

#### Reduction of the number of states in Finite Automata

#### Regular Expressions, Connection between Regular Expressions and Regular Languages Regular Grammars

---
# Regular Expressions (Regex)

> Regular expressions (regex) are sequences of characters that define search patterns. They are commonly used for string searching, matching, and manipulation.

---

### Basic Regex Symbols

| Symbol | Meaning                                    |
| ------ | ------------------------------------------ |
| `.`    | Matches any character except a newline     |
| `*`    | Matches 0 or more of the preceding element |
| `+`    | Matches 1 or more of the preceding element |
| `?`    | Matches 0 or 1 of the preceding element    |
| `\d`   | Matches any digit (equivalent to `[0-9]`)  |
| `\w`   | Matches any word character (alphanumeric)  |
| `\s`   | Matches any whitespace character           |
| `\b`   | Word boundary                              |
| `^`    | Start of a string                          |
| `$`    | End of a string                            |
| `[]`   | Character class                            |
| `()`   | Capturing group                            |

---
## Examples of Common Regex Patterns

1. **Match a valid email address**:

``` python
[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}
```

This pattern matches standard email formats like `user@example.com`.

2. **Match a phone number**:

``` python
\(\d{3}\)\s?\d{3}-\d{4}
```
   
Matches phone numbers in the format `(123) 456-7890`.

3. **Match a date in format DD/MM/YYYY**:

``` python
\b\d{2}/\d{2}/\d{4}\b
```
   
   Matches dates such as `06/10/2024`.

---

### Advanced Patterns

- **Non-capturing group**: Use `(?: ...)` for a group without capturing its match.
  - Example: `(?:foo|bar)` matches `foo` or `bar` without storing the result.

- **Lookaheads and Lookbehinds**:
  - **Positive look ahead**: `(?=...)` matches a group that is followed by a certain pattern.
  - **Negative look ahead**: `(?!...)` matches a group that is NOT followed by a certain pattern.
  - **Positive look behind**: `(?<=...)` matches a group that is preceded by a certain pattern.
  - **Negative look behind**: `(?<!...)` matches a group that is NOT preceded by a certain pattern.
