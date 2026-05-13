# Unit 1: Introduction, Lexical Analysis & Top-down Parsers

---

## 1. Introduction to Compiler Design

### Why Compilers?

- High-level languages (C, Java, Python) are designed for humans — machines don't understand them.
- A **compiler** translates source programs into equivalent target programs.
- Key role: **interface between applications and machine architectures**.

### Definition

> A **compiler** is a program that reads a source language program and translates it into an equivalent target language program. It also reports errors detected during translation.

### History

| Year | Milestone |
|---|---|
| 1952 | Grace Hopper wrote the first compiler for the A-0 System language; coined the term "compiler" |
| 1957 | First commercially available compiler — FORTRAN (John Backus, IBM); took 18 person-years |
| 1960 | COBOL — first language compiled on multiple platforms |

### Applications of Compiler Technology

- **Binary translation:** Convert executables for new architectures without recompiling
- **Hardware synthesis:** Compile functional languages (Haskell) to digital circuits (FPGA)
- **Database query interpreters/compilers**
- **JIT compilation:** Java bytecode → machine code at runtime

---

## 2. Types of Compilers

| Type | Description |
|---|---|
| **One-pass compiler** | Single scan of source code; generates target code directly |
| **Multi-pass compiler** | Multiple passes over source or intermediate form; better optimization |
| **Cross compiler** | Runs on one platform but generates code for another (e.g., compile ARM code on x86) |
| **Native compiler** | Compiles code for the same platform it runs on |
| **Decompiler** | Translates low-level code back to high-level |
| **Source-to-source** | Translates between two high-level languages (transpiler) |
| **Bootstrapping (Self-hosting)** | Compiler written in the language it compiles |
| **Compiler-compiler** | Generates a compiler from a grammar description (e.g., YACC) |

---

## 3. Language Processors

### Compiler vs Interpreter

| Feature | Compiler | Interpreter |
|---|---|---|
| Translation | Entire program → target program | Statement-by-statement execution |
| Speed | Target program runs faster | Slower |
| Error detection | After full analysis | At each statement |
| Output | Executable file | Direct output |
| Examples | C, C++, Fortran | Python, Ruby, BASIC, Perl |

### Hybrid Compiler (Java)

```
Java Source → [Compiler] → Bytecode → [JVM Interpreter] → Output
                                    ↑
                              JIT Compiler (optional — translates bytecode
                              to machine code before execution for speed)
```

- Bytecodes are portable across platforms
- JIT compilers give near-native speed

### Compiler "Cousins" — The Full Toolchain

```
Source.c
   ↓ Preprocessor (cpp): expand #includes, macros, #ifdefs → Source.i
   ↓ Compiler (gcc -S): translate to assembly → Source.s
   ↓ Assembler (as): translate assembly to object code → Source.o
   ↓ Linker/Loader (ld): combine .o files + libraries → Executable
```

- `gcc -E hello.c > hello.i` (preprocess only)
- `gcc -S hello.i` (compile to assembly)
- `as hello.s -o hello.o` (assemble)

---

## 4. The Phases of a Compiler

```
Source Program
     ↓
┌─────────────────────┐
│  1. Lexical Analyzer │  → Token stream
├─────────────────────┤
│  2. Syntax Analyzer  │  → Parse tree (AST)
│     (Parser)         │
├─────────────────────┤
│  3. Semantic Analyzer│  → Annotated AST
├─────────────────────┤
│  4. Intermediate Code│  → IR (TAC, AST)
│     Generator        │
├─────────────────────┤
│  5. Code Optimizer   │  → Optimized IR
│  (Machine-independent│
├─────────────────────┤
│  6. Code Generator   │  → Target machine code
└─────────────────────┘
     ↕ Symbol Table (used by ALL phases)
     ↕ Error Handler (used by ALL phases)
```

### Phase Descriptions

