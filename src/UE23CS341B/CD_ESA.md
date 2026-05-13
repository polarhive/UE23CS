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

---

# Unit 2: Bottom-up Parsers & Syntax Directed Translation

---

## 1. Bottom-Up Parsing Overview

> **Bottom-up parsers** build the parse tree from the **leaves (tokens) up to the root (start symbol)**, reversing a rightmost derivation.

- Also called **shift-reduce parsing** in its general form
- The most powerful class: **LR parsers** (handle virtually all unambiguous programming language grammars)
- All LL(1) grammars are LR(1), but NOT vice versa — LR handles a strictly larger class

### Key Terms

- **Reduction:** Replacing a matched production body with its head (non-terminal) — reverse of a derivation step
- **Handle:** A substring at the top of the stack that matches a production body; reducing it is the next rightmost-derivation step reversed
- **Rightmost derivation in reverse:** Goal of bottom-up parsing

---

## 2. Shift-Reduce Parsing

### Stack + Input Buffer Model

```
Stack:  $                     Input: id * id $
Action: shift id
Stack:  $ id                  Input: * id $
Action: reduce by F → id
Stack:  $ F                   Input: * id $
...
```

### Four Actions

| Action | Description |
|---|---|
| **Shift** | Push next input token onto the stack |
| **Reduce** | Pop the handle from top of stack; push the LHS non-terminal |
| **Accept** | Stack = `$S`; input = `$` — parsing complete |
| **Error** | No valid action; call error recovery |

**Key invariant:** The handle always appears at the **top of the stack** just before reduction, never inside.

### Conflicts

- **Shift/Reduce conflict:** Parser can either shift the next token or reduce the current stack top
- **Reduce/Reduce conflict:** Two different productions could reduce the same string

Conflicts indicate the grammar is not LR(k) for the given parser (often sign of ambiguity).

---

## 3. LR Parsing

> **LR(k):** Left-to-right scan, Rightmost derivation (reversed), k lookahead symbols

### Why LR Parsers?

1. Recognize virtually all programming language constructs expressible in CFG
2. Most general non-backtracking shift-reduce method
3. Detects syntax errors at the earliest possible point
4. Strictly more powerful than LL parsers

### LR Parser Structure

```
          ┌──────────────────────────────┐
          │         LR Parser            │
Input →   │  Stack (states)              │
tokens    │  ACTION table [state, token] │→ Output
          │  GOTO table   [state, NT]    │
          └──────────────────────────────┘
```

- **Stack:** Holds states (not grammar symbols directly). State summarizes all information about what has been seen.
- **ACTION[s, a]:** What to do in state s with input a → shift/reduce/accept/error
- **GOTO[s, A]:** After reducing to non-terminal A in state s, go to this state

---

## 4. LR(0) Items and the Canonical Collection

### LR(0) Item

> An **LR(0) item** is a production with a **dot** at some position in the body.

For production `A → XYZ`, the items are:

```
A → •XYZ    (nothing seen yet; expecting XYZ)
A → X•YZ    (seen X; expecting YZ)
A → XY•Z    (seen XY; expecting Z)
A → XYZ•    (seen XYZ; ready to reduce!)
```

- `A → ε` yields only one item: `A → •`

### Augmented Grammar

Add new start production `S' → S` to signal acceptance. Accept only when reducing by `S' → S`.

### CLOSURE(I)

Expand item set by adding items for every non-terminal whose dot is before it:

```
Algorithm CLOSURE(I):
  J = I
  repeat:
    for each item A → α•Bβ in J:
      for each production B → γ:
        if B → •γ not in J: add B → •γ to J
  until no new items added
  return J
```

**Intuition:** `A → α•Bβ` means we expect something derivable from Bβ; so we must also consider all ways B can start.

### GOTO(I, X)

```
GOTO(I, X) = CLOSURE({ A → αX•β | A → α•Xβ ∈ I })
```

Represents the state you go to after reading symbol X from state I.

### Kernel vs Non-Kernel Items

- **Kernel items:** Dot NOT at start (plus `S' → •S`) — define state identity
- **Non-kernel items:** Dot at start — added by CLOSURE; not stored for state comparison

### Building the Canonical LR(0) Collection

```
C = {CLOSURE({S' → •S})}
repeat:
  for each set I in C and each symbol X:
    if GOTO(I, X) ≠ ∅ and not already in C:
      add GOTO(I, X) to C
```

---

## 5. SLR(1) Parsing

> **SLR (Simple LR):** Uses LR(0) items + **FOLLOW sets** to decide when to reduce.

### SLR Parsing Table Construction

Given LR(0) automaton with states I₀, I₁, ...:

**ACTION table:**