| Phase | Input | Output | Function |
|---|---|---|---|
| **Lexical Analysis** | Character stream | Token stream | Tokenization, removes whitespace/comments |
| **Syntax Analysis** | Token stream | Parse tree | Checks grammatical structure using CFG |
| **Semantic Analysis** | Parse tree | Annotated tree | Type checking, scope resolution |
| **Intermediate Code Gen** | Annotated tree | TAC / IR | Platform-independent code |
| **Code Optimization** | IR | Optimized IR | Remove redundancy, improve efficiency |
| **Code Generation** | Optimized IR | Machine code | Register allocation, instruction selection |

### Example: Compilation of `position = initial + rate * 60`

| Phase | Output |
|---|---|
| Lexical | `<id,1> <=> <id,2> <+> <id,3> <*> <num,60>` |
| Syntax | Parse tree rooted at `=` |
| Semantic | Type coercion: 60 → 60.0 (inttofloat) |
| IR | `t1 = inttofloat(60)` `t2 = id3 * t1` `t3 = id2 + t2` `id1 = t3` |
| Optimized | `t1 = id3 * 60.0` `id1 = id2 + t1` |
| Code gen | `LDF R2, id3` `MULF R2, R2, #60.0` `LDF R1, id2` `ADDF R1, R1, R2` `STF id1, R1` |

---

## 5. Symbol Table

- A **symbol table** is a data structure used throughout compilation to store information about identifiers (name, type, scope, memory location).
- Created during **lexical analysis** when identifiers are first encountered.
- Updated and queried by ALL phases:
  - **Lexical Analysis:** Create entries for identifiers
  - **Semantic Analysis:** Type checking, scope resolution
  - **Intermediate Code Gen:** Type info for code gen
  - **Code Generation:** Retrieve addresses and storage info

---

## 6. Lexical Analysis

### Role of the Lexical Analyzer

- Also called the **scanner** or **lexer**
- Reads character stream, groups characters into **tokens**, and passes tokens to the parser
- Also: removes whitespace and comments; handles input buffering

```
Source Characters → [Lexical Analyzer] → Token stream → [Parser]
                          ↕ Symbol Table
```

**Interactions:**

- Parser calls `getNextToken()` on the lexer
- Lexer returns `<token-name, attribute-value>` pairs
- Both consult and update the symbol table

### Tokens, Patterns, Lexemes

| Term | Definition | Example |
|---|---|---|
| **Token** | Abstract symbol representing a category of lexical unit | `<id>`, `<num>`, `<if>` |
| **Lexeme** | The actual character sequence matching a token | `position`, `60`, `if` |
| **Pattern** | Rule describing the set of lexemes for a token | `letter(letter|digit)*` for identifiers |

**Token representation:** `<token-name, attribute-value>`

- `<id, 3>` — identifier with symbol table entry 3
- `<num, 60>` — numeric literal with value 60
- `<if>` — keyword (no attribute needed)
- `<+>`, `<=>` — operators (attribute optional)

### Token Categories

1. **Keywords:** `if`, `else`, `while`, `return` — one token per keyword
2. **Operators:** `+`, `-`, `*`, `/`, `==`, `<=` — individually or in classes
3. **Identifiers:** `id` — one token; lexeme stored in symbol table
4. **Literals/Constants:** `num` (integers), `real` (floats), `literal` (strings)
5. **Punctuation:** `(`, `)`, `{`, `}`, `;`, `,`

**Example:** `if (a == b) c = c + 1;`

Tokens: `<if>`, `<(>`, `<id,a>`, `<==,>`, `<id,b>`, `<)>`, `<id,c>`, `<=>`, `<id,c>`, `<+>`, `<num,1>`, `<;>`

### Lexical Analysis vs Syntax Analysis

- **Lexical Analysis:** simpler structure (regular expressions); efficiency matters (I/O bound); handles whitespace/comments
- **Syntax Analysis:** complex structure (context-free grammars); CFG required for balanced constructs like parentheses

### Why Separate Phases?

1. **Simplicity of design** — cleaner parser; lexer handles low-level details
2. **Efficiency** — specialized I/O optimizations for lexer
3. **Portability** — input-device-specific aspects isolated in lexer