1. If `A → α•aβ ∈ Iᵢ` and `GOTO(Iᵢ, a) = Iⱼ`: `ACTION[i, a] = shift j`
2. If `A → α• ∈ Iᵢ` (A ≠ S'): for each `a ∈ FOLLOW(A)`: `ACTION[i, a] = reduce A → α`
3. If `S' → S• ∈ Iᵢ`: `ACTION[i, $] = accept`
4. Otherwise: error

**GOTO table:**

- If `GOTO(Iᵢ, A) = Iⱼ` for non-terminal A: `GOTO[i, A] = j`

### SLR Parsing Algorithm

```
s = initial state (push s₀ onto stack)
a = getNextToken()
loop:
    s = top of stack state
    if ACTION[s, a] = shift t:
        push t; a = getNextToken()
    elif ACTION[s, a] = reduce A → β:
        pop |β| states from stack
        t = top of stack
        push GOTO[t, A]
        output production A → β
    elif ACTION[s, a] = accept:
        return success
    else:
        error()
```

### SLR Limitations

- Uses FOLLOW(A) for the entire grammar — too broad
- A grammar may not be SLR(1) even if it's unambiguous
- Example: some shift/reduce conflicts remain unresolved by FOLLOW sets alone
- **Solution:** Use more precise per-state lookahead → LR(1) or LALR(1)

---

## 6. LR(1) Parsing (Canonical LR)

### LR(1) Items

An **LR(1) item** is a pair: `[A → α•β, a]`

- `A → α•β` is an LR(0) item (the core)
- `a` is a **lookahead terminal** (the terminal that may follow A when this is reduced)

The lookahead is used **only with reduce items** (`A → α•, a`): reduce only when input is `a`.

### CLOSURE for LR(1)

```
If [A → α•Bβ, a] ∈ CLOSURE(I):
  For each production B → γ:
    For each b ∈ FIRST(βa):  // lookahead for B's items
      Add [B → •γ, b] if not already present
```

### LR(1) Table Construction

- Same as SLR but reduce `A → α` only when lookahead `a` matches the item's lookahead
- `ACTION[i, a] = reduce A → α` only for `[A → α•, a]` items

**Power:** More grammars are LR(1) than SLR(1), but tables are much larger (states can be exponentially more)

---

## 7. LALR(1) Parsing

> **LALR (Look-Ahead LR):** Merge LR(1) states with the same **core** (same LR(0) items, ignoring lookaheads); combine lookahead sets.

### Why LALR?

- LR(1) has too many states (impractical for large grammars)
- LALR merges states with same core → much smaller tables
- Practically handles most real programming languages
- Used by: **YACC/Bison**, most parser generators

### LALR Construction

1. Build canonical LR(1) collection
2. Find all states with the same core (same set of LR(0) items)
3. Merge those states: combine their lookahead sets
4. Recheck for reduce/reduce conflicts (merge might introduce them)

### Comparison of LR Parsers

| Feature | SLR(1) | LALR(1) | LR(1) |
|---|---|---|---|
| States | Fewest (LR(0) states) | Same as SLR | Largest |
| Power (grammars handled) | Least | Middle | Most |
| Lookahead precision | Grammar-wide FOLLOW | Per-state merged | Per-state exact |
| Table size | Smallest | Same size as SLR | Largest |
| Used in practice | Rarely | **Yes (YACC/Bison)** | Rarely |
| Conflicts (shift/reduce) | Most likely | Fewer | Fewest |

### Grammar Class Hierarchy

```
Regular ⊂ LL(1) ⊂ SLR(1) ⊂ LALR(1) ⊂ LR(1) ⊂ LR(k) ⊂ CFG
```

---

## 8. Error Recovery in LR Parsers

### Panic Mode Recovery

- Pop states from stack until a state with a "synchronizing" non-terminal is found
- Shift tokens from input until one can legally follow that non-terminal
- Resume parsing

### Error Productions

- Add productions to grammar for common mistakes (e.g., missing semicolon)
- Parser generates diagnostic messages and continues

---

## 9. Semantic Analysis

### What is Semantic Analysis?

- **Syntax analysis** checks structure (CFG)
- **Semantic analysis** checks **meaning** — things CFG cannot enforce:
  - Type compatibility (`int a = "hello"` — structurally valid, semantically wrong)
  - Variable declared before use
  - Correct number of function arguments
  - Return type matches function declaration

### Semantic Errors

1. Type mismatch (assign float to int pointer)
2. Undeclared variable
3. Multiple declaration in same scope
4. Out-of-scope variable access
5. Actual/formal parameter mismatch
6. Reserved identifier misuse

### Semantic Analysis produces

- Symbol table annotations
- Type-annotated AST
- Error messages
- Intermediate representation (IR) for code generation

---

## 10. Syntax-Directed Definitions (SDD)

> An **SDD** is a CFG augmented with **attributes** attached to grammar symbols and **semantic rules** associated with productions.

```
SDD = CFG + attributes + semantic rules
```

### Attributes

- Each grammar symbol (terminal or non-terminal) can have attributes
- Attribute value holds semantic information (type, value, code string, etc.)

### Semantic Rules

Specify how attribute values are computed, associated with productions.

**Example — arithmetic expression evaluation:**

| Production | Semantic Rule |
|---|---|
| L → E n | print(E.val) |
| E → E₁ + T | E.val = E₁.val + T.val |
| E → T | E.val = T.val |
| T → T₁ * F | T.val = T₁.val * F.val |
| T → F | T.val = F.val |
| F → ( E ) | F.val = E.val |
| F → digit | F.val = digit.lexval |

**Example — infix to postfix translation:**

| Production | Semantic Rule |
|---|---|
| E → E₁ + T | E.code = E₁.code \|\| T.code \|\| '+' |
| T → T₁ * F | T.code = T₁.code \|\| F.code \|\| '*' |
| F → id | F.code = id.lexval |

---

## 11. Synthesized vs Inherited Attributes

### Synthesized Attributes

> **Synthesized** attribute of node N is computed from the attributes of its **children** (and N itself).

- Information flows **upward** (leaves → root)
- Can be computed in a **single bottom-up traversal**
- Both terminals and non-terminals can have synthesized attributes
- **SDD using only synthesized attributes = S-attributed SDD**

```
        E.val = 7
       / \
    E.val  +  T.val = 3
    = 4      /   \
            T.val  * F.val
            = 3     = 3
```

### Inherited Attributes

> **Inherited** attribute of node N is computed from its **parent** and/or **left siblings** (and N itself).

- Information flows **downward or sideways** (root → leaves)
- Only non-terminals can have inherited attributes
- Required for: passing type information in declarations, scope management

```
D → T L
T → int    T → float
L → L₁, id  | id
```

Here, `L.in = T.type` — the type is **inherited** down to the identifier list.

### Evaluation Order Summary

| Attribute Type | Computed from | Direction | Traversal |
|---|---|---|---|
| Synthesized | Children | Bottom-up | Post-order |
| Inherited | Parent/left siblings | Top-down or sideways | Pre-order (restricted) |

---

## 12. S-attributed and L-attributed SDDs

### S-attributed SDD

- Uses **only synthesized attributes**
- Evaluated during **bottom-up parsing** (or post-order traversal)
- Semantic actions placed at the **rightmost position** of RHS

### L-attributed SDD

- Uses synthesized attributes AND inherited attributes (with restriction)
- Restriction: inherited attribute of symbol Xⱼ in `A → X₁X₂...Xₙ` depends only on:
  - Attributes of X₁, X₂, ..., Xⱼ₋₁ (left siblings)
  - Inherited attributes of A (parent)
- Evaluated during **top-down parsing** (depth-first, left-to-right)
- Semantic actions can appear **anywhere** in the RHS

**Key relationship:**

```
S-attributed ⊂ L-attributed
(every S-attributed SDD is also L-attributed, but not vice versa)
```

---

## 13. Syntax-Directed Translation (SDT) Schemes

> An **SDT scheme** is a CFG with **semantic actions** (program fragments) embedded inside production bodies.

```
E → E + T   { printf("+"); }
E → E - T   { printf("-"); }
```

By convention, actions are enclosed in `{ }`.

### Action Execution Order

```
A → {Action1} B {Action2} C {Action3}
```

- `Action1` — before parsing B (before seeing B's input)
- `Action2` — after B, before C
- `Action3` — at reduction time (after seeing all of B and C)

### S-attributed SDT (Bottom-up)

- Actions appear at the **end** of the production body
- Executed at reduction time

```
E → E₁ + T  { E.val = E₁.val + T.val }
```

### L-attributed SDT (Top-down)

- Actions can appear **anywhere** in the production body
- Executed during the depth-first, left-to-right traversal

---

## 14. Applications of SDT

| Application | Example |
|---|---|
| **Expression evaluation** | Compute numeric value of arithmetic expression |
| **Infix → Postfix** | `a+b*c` → `abc*+` |
| **AST construction** | Build syntax tree nodes during parse |
| **Type checking** | Propagate and check types |
| **Intermediate code generation** | Generate TAC or other IR |
| **Symbol table management** | Insert/lookup identifiers |

### Example — Postfix SDT

```
E  → E₁ + T  { print("+") }
E  → T
T  → T₁ * F  { print("*") }
T  → F
F  → ( E )
F  → id       { print(id.lexval) }
```

Parsing `a + b * c` with this SDT prints: `a b c * +`

---

## 15. Dependency Graphs

- A **dependency graph** shows how attribute values depend on each other
- Node for each attribute occurrence; edge from `b` to `c` if `c` depends on `b`
- Evaluation order = topological sort of dependency graph
- If there is a **cycle** in the dependency graph → no valid evaluation order → grammar is not well-defined for this attribute

---

## Summary

```
Bottom-Up Parsing:
  Shift-Reduce → LR family
  ├── LR(0) Items: A → α•β
  │     CLOSURE + GOTO → Canonical Collection → LR(0) automaton
  ├── SLR(1): ACTION uses FOLLOW sets; simplest; fewest grammars
  ├── LR(1): Per-item lookahead [A→α•β, a]; most powerful; largest tables
  └── LALR(1): Merge LR(1) states with same core; practical compromise
                Used by YACC/Bison; handles most PL grammars

Grammar Hierarchy: LL(1) ⊂ SLR ⊂ LALR ⊂ LR(1) ⊂ CFG

Syntax-Directed Translation:
  SDD = CFG + attributes + semantic rules
  SDT = CFG + semantic actions embedded in productions
  ├── Synthesized: computed from children (bottom-up)
  ├── Inherited: computed from parent/left-siblings (top-down)
  ├── S-attributed: only synthesized → bottom-up evaluation
  └── L-attributed: synthesized + restricted inherited → top-down
```

---

## Key Terms

| Term                       | Definition                                                              |
| -------------------------- | ----------------------------------------------------------------------- |
| Handle                     | String matching a production body, at top of stack; reduction candidate |
| LR(0) item                 | Production with a dot marking progress in parsing                       |
| CLOSURE                    | Expand item set by adding items for non-terminals after the dot         |
| GOTO(I, X)                 | New state after reading X from state I                                  |
| Canonical LR(0) collection | Full set of item states; basis for LR table construction                |
| SLR                        | Simple LR — uses FOLLOW sets for reduce decisions                       |
| LALR                       | Look-Ahead LR — merges LR(1) states with same core                      |
| LR(1) item                 | `[A→α•β, a]` — LR(0) item plus lookahead terminal                       |
| SDD                        | Syntax-Directed Definition: CFG + attributes + semantic rules           |
| SDT                        | Syntax-Directed Translation: CFG + embedded semantic actions            |
| Synthesized attribute      | Computed bottom-up from children's attributes                           |
| Inherited attribute        | Computed top-down from parent/left-sibling attributes                   |
| S-attributed               | SDD with only synthesized attributes                                    |
| L-attributed               | SDD with synthesized + restricted inherited attributes                  |
| Dependency graph           | Shows attribute computation dependencies; must be acyclic               |

---

# Unit 3: Implementation of Syntax-Directed Translation Schemes and Intermediate Code Generation

---

## 1. Why Intermediate Code?

### The Retargeting Problem

Without IR: m source languages × n target machines = **m×n compilers** (impractical)

With IR: **m front-ends** (source → IR) + **n back-ends** (IR → target) = m+n components

```
Source_1 ─┐                     ┌─ Machine_1
Source_2 ─┤→ [Front-ends] → IR →├─ Machine_2
Source_m ─┘                     └─ Machine_n
```

### Benefits of IR

1. **Retargeting:** Attach new back-end for new machine; front-end unchanged
2. **Machine-independent optimization:** Apply optimizations to IR before code generation
3. **Simplicity:** IR is simpler to transform than either source or machine code
4. **Portability:** Bytecode-style IR (JVM, LLVM IR) is platform-independent

### Classification of Intermediate Representations

| Dimension | High-Level | Low-Level |
|---|---|---|
| Examples | AST, DAG | TAC, SSA, LLVM IR, JVM bytecode |
| Closeness | Source language | Machine language |
| Suited for | Type checking, structure | Register allocation, instruction selection |

| Dimension | Graphical | Linear |
|---|---|---|
| Examples | Syntax Tree, DAG | TAC, SSA |
| Structure | Tree/Graph nodes | Sequence of instructions |

---

## 2. Directed Acyclic Graph (DAG)

### What is a DAG?

A **DAG (Directed Acyclic Graph)** for an expression is a variant of a syntax tree where **common subexpressions share a single node** rather than being replicated.

### DAG vs Syntax Tree

| Feature | Syntax Tree | DAG |
|---|---|---|
| Common subexpressions | Replicated — new subtree each time | **Shared** — single node with multiple parents |
| Space | More | Less |
| Common sub-expr identification | No | Yes |
| Optimization hint | No | Yes — calculate once, reuse |

### Construction Rule

When creating a node for `op(l, r)`:

- **Check:** Does an identical node already exist in the DAG?
  - **Yes:** Return existing node (no new node created)
  - **No:** Create a new node

### Example

Expression: `a + a * (b-c) + (b-c) * d`

```
Syntax Tree would duplicate (b-c) and a.
DAG:
        +
       / \
      +   *
     / \ / \
    a  * −  d
      /\  /\
     a  (b−c node, shared)
```

- Node `(b-c)` appears once, used twice (by `a*(b-c)` and `(b-c)*d`)
- TAC from DAG: `t1 = b-c`, `t2 = a*t1`, `t3 = t2+a`, `t4 = t1*d`, ... — no repeated computation of `b-c`

### Key Properties

- DAG has a **unique node for each distinct computed value**
- Identifies **common subexpressions** → reduces recomputation
- Reduces number of generated instructions

---

## 3. Three-Address Code (TAC)

### Definition

> **Three-Address Code (TAC)** is a sequence of instructions of the form `x = y op z`, where each instruction has at most **three addresses** (operands) and **one operator**.

- No built-up arithmetic expressions on RHS — expressions always broken into atomic steps
- Results stored in **compiler-generated temporaries** (t₁, t₂, t₃, ...)
- Resembles assembly language; suitable for optimization

### General Form

```
x = y op z     // binary operation
x = op y       // unary operation
x = y          // copy
goto L         // unconditional jump
if x goto L    // conditional jump
ifFalse x goto L
x = y[i]       // array read (indexed)
x[i] = y       // array write (indexed)
x = &y, x = *y, *x = y  // pointer operations
param x        // pass parameter
call p, n      // call procedure p with n params
return y       // return value
```

### TAC for Common Constructs

#### Arithmetic expression: `a = b * -c + b * -c`

```
t1 = -c
t2 = b * t1
t3 = -c          // or reuse t1 if optimized
t4 = b * t3
t5 = t2 + t4
a  = t5
```

#### If-then-else: `if (x > y) z = x; else z = y;`

```
if x > y goto L1
z = y
goto L2
L1: z = x
L2:
```

#### While loop: `while (a < b) a = a + 1;`

```
L1: t1 = a < b
    ifFalse t1 goto L2
    t2 = a + 1
    a = t2
    goto L1
L2:
```

#### For loop: `for (j=0; j<=10; j++) { a = a * (j*(b/c)); }`

```
j = 0
L1: t1 = j <= 10
    ifFalse t1 goto L2
    t2 = b / c
    t3 = j * t2
    t4 = a * t3
    a = t4
    t5 = j + 1
    j = t5
    goto L1
L2:
```

#### Function call (recursive): `fact(x)`

```
    if x == 0 goto L1
    t1 = x - 1
    param t1
    call fact, 1
    t2 = result
    t3 = t2 * x
    u = t3
    goto L2
L1: u = 1
L2: fact = u
    return fact
```

#### Array access: `x = y[i]`

```
t1 = 4 * i    // compute byte offset
t2 = y[t1]    // indexed load
x = t2
```

---

## 4. Data Structures for TAC

### 4.1 Quadruples

> A **quadruple** has four fields: `(op, arg1, arg2, result)`

| op | arg1 | arg2 | result |
|---|---|---|---|
| − | c | | t1 |
| * | b | t1 | t2 |
| − | c | | t3 |
| * | b | t3 | t4 |
| + | t2 | t4 | t5 |
| = | t5 | | a |

**Special cases:**

- `x = y[i]` → `(=[],  y, i, x)` — arg1=array, arg2=index
- `x[i] = y` → `([]=, x, i, y)` — arg1=array, arg2=index
- Unary ops: leave arg2 empty
- Copy `x = y`: op=`=`, arg1=`y`, arg2=empty, result=`x`

**Advantage:** Temporaries are explicit variables — **easy to move instructions** during optimization (references don't break)

### 4.2 Triples

> A **triple** has three fields: `(op, arg1, arg2)`. No explicit result field — result referenced by **instruction position number**.

```
Position | op  | arg1 | arg2
(1)      | −   | c    |
(2)      | *   | b    | (1)
(3)      | −   | c    |
(4)      | *   | b    | (3)
(5)      | +   | (2)  | (4)
(6)      | =   | a    | (5)
```

**Advantage:** No temporary variable names needed

**Disadvantage:** **Code immovability** — if an instruction moves (e.g., during optimization), all positional references must be updated → expensive

### 4.3 Indirect Triples

> **Indirect triples** use an **execution order list** that contains pointers to triples, rather than embedding instructions sequentially.

```
Execution list:      Triple table:
(1) → ptr to triple  (1): (−, c, )
(2) → ptr to triple  (2): (*, b, (1))
...                  ...
```

**Advantage over triples:** Moving an instruction only requires changing its position in the execution list — the triple itself (and references to it) don't change. **Best of both worlds.**

### Comparison

| Feature | Quadruple | Triple | Indirect Triple |
|---|---|---|---|
| Temporary names | Explicit | Implicit (position) | Implicit |
| Code movement | Easy | Hard | Easy |
| Memory | More (4 fields) | Less (3 fields) | Less triples + list |
| Optimization | Best | Poor | Good |

---

## 5. Static Single-Assignment (SSA) Form

### Definition

> **SSA form** is a variant of TAC where **every variable is assigned exactly once** (though it may be used multiple times).

```
// TAC (multiple assignments to same variable)
y = 1
y = 2       // unclear which y reaches x = y
x = y

// SSA form (each variable assigned once)
y₁ = 1
y₂ = 2
x₁ = y₂   // crystal clear: x uses y₂
```

- "Static" = the single-assignment property is a compile-time (static) analysis; variables are versioned by the compiler, not at runtime
- Used by: gcc, LLVM, Java HotSpot, MLIR

### Φ (Phi) Function

When control flow merges (e.g., after an if-else), multiple versions of a variable may reach a merge point. The **Φ-function** selects the correct version based on the path taken:

```
if(flag) x₁ = -1; else x₂ = 1;
x₃ = Φ(x₁, x₂)     // x₃ = x₁ if came through true branch; x₂ otherwise
y = x₃ * a
```

### SSA Examples

#### Simple loop: `while (x < 10) { y = y + x; x = x + 1; }`

```
x₁ = x₀          // before loop
y₁ = y₀
L1:
  x₂ = Φ(x₁, x₃)
  y₂ = Φ(y₁, y₃)
  ifFalse x₂ < 10 goto L2
  y₃ = y₂ + x₂
  x₃ = x₂ + 1
  goto L1
L2:
```

### Why SSA?

Without SSA: optimizations require iterative data-flow analysis, liveness analysis, alias checking.

With SSA: optimizations become **local, sparse, and single-pass**:

| Optimization | Without SSA | With SSA |
|---|---|---|
| Constant propagation | Iterative data flow | Direct substitution |
| Dead code elimination | Liveness analysis | Remove unused definitions |
| Common subexpression | Alias & flow checks | Operand comparison |
| Branch simplification | Hard | Trivial with Φ |

### SSA Benefits List

1. **Constant propagation** — `a = 3*4+5` treated as `a = 17`
2. **Dead-code elimination** — unused definitions removed
3. **Global value numbering** — detect duplicate computations
4. **Partial redundancy elimination** — remove computations done on some paths
5. **Strength reduction** — `a*2` → `a<<1`
6. **Register allocation** — cleaner liveness information

---

## 6. Boolean Expressions in TAC

### Short-Circuit (Lazy) Evaluation

Boolean expressions in control flow (`if`, `while`, `for`) use **short-circuit** semantics:

- `A && B`: evaluate A; if false, don't evaluate B
- `A || B`: evaluate A; if true, don't evaluate B

### Translation Pattern

**`if (a < b) stmt`:**

```
t1 = a < b
ifFalse t1 goto L_false
[stmt code]
L_false:
```

**`if (a < b || c > d) stmt`:**

```
t1 = a < b
if t1 goto L_true
t2 = c > d
ifFalse t2 goto L_false
L_true: [stmt code]
L_false:
```

---

## 7. Backpatching

> **Backpatching** is a technique to handle forward jumps in TAC generation where the jump target address is unknown when the jump instruction is emitted.

### Mechanism

- When generating a jump instruction with unknown target: leave the label **empty** (hole)
- Maintain a **patch list** (list of instructions needing this label)
- When the label is eventually determined: **fill in (backpatch)** all instructions in the list

### Functions

- `makelist(i)`: create a new list containing only instruction `i`
- `merge(p1, p2)`: combine two patch lists
- `backpatch(p, i)`: fill in instruction number `i` as the target for all instructions in list `p`

### Example: `if (B) S1 else S2`

```
1: evaluate condition B → e.g., "if x > y goto _"   (true list: {1})
2: goto _                                             (false list: {2})
   -- backpatch true list to here
3: [code for S1]
4: goto _                                             (next list: {4})
   -- backpatch false list to here
5: [code for S2]
   -- backpatch {4} to here (next statement)
```

---

## 8. Translation of Declarations

When processing variable declarations, the compiler:

1. Allocates storage (tracks `offset` in current symbol table)
2. Records type and width (size) in the symbol table
3. For structured types (arrays, records): computes total size

### Type Widths

- `int`: 4 bytes
- `float`: 8 bytes
- `array(n, T)`: n × width(T)
- `record`: sum of field widths (with alignment)

### SDT for Declarations

```
D → T id ;       { addtype(id.entry, T.type, T.width); }
T → int          { T.type = integer; T.width = 4; }
T → float        { T.type = float; T.width = 8; }
T → array[num] of T₁  { T.type = array(num.val, T₁.type); T.width = num.val * T₁.width; }
```

---

## 9. Translation of Array Accesses

For row-major multi-dimensional arrays, the address formula is:

```
A[i₁][i₂]...[iₖ]:
base + i₁*(d₂*d₃*...*dₖ*w) + i₂*(d₃*...*dₖ*w) + ... + iₖ*w
```

where `w` = element width, `dⱼ` = dimension j size.

TAC generated by the compiler handles these offset calculations explicitly using temporaries.

---

## 10. Translation of Type Expressions

### Type Checking with SDD

```
E → E₁ + E₂
  if E₁.type == int && E₂.type == int:
      E.type = int
  elif E₁.type == float || E₂.type == float:
      E.type = float   // type coercion
      (insert inttofloat cast if needed)
  else: type error
```

### Coercions

Generated automatically: `inttofloat(x)` instruction inserted when int used where float expected.

---

## Summary

```
Intermediate Code Generation:
│
├── IR Types
│   ├── DAG — graphical; identifies common subexpressions
│   ├── TAC — linear; at most 3 addresses per instruction
│   └── SSA — TAC + every variable assigned once + Φ functions
│
├── TAC Data Structures
│   ├── Quadruples (op, arg1, arg2, result) — easy optimization
│   ├── Triples (op, arg1, arg2) — position = result ref; hard to move
│   └── Indirect Triples — execution list + triple table; easy to move
│
├── TAC Constructs
│   ├── Assignment, Arithmetic, Copy
│   ├── Conditional/unconditional jump
│   ├── Array access, Pointer ops
│   └── Function call/return (param, call, return)
│
├── SSA Form
│   ├── Each variable assigned exactly once
│   ├── Φ-function at control flow merge points
│   └── Simplifies: constant prop, dead-code elim, CSE, register alloc
│
└── Backpatching
    ├── Leave jump targets as holes
    ├── Maintain patch lists
    └── Fill in when target becomes known
```

---

## Key Terms

| Term                 | Definition                                                               |
| -------------------- | ------------------------------------------------------------------------ |
| DAG                  | Directed Acyclic Graph — IR identifying common subexpressions            |
| TAC                  | Three-Address Code — IR with at most 3 operands per instruction          |
| Quadruple            | TAC representation with (op, arg1, arg2, result) — 4 fields              |
| Triple               | TAC representation with (op, arg1, arg2); result = position number       |
| Indirect Triple      | Triples accessed via execution order list; easy to reorder               |
| SSA                  | Static Single-Assignment — each variable defined exactly once            |
| Φ-function           | SSA merge function selecting the value from the taken control path       |
| Backpatching         | Technique to fill jump targets discovered after jump instruction emitted |
| Common subexpression | Same computation performed multiple times; DAG identifies these          |
| Temporary            | Compiler-generated variable (t₁, t₂, ...) holding intermediate results   |
| Front-end            | Compiler phases up to IR generation (lexer, parser, semantic, ICG)       |
| Back-end             | Compiler phases from IR to target code (optimization, code gen)          |

---

# Unit 4: Machine-Independent Code Optimization, Code Generation and Run-Time Environment

---

## 1. Overview of Code Optimization

### What is Optimization?

> **Code optimization** is a program transformation technique that improves the efficiency of generated code (less CPU, less memory, higher speed) **without changing the program's observable behavior**.

### Criteria for a Valid Optimization

1. **Semantics-preserving:** Must not change program output — correctness over performance
2. **Speed improvement:** Must improve average runtime
3. **Worth the effort:** Should not unreasonably increase compilation time

### Two Levels of Optimization

- **Local optimization:** Within a single basic block
- **Global optimization:** Across multiple basic blocks using data-flow analysis

### Techniques Overview

1. Dead Code Elimination
2. Constant Folding
3. Constant Propagation
4. Copy Propagation
5. Strength Reduction
6. Common Subexpression Elimination (CSE)
7. Packing Temporaries
8. Loop Optimizations (Code Motion, Induction Variables, Loop Unrolling)

---

## 2. Basic Blocks and Control Flow Graphs (CFG)

### Basic Block

> A **basic block** is a maximal sequence of consecutive TAC instructions where:
> - Control enters only at the **first instruction** (no jumps into the middle)
> - Control leaves only at the **last instruction** (no internal branches or halts)

### Leader Algorithm (Finding Basic Blocks)

**Step 1:** Identify **leaders** (first instruction of each basic block):

1. The first instruction is always a leader
2. Any instruction that is the **target of a jump** (conditional or unconditional) is a leader
3. Any instruction **immediately following** a conditional or unconditional jump is a leader

**Step 2:** Each basic block = leader → all instructions up to (but not including) next leader

### Control Flow Graph (CFG)

> A **CFG** is a directed graph where **nodes = basic blocks** and **edges = possible control flow** between blocks.

**Edge rules:**

- Add edge B → C if C's leader is the target of a jump at the end of B
- Add edge B → C if C immediately follows B and B doesn't end with an unconditional jump

**Special nodes:** Add `ENTRY` → first block and any block that can exit → `EXIT`

### Example

```
TAC:
1:  i = 0               ← Leader (rule 1)
2:  t1 = i < 10
3:  ifFalse t1 goto 7   
4:  a[i] = 0            ← Leader (rule 3, follows jump)
5:  i = i + 1
6:  goto 2
7:  print a             ← Leader (rule 2, target of goto)
```

Basic blocks: B1={1}, B2={2,3}, B3={4,5,6}, B4={7}

CFG edges: B1→B2, B2→B3 (fall through), B2→B4 (jump), B3→B2 (loop back)

### Importance of CFG

- Required for: reaching definitions, live variable analysis, available expressions
- Enables: dead code elimination, loop optimization, CSE, code motion
- Basis for all data-flow analysis

---

## 3. Data-Flow Analysis

### What is Data-Flow Analysis?

> **Data-flow analysis** derives information about how values flow through program execution paths — how variables are defined and used across basic blocks.

Two key analyses:

### 3.1 Reaching Definitions

> A definition `d` of variable `x` (instruction that assigns to `x`) **reaches** point `p` if there is a path from `d` to `p` with no other definition of `x` along the way.

- Used for: constant propagation, copy propagation, ud-chains (use-def chains)
- Computed as a forward data-flow analysis (information flows in program execution order)

**Equations:**

```
OUT[B] = GEN[B] ∪ (IN[B] − KILL[B])
IN[B]  = ∪ OUT[pred] for all predecessors pred of B
```

- `GEN[B]`: definitions generated within B not killed later in B
- `KILL[B]`: definitions killed in B (other definitions of same variable)

### 3.2 Live Variable Analysis

> A variable `x` is **live** at point `p` if its value at `p` may be used along some path from `p` to the end of the program.

- Used for: register allocation (don't need register for dead variable), dead-code elimination
- Computed as a **backward** data-flow analysis (information flows backward)

**Equations:**

```
IN[B]  = USE[B] ∪ (OUT[B] − DEF[B])
OUT[B] = ∪ IN[succ] for all successors succ of B
```

- `USE[B]`: variables used in B before any definition in B
- `DEF[B]`: variables defined in B before any use in B

### 3.3 Available Expressions

> An expression `x op y` is **available** at point `p` if every path from entry to `p` evaluates `x op y`, and after the last evaluation, neither `x` nor `y` is redefined.

- Used for: global CSE — if expression is available at a point, no need to recompute it
- Forward data-flow analysis

---

## 4. Local Optimization Techniques

### 4.1 Dead Code Elimination

> **Dead code**: code that is unreachable (never executed) or whose results are never used.

```
// Unreachable dead code:
return x;
y = x + 1;  // never reached

// Useless dead code (result never used):
t1 = a * b;   // t1 never referenced after this
x = c + d;
```

- Remove both types — saves memory and computation time
- Dead code in SSA: any variable with no uses is dead code (immediate)

### 4.2 Constant Folding

> **Constant folding**: evaluate constant expressions at **compile time**, not at runtime.

```
i = 30 * 20 * 10     →    i = 6000
b = (3 > 1)          →    b = true
s = "hello" + "world" →   s = "helloworld"
```

**Algebraic identities also apply:**

```
x * 0 = 0           x + 0 = x
x * 1 = x           a && false = false
a || true = true     0 / x = 0
```

**Caution:** Floating-point folding may alter rounding; division by zero must not be folded.

### 4.3 Constant Propagation

> If a variable is known to hold a **constant value**, replace uses of that variable with the constant.

```
x = 5
y = x + 3    →   y = 5 + 3   →  (after folding) y = 8
```

Best applied **together with constant folding** and dead-code elimination iteratively:

```
Constant Propagation → Constant Folding → Dead Code Elimination → (repeat)
```

### 4.4 Copy Propagation

> After a copy statement `u = v`, replace uses of `u` with `v` wherever safe.

```
x = y;
z = x + 1;    →    z = y + 1;    // x eliminated if no other uses
```

**When safe:** `x` not redefined, `y` not modified between assignment and use.

Copy propagation cleans up redundant copies introduced by other optimizations (major optimizations create copies; copy propagation removes them).

### 4.5 Strength Reduction

> Replace **expensive operations** with cheaper but equivalent ones.

| Before | After | Why |
|---|---|---|
| `a * 4` | `a << 2` | Shift cheaper than multiply |
| `a * 7` | `(a << 3) - a` | Shift + subtract cheaper than multiply |
| `a / 32768` | `a >> 15` | Shift cheaper than divide |
| `a * 2` | `a + a` | Addition cheaper than multiply |

Effectiveness depends on hardware architecture.

### 4.6 Common Subexpression Elimination (CSE)

> Identify identical expressions that are guaranteed to compute the same value; compute once, reuse.

```
// Before CSE:
t1 = 4 * i
t2 = a[t1]
t3 = 4 * i   // redundant — same as t1
t4 = b[t3]

// After CSE:
t1 = 4 * i
t2 = a[t1]
t4 = b[t1]   // reuse t1
```

Requires that the operands (`i` in this case) are **not modified** between the two computations.

### 4.7 Packing Temporaries

> Replace distinct temporaries with a single one if their **live ranges do not overlap**.

```
// Before:
t1 = a + b
print(t1)
t2 = c + d   // t1 is dead here; safe to use t1 again

// After:
t1 = a + b
print(t1)
t1 = c + d   // reuse t1
```

Reduces the number of temporaries → less register pressure.

---

## 5. Loop Optimization

> Loops are prime optimization targets because they execute repeatedly — even small improvements compound across iterations.

### 5.1 Loop-Invariant Code Motion

> **Loop-invariant computation**: an expression whose value **does not change** during loop execution (operands not modified in loop).

**Code Motion (Hoisting):** Move invariant computations **outside the loop** (into the preheader).

```
// Before:
while (i < n) {
    x = y * z;    // y and z don't change in loop — invariant!
    a[i] = x;
    i++;
}

// After code motion:
temp = y * z;
while (i < n) {
    a[i] = temp;
    i++;
}
```

**Effect:** Computation done once instead of N times.

### 5.2 Induction Variables

> An **induction variable** is a variable whose value changes by a constant amount (`c`) on each loop iteration: `x = x + c`.

**Example:**

```
// Before:
for i = 0 to 9:
    t1 = i * 4    // t1 = 0, 4, 8, 12, ... — derived induction variable
    a[t1] = 0
```

**Strength reduction on induction variables:**

```
// After strength reduction:
t1 = 0
for i = 0 to 9:
    a[t1] = 0
    t1 = t1 + 4  // increment by c=4 instead of multiply
```

Replace `i * 4` with an addition — strength reduction from multiply to add.

### 5.3 Loop Unrolling (Loop Unwinding)

> Duplicate the loop body multiple times to **reduce loop overhead** (condition checks, jumps, counter increments).

```
// Original (100 iterations):
for (i = 0; i < 100; i++)
    a[i] = 0;

// Unrolled 2x (50 iterations):
for (i = 0; i < 100; i += 2) {
    a[i] = 0;
    a[i+1] = 0;
}
```

**Jump reduction:** 1× unroll → 50% fewer loop-back jumps; 3× unroll → 75% fewer.

**Complete unrolling:** Eliminates all loop overhead (only valid when iteration count known at compile time):

```
a[0] = 0; a[1] = 0; a[2] = 0; ... a[9] = 0;  // for 10-iteration loop
```

**Trade-off:** Speed vs code size (space-time tradeoff)

- Advantages: faster execution, enables ILP (instruction-level parallelism)
- Disadvantages: increased binary size, increased register pressure

---

## 6. Run-Time Environments

### 6.1 What is a Run-Time Environment?

> The **run-time environment** is the infrastructure (data structures + services) maintained during program execution to implement high-level language abstractions on a target machine.

The compiler generates code that assumes this environment exists and cooperates with the OS to create it.

**Responsibilities:**

1. **Memory management:** Allocate stack, heap, static areas
2. **Variable access:** Locate local variables, global variables, handle scope
3. **Procedure linkage:** Calling conventions, return address management
4. **Parameter passing:** Call-by-value, call-by-reference, etc.
5. **OS interfaces:** I/O, system calls

---

### 6.2 Storage Organization

Run-time memory is organized as:

```
Low Address
┌──────────────────────────┐
│  Code (Target Machine)   │  Fixed size — known at compile time
├──────────────────────────┤
│  Static Data Segment     │  Global/static variables — known at compile time
├──────────────────────────┤
│  Heap                    │  Dynamic allocation (malloc/new) — grows upward ↑
│          ↕               │
│  (Free space)            │
│          ↕               │
│  Stack                   │  Activation records — grows downward ↓
└──────────────────────────┘
High Address
```

| Segment | Contents | Size known when? |
|---|---|---|
| **Code** | Executable machine instructions | Compile time |
| **Static** | Global/static initialized variables | Compile time |
| **Heap** | Dynamically allocated objects (malloc, new) | Run time |
| **Stack** | Activation records (local vars, params, return addr) | Run time |

### Stack vs Heap

| Feature | Stack | Heap |
|---|---|---|
| Structure | Linear (LIFO) | Hierarchical (any order) |
| Allocation | Compiler-managed (automatic) | Programmer-managed (malloc/free) or GC |
| Fragmentation | None | Possible |
| Scope | Local to functions | Global, flexible lifetime |
| Resizable | No | Yes |
| Speed | Faster | Slower |

---

### 6.3 Static vs Dynamic Allocation

**Static allocation:**

- Bound to memory at compile time; never changes
- No run-time support needed
- Limitations: size must be known at compile time; no recursion; no dynamic structures

**Dynamic allocation (Stack + Heap):**

- Stack: automatic; tied to function calls; LIFO management
- Heap: manual or garbage-collected; flexible lifetimes and sizes

---

### 6.4 Activation Trees

> An **activation tree** represents the dynamic calling relationships between procedure executions.

- **Activation:** One execution of a procedure
- **Root:** activation of `main`
- **Node A is parent of B:** A called B; B must finish before A does
- **Left-to-right ordering:** left node's activation completes before right node's begins

**Key traversal properties:**

1. Procedure calls = **preorder** traversal of activation tree
2. Procedure returns = **postorder** traversal
3. Flow of control = **depth-first** traversal
4. If control is at node N: all active (open) activations = path from root to N

```
main calls: readArray, quicksort(1,9)
quicksort(1,9) calls: partition(1,9), quicksort(1,3), quicksort(5,9)

Activation Tree:
            main
          /       \
    readArray   quicksort(1,9)
               /      |       \
       partition(1,9)  qs(1,3)  qs(5,9)
                      /   \
                   p(1,3) ...
```

---

### 6.5 Activation Record (Stack Frame)

> An **activation record** (also: stack frame / function call frame) is a block of memory pushed onto the run-time stack for each function invocation, containing all information needed for that call.

```
┌─────────────────────────┐  ← top of stack (current frame)
│   Temporaries           │  Compiler-generated temp values
├─────────────────────────┤
│   Local Variables       │  Variables local to this activation
├─────────────────────────┤
│   Saved Machine Status  │  PC, registers to restore on return
├─────────────────────────┤
│   Access Link           │  Pointer to enclosing scope's frame (for nested fns)
├─────────────────────────┤
│   Control Link          │  Pointer to caller's activation record
├─────────────────────────┤
│   Return Value          │  Space for value returned to caller
├─────────────────────────┤
│   Actual Parameters     │  Arguments passed by the caller
└─────────────────────────┘  ← base of this frame / top of previous frame
```

**Lifecycle:**

- Calling a function → **push** new activation record
- Returning from a function → **pop** current activation record

**Stack at any point in execution** = path from root to current node in activation tree (bottom = main's record, top = current function's record).

---

### 6.6 Parameter Passing Mechanisms

| Mechanism | Description | Effect on caller's variable |
|---|---|---|
| **Call-by-value** | Copy of actual parameter is passed | Not affected |
| **Call-by-reference** | Address of actual parameter passed | Caller's variable can be modified |
| **Call-by-result** | Result written back to caller on return | Assigned at return |
| **Call-by-value-result** | Copy in; write back on return | Assigned at return |
| **Call-by-name** | Expression re-evaluated on each use (Algol 60) | Complex; like macro substitution |

---

## 7. Code Generation

### Role of Code Generator

- Input: Optimized IR (TAC)
- Output: Target machine code (or assembly)
- Tasks: instruction selection, instruction ordering, register allocation

### Issues in Code Generation

1. **Correctness:** Generated code must produce same result as source
2. **Efficiency:** Use registers effectively; minimize memory accesses
3. **Register allocation:** Decide which values live in registers at each point
4. **Instruction selection:** Choose the best machine instruction sequence for each IR operation

---

### 7.1 Next-Use Information

> The **next use** of variable `x` at instruction `i` is the next instruction `j > i` that references `x`.

A variable is **live** at a point if it has a next use; **dead** if not.

**Algorithm (backward scan within basic block):**

```
Scan instructions from last to first:
  For instruction i: x = y op z
    Record: next-use[i][x], next-use[i][y], next-use[i][z]
    After instruction i:
      set x to "no next use" (just defined)
      set y, z to "has next use" (just referenced)
```

Used for: deciding when to free registers (variable with no next use → register can be reused).

---

### 7.2 Register Allocation

> **Register allocation** assigns variables/temporaries to machine registers to minimize memory loads/stores.

Since registers are scarce, some values must be **spilled** (written to memory) when all registers are occupied.

#### Graph Coloring Approach

1. Build **interference graph:** nodes = variables; edge between u and v if u and v are **live simultaneously** at some point
2. **k-coloring:** Try to color the graph with k colors (k = number of registers) such that no two adjacent nodes share a color
3. Each color = one register; node's color = register assigned to that variable
4. If k-coloring fails → **spill** a node (variable stored in memory instead of register):
   - Remove spilled node from graph, color the rest, then handle spills
   - Spill cost heuristic: spill the variable used least frequently (inside loops costs more)

**Register Interference Graph (RIG):** Two variables interfere if they are both live at the same program point.

---

### 7.3 Instruction Selection

Map each TAC instruction to one or more target machine instructions:

| TAC | Typical x86 Assembly |
|---|---|
| `x = y + z` | `mov eax, y` / `add eax, z` / `mov x, eax` |
| `x = y * 4` | `lea eax, [y*4]` (or `shl`) |
| `if x < y goto L` | `cmp x, y` / `jl L` |
| `x = a[i]` | `mov eax, [a + i*4]` |

Modern instruction selection uses **tree pattern matching** or **dynamic programming** (Ershov method) for optimal instruction sequences.

---

## 8. Summary Diagram

```
Unit 4 — Optimization, Code Generation, Run-Time Environment
│
├── Basic Blocks & CFG
│   ├── Leaders: first instr, jump targets, instructions after jumps
│   ├── CFG edges: from last instruction to next/target block
│   └── Used for: all data-flow analysis and optimization
│
├── Data-Flow Analysis
│   ├── Reaching Definitions (forward) — for constant/copy propagation
│   ├── Live Variable Analysis (backward) — for register allocation
│   └── Available Expressions (forward) — for global CSE
│
├── Local Optimizations (within one basic block)
│   ├── Dead Code Elimination
│   ├── Constant Folding → evaluate constants at compile time
│   ├── Constant Propagation → substitute known constants
│   ├── Copy Propagation → replace u with v after u = v
│   ├── Strength Reduction → expensive → cheap (multiply → shift)
│   ├── CSE → compute once, reuse
│   └── Packing Temporaries → merge non-overlapping live ranges
│
├── Loop Optimizations
│   ├── Code Motion → hoist invariant computations out of loop
│   ├── Induction Variable + Strength Reduction → multiply → add
│   └── Loop Unrolling → reduce loop overhead at cost of code size
│
├── Run-Time Environment
│   ├── Memory Layout: Code | Static | Heap ↑ ... ↓ Stack
│   ├── Activation Tree → dynamic call hierarchy
│   ├── Activation Record (Stack Frame):
│   │     params, return val, control link, access link,
│   │     machine status, local vars, temporaries
│   └── Parameter passing: value, reference, result, name
│
└── Code Generation
    ├── Next-Use Information → live/dead analysis for registers
    ├── Register Allocation → graph coloring; k registers = k colors
    └── Instruction Selection → TAC → target machine instructions
```

---

## Key Terms

| Term                 | Definition                                                             |
| -------------------- | ---------------------------------------------------------------------- |
| Basic block          | Maximal sequence of TAC instructions with single entry and single exit |
| Leader               | First instruction of a basic block                                     |
| CFG                  | Control Flow Graph — directed graph of basic blocks                    |
| Dead code            | Unreachable code or code whose results are never used                  |
| Constant folding     | Evaluate constant expressions at compile time                          |
| Constant propagation | Replace variable with its constant value                               |
| Copy propagation     | Replace `u` with `v` after `u = v`                                     |
| CSE                  | Common Subexpression Elimination — compute once, reuse                 |
| Strength reduction   | Replace expensive op with cheaper equivalent                           |
| Code motion          | Move loop-invariant code to before the loop                            |
| Induction variable   | Variable incremented/decremented by constant each iteration            |
| Loop unrolling       | Replicate loop body to reduce overhead                                 |
| Activation           | One execution of a procedure                                           |
| Activation tree      | Tree of all activations during a program run                           |
| Activation record    | Stack frame — memory block for one function invocation                 |
| Control link         | Pointer in activation record back to caller's frame                    |
| Access link          | Pointer to enclosing scope's frame (for nested functions)              |
| Reaching definition  | Definition of x that reaches point p with no redefinition between      |
| Live variable        | Variable whose current value may be used in the future                 |
| Register allocation  | Assigning variables to CPU registers to minimize memory access         |
| Graph coloring       | Register allocation algorithm — k colors = k registers                 |
| Spilling             | Storing variable in memory when no register is available               |
| Call-by-value        | Copy of argument passed; caller unaffected                             |
| Call-by-reference    | Address of argument passed; caller's variable modifiable               |