---

## 7. Regular Expressions

> **Regular expressions** are a concise notation for describing patterns (sets of strings).

### Operators and Notation

| Notation | Name | Meaning |
|---|---|---|
| `ε` | Epsilon | Empty string |
| `a` | Symbol | Single character `a` |
| `r\|s` | Union/Alternation | Any string in r OR s |
| `rs` | Concatenation | A string in r followed by s |
| `r*` | Kleene closure | Zero or more repetitions of r |
| `r+` | Positive closure | One or more repetitions: `rr*` |
| `r?` | Optional | Zero or one occurrence: `r\|ε` |
| `[abc]` | Character class | Matches a, b, or c |
| `[a-z]` | Range class | Any lowercase letter |
| `.` | Any character | Matches any single character except newline |

**Precedence (high to low):** `*` (highest) → `+` → `?` → concatenation → `|` (lowest)

### Examples

- **Identifier:** `letter(letter|digit)*` where `letter = [a-zA-Z_]`, `digit = [0-9]`
- **Integer:** `digit+`
- **Float:** `digit+.digit*` or `digit*.digit+`
- **Whitespace:** `(blank|tab|newline)+`
- **C comment:** `/*([^*]|\*+[^*/])*\*+/`

### Regular Definitions

Named pattern abbreviations:

```
digit  → [0-9]
letter → [a-zA-Z_]
id     → letter(letter|digit)*
num    → digit+(\.digit+)?(E[+-]?digit+)?
```

### Limitations of Regular Expressions

- Cannot check **balanced tokens** (parentheses, braces) — requires CFG
- Cannot express context-sensitive constraints (type checking)

---

## 8. Finite Automata (FA)

### Why Finite Automata?

- Regular expressions describe patterns; **finite automata recognize them** — used to implement lexers

### 8.1 NFA (Non-deterministic Finite Automaton)

- A 5-tuple: M = (Q, Σ, δ, q₀, F) where δ: Q × (Σ ∪ {ε}) → 2^Q
- Can have **ε-transitions** (move without consuming input)
- Multiple possible next states for same input
- More compact — easier to construct from regex

### 8.2 DFA (Deterministic Finite Automaton)

- A 5-tuple: M = (Q, Σ, δ, q₀, F) where δ: Q × Σ → Q
- Exactly **one transition per state per input symbol**
- No ε-transitions
- More efficient to execute (O(n) for input of length n)

### NFA vs DFA

| Feature | NFA | DFA |
|---|---|---|
| Transitions | Multiple / ε allowed | Exactly one per symbol |
| Construction | Easy from regex (Thompson's) | Complex (subset construction) |
| Execution | Slow (track all paths) | Fast (single path) |
| States | Fewer states | Potentially exponential states |
| Power | Equivalent (same languages) | Equivalent |

---

## 9. Thompson's Construction (Regex → NFA)

Build NFA inductively from the structure of the regex:

```
ε:     →(i)──ε──▶(f)

a:     →(i)──a──▶(f)

r|s:       ┌──ε──[NFA_r]──ε──┐
       →(i)─┤                  ├─▶(f)
           └──ε──[NFA_s]──ε──┘

rs:    →(i)[NFA_r](m)──ε──(m)[NFA_s](f)

r*:    ┌──────────ε─────────────┐
       │   ┌────ε────┐          │
       →(i)─┴──▶[NFA_r]──▶(m)──┴──▶(f)
              └─────ε──────┘
```

---

## 10. Subset Construction (NFA → DFA)

Converts NFA to equivalent DFA. Each DFA state = a **set of NFA states** (subset).

**Algorithm:**

1. Compute ε-closure(q₀) — start state of DFA
2. For each unmarked DFA state T and each input symbol a:
   - Compute move(T, a) = all NFA states reachable from T on a
   - Compute ε-closure(move(T, a))
   - Add as new DFA state if not already present
3. DFA accepting states = any DFA state containing an NFA accepting state

**ε-closure(T):** Set of NFA states reachable from T via ε-transitions only (including T itself)

---

## 11. DFA Minimization

Reduce DFA states while preserving the recognized language:

**Myhill-Nerode / Partition Refinement Algorithm:**

1. Start with two groups: accepting states F and non-accepting states Q−F
2. Repeatedly partition groups: two states in a group are **distinguishable** if on some input they go to different groups
3. Repeat until no further partitioning is possible
4. Each group becomes a single state in the minimized DFA

---

## 12. Lex / Flex — Lexer Generator

> **Lex** (or **Flex**) is a tool that generates a lexical analyzer from a specification of token patterns as regular expressions.

### How Lex Works Internally

```
Regular Expressions → NFA (Thompson's construction)
NFA → DFA (Subset construction)
DFA → Optimized DFA (State minimization)
DFA → C code (lex.yy.c) — table-driven DFA
```

### Lex Specification Structure

```
%{
/* C declarations, header includes */
%}

/* definitions */
digit  [0-9]
letter [a-zA-Z_]

%%
/* rules: pattern { action } */
{letter}({letter}|{digit})*  { return ID; }
{digit}+                     { return NUM; }
[ \t\n]+                     { /* skip whitespace */ }
"if"                         { return IF; }
.                            { /* error */ }

%%
/* user code */
```

### Longest Match and Priority Rules

- **Longest match:** Among all patterns that match at current position, the one matching the **longest** lexeme wins
- **Priority:** If two patterns match the same length, the one appearing **first** in the specification wins

---

## 13. Syntax Analysis — Context-Free Grammars

### Role of the Parser

- Receives token stream from lexer
- Checks if the token sequence conforms to the grammar (syntactic structure)
- Produces a **parse tree** or **AST (Abstract Syntax Tree)**
- Reports **syntax errors** with recovery

### Context-Free Grammar (CFG)

A CFG is a 4-tuple G = (V, T, P, S) where:

- V = non-terminals (variables)
- T = terminals (tokens)
- P = production rules of form A → α, where A ∈ V, α ∈ (V ∪ T)*
- S = start symbol

**Example:**

```
E → E + T | T
T → T * F | F
F → ( E ) | id
```

### Derivations

- **Leftmost derivation:** Always expand the **leftmost** non-terminal
- **Rightmost derivation:** Always expand the **rightmost** non-terminal
- Parse trees correspond to derivations (one parse tree per derivation, if unambiguous)

### Ambiguous Grammar

A grammar is **ambiguous** if some string has more than one parse tree (or more than one leftmost/rightmost derivation).

**Example of ambiguous grammar:** `E → E + E | E * E | id`

- String `a + b * c` has two parse trees: `(a+b)*c` or `a+(b*c)`
- **Fix:** Rewrite to enforce precedence and associativity using explicit grammar structure

---

## 14. Top-Down Parsers

> **Top-down parsers** build the parse tree from the **root (start symbol) to the leaves (tokens)**, expanding non-terminals left-to-right.

Two types:

1. **Recursive Descent Parser** — uses recursive procedures
2. **Predictive Parser (LL(1))** — table-driven, no backtracking

---

### 14.1 Left Recursion — Problem for Top-Down Parsers

A grammar is **left-recursive** if it has a production A → Aα (directly or indirectly). Top-down parsers loop infinitely on left-recursive grammars.

#### Eliminating Immediate Left Recursion

Transform: `A → Aα | β` into:

```
A  → βA'
A' → αA' | ε
```

**Example:**

```
E → E + T | T      becomes:    E  → T E'
                               E' → + T E' | ε
```

#### General Left Recursion Elimination Algorithm

For all non-terminals A₁, A₂, ..., Aₙ ordered:

- For i = 1 to n:
  - For j = 1 to i-1: Replace Aᵢ → Aⱼγ with Aᵢ → δ₁γ | δ₂γ | ... (substitute Aⱼ's productions)
  - Eliminate immediate left recursion in Aᵢ

---

### 14.2 Left Factoring

> **Left factoring** is a grammar transformation applied when two or more productions for the same non-terminal begin with the same prefix.

**Problem:** `A → αβ₁ | αβ₂` — parser cannot choose without looking ahead past α.

**Transformation:**

```
A  → α A'
A' → β₁ | β₂
```

**Effect:** Reduces k-symbol lookahead (LL(k)) to 1-symbol lookahead (LL(1)); eliminates backtracking in RDP.

**Example:**

```
stmt → if expr then stmt else stmt
     | if expr then stmt
```

becomes:

```
stmt  → if expr then stmt stmt'
stmt' → else stmt | ε
```

---

### 14.3 Recursive Descent Parser (RDP)

- One procedure per non-terminal
- Each procedure tries to match its non-terminal against the input
- May require **backtracking** if the grammar is not LL(1)
- Best for **LL(1) (left-factored, non-left-recursive)** grammars

```c
// For grammar: E → T E'   E' → + T E' | ε   T → F T'   T' → * F T' | ε   F → ( E ) | id
void E()  { T(); E_prime(); }
void E_prime() {
    if (lookahead == '+') { match('+'); T(); E_prime(); }
    // ε production: do nothing
}
void T()  { F(); T_prime(); }
void T_prime() {
    if (lookahead == '*') { match('*'); F(); T_prime(); }
}
void F() {
    if (lookahead == '(') { match('('); E(); match(')'); }
    else if (lookahead == ID) { match(ID); }
    else error();
}
```

---

### 14.4 FIRST and FOLLOW Sets

These sets drive the construction of predictive parsing tables.

#### FIRST(α)

> **FIRST(α)** = set of terminals that begin strings derivable from α. If α ⟹* ε, then ε ∈ FIRST(α).

**Rules to compute FIRST(X):**

1. If X is a terminal: FIRST(X) = {X}
2. If X → ε: add ε to FIRST(X)
3. If X → Y₁Y₂...Yₖ:
   - Add FIRST(Y₁) − {ε} to FIRST(X)
   - If ε ∈ FIRST(Y₁): add FIRST(Y₂) − {ε}, and so on
   - If ε ∈ FIRST(Yᵢ) for all i: add ε to FIRST(X)

#### FOLLOW(A)

> **FOLLOW(A)** = set of terminals that can appear immediately to the right of A in a sentential form. $ (EOF) ∈ FOLLOW(S) always.

**Rules to compute FOLLOW(A):**

1. Place $ in FOLLOW(S) (start symbol)
2. For production B → αAβ: add FIRST(β) − {ε} to FOLLOW(A)
3. For production B → αA or B → αAβ where ε ∈ FIRST(β): add FOLLOW(B) to FOLLOW(A)

**Example:** Grammar: `E → TE'`, `E' → +TE' | ε`, `T → FT'`, `T' → *FT' | ε`, `F → (E) | id`

| Non-terminal | FIRST | FOLLOW |
|---|---|---|
| E | `{(, id}` | `{), $}` |
| E' | `{+, ε}` | `{), $}` |
| T | `{(, id}` | `{+, ), $}` |
| T' | `{*, ε}` | `{+, ), $}` |
| F | `{(, id}` | `{*, +, ), $}` |

---

### 14.5 LL(1) Grammar

> A grammar is **LL(1)** if for every pair of productions A → α | β:
> 1. FIRST(α) ∩ FIRST(β) = ∅ (no FIRST/FIRST conflict)
> 2. If ε ∈ FIRST(α): FIRST(β) ∩ FOLLOW(A) = ∅ (no FIRST/FOLLOW conflict)

**LL(1)** stands for:

- **L**: left-to-right scan of input
- **L**: leftmost derivation
- **1**: one symbol of lookahead

---

### 14.6 Predictive Parsing Table Construction

**Algorithm — build M[A, a] for non-terminal A and terminal a:**

For each production A → α:

1. For each terminal `a` in FIRST(α): add `A → α` to M[A, a]
2. If ε ∈ FIRST(α):
   - For each terminal `b` in FOLLOW(A): add `A → α` to M[A, b]
   - If $ ∈ FOLLOW(A): add `A → α` to M[A, $]
3. All empty cells are **error**

**Example parsing table** for `E → TE'`, `E' → +TE' | ε`, `T → FT'`, `T' → *FT' | ε`, `F → (E) | id`:

| Non-terminal | id | + | * | ( | ) | $ |
|---|---|---|---|---|---|---|
| E | E→TE' | | | E→TE' | | |
| E' | | E'→+TE' | | | E'→ε | E'→ε |
| T | T→FT' | | | T→FT' | | |
| T' | | T'→ε | T'→*FT' | | T'→ε | T'→ε |
| F | F→id | | | F→(E) | | |

---

### 14.7 Non-Recursive (Table-Driven) Predictive Parser

**Components:**

- Input buffer (token stream + $)
- Stack (starts with S$)
- Parsing table M[A, a]
- Output (productions used)

**Algorithm:**

```
Push $ and S onto stack
a = getNextToken()
while stack top ≠ $ :
    X = top of stack
    if X == a:                     // X is a terminal matching input
        pop X; a = getNextToken()
    elif X is terminal and X ≠ a:  // mismatch
        error()
    elif M[X, a] = error:          // no production
        error()
    elif M[X, a] = X → Y₁Y₂...Yₖ: // apply production
        pop X
        push Yₖ, ..., Y₂, Y₁      // push RHS in reverse
        output production
if a == $: accept
else: error
```

---

## 15. Error Recovery in Parsers

### Types of Errors

- **Lexical:** Misspelled identifier, illegal character
- **Syntax:** Missing semicolon, unmatched parenthesis
- **Semantic:** Type mismatch, undeclared variable
- **Logical:** Correct syntax but wrong meaning

### Recovery Strategies

1. **Panic mode:** Skip tokens until a synchronizing token is found (e.g., `;`, `}`)
2. **Phrase-level recovery:** Local correction (e.g., insert missing `;`)
3. **Error productions:** Add grammar productions for common error patterns
4. **Global correction:** Find the minimal change to make the input valid (expensive)

---

## Summary

```
Source Characters
    ↓
Lexical Analysis (Regular Expressions → NFA → DFA)
    - Tokens: <token-name, attribute>
    - Uses: FIRST chars, longest match, priority rules
    ↓
Syntax Analysis — Top-down Parsers
    ↓
    ├── Remove Left Recursion
    ├── Apply Left Factoring
    ↓
    ├── Recursive Descent Parser (LL(1), hand-coded)
    └── Predictive Parser (LL(1), table-driven)
           - FIRST / FOLLOW computation
           - Parsing table M[A, a]
           - Stack-based parsing algorithm
```

---

## Key Terms

| Term                | Definition                                                     |
| ------------------- | -------------------------------------------------------------- |
| Token               | Atomic unit of lexical analysis (e.g., `<id>`, `<num>`, `<+>`) |
| Lexeme              | Actual character sequence matched by a token pattern           |
| Pattern             | Regular expression describing valid lexemes for a token        |
| Regular Expression  | Algebraic notation for sets of strings                         |
| NFA                 | Non-deterministic FA — ε-transitions allowed                   |
| DFA                 | Deterministic FA — exactly one transition per symbol           |
| Thompson's          | Algorithm to convert regex to NFA                              |
| Subset Construction | Algorithm to convert NFA to DFA                                |
| Left Recursion      | A → Aα; eliminated before top-down parsing                     |
| Left Factoring      | A → αβ₁ \| αβ₂ → A → αA'; reduces lookahead needed             |
| FIRST(α)            | Terminals that can begin strings derived from α                |
| FOLLOW(A)           | Terminals that can follow A in a sentential form               |
| LL(1)               | Grammar parseable left-to-right with 1 lookahead               |
| Predictive Parser   | Table-driven top-down parser; no backtracking                  |
| RDP                 | Recursive Descent Parser — one function per non-terminal       |