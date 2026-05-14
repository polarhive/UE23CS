# Compiler Design — PYQ Master Reference with Answers

**Source:** PES University ESA Papers (qp1–qp16) + CD_COP_Slides (Prof. Prakash C O)

**Papers span:** May 2017 – Jan–May 2024

**Course codes:** UE17CS351 / UE18CS351 / UE19CS351 / UE20CS353 / UE21CS341B

---

## Table of Contents

1. [Compiler Overview & Phases](#1-compiler-overview--phases)
2. [Lexical Analysis](#2-lexical-analysis)
3. [Syntax Analysis & Parsing](#3-syntax-analysis--parsing)
4. [Syntax-Directed Translation & Semantic Analysis](#4-syntax-directed-translation--semantic-analysis)
5. [Intermediate Code Generation](#5-intermediate-code-generation)
6. [Code Optimization & Data Flow Analysis](#6-code-optimization--data-flow-analysis)
7. [Runtime Storage Organization](#7-runtime-storage-organization)
8. [Code Generation & Target Code](#8-code-generation--target-code)

---

## 1. Compiler Overview & Phases

### Q1.1 Define Compiler. What are the phases of the Compiler? Explain with a neat diagram. Mention the input and output for each phase

**Answer:**

**Definition:** A compiler is a program that reads a source program written in one language (source language) and translates it into an equivalent program in another language (target language). An important role is to report errors in the source program detected during translation.

**Phases of a Compiler:**

The compilation process operates as a sequence of phases, each transforming one representation of the source program into another. There are two major parts:

- **Analysis Part (Front-end):** Breaks the source program into constituent pieces, imposes grammatical structure, creates an intermediate representation, and stores information in the symbol table.
- **Synthesis Part (Back-end):** Constructs the desired target program from the IR and symbol table information.

**Phases with inputs and outputs:**

| Phase | Input | Output |
|---|---|---|
| **1. Lexical Analysis (Scanner)** | Source character stream | Token stream |
| **2. Syntax Analysis (Parser)** | Token stream | Parse tree / Syntax tree |
| **3. Semantic Analysis** | Syntax tree + Symbol table | Annotated syntax tree |
| **4. Intermediate Code Generation** | Annotated syntax tree | Intermediate representation (e.g., TAC) |
| **5. Code Optimization** | IR | Optimized IR |
| **6. Code Generation** | Optimized IR | Target machine code |

**Example: `position = initial + rate * 60`**

1. **Lexical Analysis:** Produces tokens: `<id,1> <=> <id,2> <+> <id,3> <*> <60>`; enters identifiers into symbol table.
2. **Syntax Analysis:** Builds a syntax tree showing `=` at root, with `id(position)` on left and `+` subtree on right.
3. **Semantic Analysis:** Detects that `rate * 60` requires type coercion (`int→float`); inserts `inttofloat` node.
4. **IR Generation:** Produces TAC:

   ```
   t1 = inttofloat(60)
   t2 = id3 * t1
   t3 = id2 + t2
   id1 = t3
   ```

5. **Code Optimization:** Eliminates redundant conversion (60 → 60.0 at compile time), reduces to:

   ```
   t1 = id3 * 60.0
   id1 = id2 + t1
   ```

6. **Code Generation:** Produces target assembly:

   ```
   LDF  R2, id3
   MULF R2, R2, #60.0
   LDF  R1, id2
   ADDF R1, R1, R2
   STF  id1, R1
   ```

---

### Q1.2 Compiler vs Interpreter

**Answer:**

| Feature | Compiler | Interpreter |
|---|---|---|
| Translation | Translates entire source program at once | Executes source program statement by statement |
| Output | Produces a separate target program | No separate target program produced |
| Speed | Faster execution (machine code runs directly) | Slower (translates + executes each time) |
| Error Detection | Reports all errors after full scan | Reports error at the first erroneous statement |
| Examples | C, C++, Fortran compilers | Python, BASIC, MATLAB interpreters |

**Types of Compilers:**

1. **One-pass compiler:** Generates target code in a single pass through source.
2. **Multi-pass compiler:** Makes multiple passes for deeper analysis/optimization.
3. **Cross compiler:** Runs on one machine, generates code for another architecture.
4. **Native compiler:** Compiles for the same machine it runs on.
5. **Decompiler:** Translates from low-level to high-level language.

---

### Q1.3 Front-End and Back-End of a Compiler

**Answer:**

- **Front-End (Analysis):** Understands the source language. Comprises Lexical Analysis, Syntax Analysis, Semantic Analysis, and IR Generation. Machine-independent.
- **Back-End (Synthesis):** Maps to the target machine. Comprises Code Optimization and Code Generation. Machine-dependent.

**Why split?** A single front-end can be paired with multiple back-ends (retargeting). Multiple source languages can share one back-end via a common IR.

---

### Q1.4 Static vs Dynamic Scoping

**Answer:**

- **Static (Lexical) Scoping:** The scope of a variable is determined at compile time based on the textual structure of the program. A reference to a variable is resolved to the nearest enclosing declaration in the source code.
- **Dynamic Scoping:** Scope is determined at runtime based on the call stack. A variable refers to the most recently called procedure that has a binding for it.

**Example:**

```
BEGIN
  Boolean b := true;
  Procedure P;
  BEGIN Print(b); END;
  BEGIN
    Boolean b := false;
    Call P;
  END;
END;
```

- **Static scoping output:** `true` (P sees b declared in its textual enclosure)
- **Dynamic scoping output:** `false` (P sees b from the most recent caller's environment)

---

## 2. Lexical Analysis

### Q2.1 Role of a Lexical Analyzer

**Answer:**

The main tasks of the lexical analyzer are:

1. **Read** the input characters of the source program.
2. **Group** characters into meaningful sequences called **lexemes**.
3. **Produce** a sequence of tokens of the form `<token-name, attribute-value>` for each lexeme.
4. Send the token stream to the parser.
5. **Enter identifiers** into the symbol table.
6. Strip out **comments** and **whitespace**.
7. Correlate error messages with line numbers.

**Is Lexer language-dependent?** Yes.

- In Python, indentation defines block structure; the lexer emits INDENT/DEDENT tokens.
- In C++, `>>` can be a shift operator or two closing template brackets depending on context; the lexer needs parser feedback.
- In PL/I, keywords are not reserved; `IF` can be a variable name.

**Lexer vs Parser (why separate):**

1. **Simplicity of design:** Parser need not handle whitespace/comments.
2. **Efficiency:** Specialized buffering techniques speed up lexing.
3. **Portability:** Input-device-specific handling isolated in lexer.

---

### Q2.2 Tokens, Patterns, and Lexemes

**Answer:**

- **Token:** A pair `<token-name, attribute-value>`. The token-name is an abstract symbol (e.g., `id`, `num`, `relop`). Attribute-value points to symbol table for identifiers.
- **Pattern:** A description (regular expression) of the form lexemes may take. Example: `[a-zA-Z_][a-zA-Z0-9_]*` for identifiers.
- **Lexeme:** An actual sequence of characters matching a pattern. Example: `position`, `60`, `<=`.

**Token classes:** keywords, identifiers, literals/constants, operators, punctuation.

---

### Q2.3 Design of a Lexical Analyzer

**Answer:**

A lexical analyzer is built using:

1. **Regular definitions** to specify token patterns.
2. **NFA construction** (Thompson's construction) from regular expressions.
3. **NFA → DFA conversion** (subset construction algorithm).
4. **DFA minimization**.
5. The DFA is implemented as a **transition diagram** or a **table-driven program**.

**Diagram:**

```
Source Code → [Lexer / Scanner] → Token Stream → Parser
                     ↑↓
                 Symbol Table
```

The lexer uses two pointers:

- `lexemeBegin`: marks start of current lexeme.
- `forward`: scans ahead until a match.

---

### Q2.4 Input Buffering

**Answer:**

**Why needed?** Many tokens require look-ahead (e.g., `<`, `<=`, `<<` — cannot determine token until next char is seen). Reading char-by-char is slow.

**Buffer Pairs:**

- Two buffers of size N (typically 4096 bytes, one disk block) alternately reloaded.
- Two pointers: `lexemeBegin` (start of current lexeme) and `forward` (scans ahead).
- When `forward` reaches end of one buffer, reload the other and advance `forward`.

**Problem:** Each character advance requires checking if end of buffer has been reached.

**Sentinels:** Add a special character `eof` at the end of each buffer. This consolidates both buffer-end check and character-read into a single test:

```
switch *forward++ {
  case eof:
      if forward-1 is at end of buffer-1:
          reload buffer-2; forward = start of buffer-2;
      else if forward-1 is at end of buffer-2:
          reload buffer-1; forward = start of buffer-1;
      else: terminate (true EOF);
  case ...: // normal character processing
}
```

**Advantage:** Eliminates one check per character, speeding up scanning significantly. Only one test needed instead of two.

---

### Q2.5 Transition Diagrams

**Answer:**

A **transition diagram** is a directed graph where:

- **States** (circles) represent conditions during scanning.
- **Edges** (labeled with characters/character classes) represent transitions.
- **Start state** has an incoming "start" arrow.
- **Accepting states** (double circles) indicate a lexeme has been found; a `*` means retract `forward` by one position.

**Transition diagram for whitespace:**

```
State 0 --[blank|tab|newline]--> State 1 --[blank|tab|newline]--> State 1
State 1 --[other]--> State 2* (accept: ws token, do not return to parser)
```

**Transition diagram for identifiers:**

```
State 0 --[letter|_]--> State 1 --[letter|digit|_]--> State 1
State 1 --[other]--> State 2* (accept: id token)
```

**Transition diagram for relop (`<`, `<=`, `<>`, `=`, `>`, `>=`):**

```
State 0 --[<]--> State 1
State 1 --[=]--> State 2 (accept: LE)
State 1 --[>]--> State 3 (accept: NE)
State 1 --[other]--> State 4* (accept: LT)
State 0 --[=]--> State 5 (accept: EQ)
State 0 --[>]--> State 6
State 6 --[=]--> State 7 (accept: GE)
State 6 --[other]--> State 8* (accept: GT)
```

---

### Q2.6 Recognizing Keywords vs Identifiers

**Answer:**

Two approaches:

**Method 1 (Used in practice):** Install reserved words in the symbol table initially with their token types. When the scanner finds a lexeme, it looks it up in the symbol table. If found as a keyword, return that keyword token; otherwise return `id`.

**Method 2:** Create separate transition diagrams for each keyword. After recognizing an identifier, check if it matches a keyword pattern. Keywords take priority over identifiers.

---

### Q2.7 Lexical Errors

**Answer:**

A lexical error occurs when the lexer cannot recognize the next input character as the start of any valid token. Examples: `@` in Java, `#` where not expected.

**Handling:** The lexer can:

1. **Delete** the unrecognized character and continue.
2. **Insert** a missing character.
3. **Replace** a character with a correct one.
4. **Transpose** two adjacent characters.

The lexer alone cannot detect many errors (e.g., `fi` might be an undeclared function or misspelled `if`); these are passed to the parser/semantic analyzer.

**Sequence of lexemes for `while(i <= 10) { printf("%d",i); i++; }`:**

| Lexeme | Token |
|---|---|
| `while` | WHILE (keyword) |
| `(` | LPAREN |
| `i` | id |
| `<=` | LE (relop) |
| `10` | num |
| `)` | RPAREN |
| `{` | LBRACE |
| `printf` | id |
| `(` | LPAREN |
| `"%d"` | string_literal |
| `,` | COMMA |
| `i` | id |
| `)` | RPAREN |
| `;` | SEMICOLON |
| `i` | id |
| `++` | INC |
| `;` | SEMICOLON |
| `}` | RBRACE |

---

### Q2.8 LEX Tool

**Answer:**

**Lex/Flex** is a tool for generating lexical analyzers from a specification file.

**Three sections of a Lex specification:**

```
%{
  /* 1. Definitions section: C declarations, macro definitions */
  #include <stdio.h>
%}
%%
/* 2. Rules section: pattern { action } */
[0-9]+      { printf("NUMBER"); }
[a-zA-Z_]+  { printf("IDENT"); }
[ \t\n]     { /* skip whitespace */ }
%%
/* 3. User code section: helper functions */
int main() { yylex(); return 0; }
```

**Internally, Lex:** Regular Expressions → NFA (Thompson's construction) → DFA (subset construction) → Minimized DFA → C code (lex.yy.c) with table-driven DFA.

**Maximal Munch Rule:** The lexer always takes the longest possible match at any point. Conflicts between patterns are resolved by giving priority to the pattern listed first in the specification.

**Example with `a*b | ca | a*ca*` on input `abcaa`:**

- `ab` matches rule 1 (prints `1`)
- `c` matches... `ca` (2 chars)? Try: `ca` → matches rule 2 (prints `2`)
- `a` matches rule 1 (`a*b`? no `b` follows) — try rule 3: `a*ca*` on remaining — no. `a*b` — no. Defaults to rule 3 `a*` = `a` (prints `3`)... (work through maximal munch carefully for each input)

---

## 3. Syntax Analysis & Parsing

### Q3.1 Error Recovery Strategies

**Answer:**

**1. Panic Mode Recovery:**

- The parser discards input symbols one at a time until a **synchronizing token** (like `;`, `}`, `end`) is found.
- Simple to implement; may skip large portions of input without reporting further errors.
- May miss some errors.

**2. Phrase-Level (Statement Mode) Recovery:**

- The parser replaces a prefix of the remaining input with some string, allowing parsing to continue.
- Example: Replace a comma with a semicolon, insert a missing semicolon.
- More specific error recovery but complex to implement.

**3. Error Productions:**

- Add productions to the grammar that generate common erroneous constructs.
- If an error production is used, the parser generates a diagnostic warning but continues normally.

**4. Global Correction:**

- Find the minimum number of changes to the input to make it syntactically correct.
- Too expensive for practical use.

---

### Q3.2 Left Recursion Elimination

**Answer:**

A grammar is **left recursive** if it has a production `A → Aα | β`.

**Immediate left recursion elimination:**

Replace `A → Aα₁ | Aα₂ | ... | β₁ | β₂ | ...` with:

```
A  → β₁ A' | β₂ A' | ...
A' → α₁ A' | α₂ A' | ... | ε
```

**Example:** `E → E + T | T` becomes:

```
E  → T E'
E' → + T E' | ε
```

**Indirect left recursion:** First order the nonterminals, then eliminate direct left recursion for each, substituting to remove indirect recursion.

---

### Q3.3 Left Factoring

**Answer:**

When two productions share a common prefix, a predictive parser cannot choose between them on one token of lookahead. Left factoring defers the choice.

**General rule:** If `A → αβ₁ | αβ₂`, replace with:

```
A  → α A'
A' → β₁ | β₂
```

**Example:** `A → aAB | aBc | aAc` → factor out `a`:

```
A  → a A'
A' → AB | Bc | Ac
```

Further factoring `A'` (common prefix `A` in first and last): Not directly applicable. Apply again:

```
A' → AB | Ac | Bc
A  → a A'
A' → A(B | c) | Bc     →    A'' → B | c
So A' → A A'' | Bc
```

---

### Q3.4 FIRST and FOLLOW Sets

**Answer:**

**FIRST(α):** Set of terminals that begin strings derived from α. If α ⇒* ε, then ε ∈ FIRST(α).

**Rules for computing FIRST(X):**

- If X is terminal: FIRST(X) = {X}
- If X → ε: add ε to FIRST(X)
- If X → Y₁Y₂...Yₙ: add FIRST(Y₁) − {ε}; if Y₁ ⇒* ε, add FIRST(Y₂) − {ε}; etc.

**FOLLOW(A):** Set of terminals that can appear immediately to the right of A in some sentential form.

**Rules for computing FOLLOW(A):**

- FOLLOW(S) ∋ $ (where S is the start symbol)
- If A → αBβ: add FIRST(β) − {ε} to FOLLOW(B)
- If A → αB or A → αBβ where ε ∈ FIRST(β): add FOLLOW(A) to FOLLOW(B)

---

### Q3.5 LL(1) Parsing Table Construction & Worked Example

**Answer:**

**Construction:** For each production A → α:

1. For each terminal `a` in FIRST(α): add `A → α` to M[A, a]
2. If ε ∈ FIRST(α): for each terminal `b` in FOLLOW(A): add `A → α` to M[A, b]; if $ ∈ FOLLOW(A): add `A → α` to M[A, $]

**Worked example: Grammar `S → +SS | *SS | a`**

FIRST(S) = {+, *, a}, FOLLOW(S) = {+, *, a, $}

| | `+` | `*` | `a` | `$` |
|---|---|---|---|---|
| S | S → +SS | S → *SS | S → a | error |

**Grammar is LL(1)** — no conflicts.

**Parsing `+aa`:**

Stack (right = top): `$ S` | Input: `+ a a $`

- TOS = S, lookahead = `+` → use `S → +SS`, push `S S +`
- Stack: `$ S S +`, Input: `+ a a $`
- Match `+`: pop `+`
- Stack: `$ S S`, Input: `a a $`
- TOS = S, lookahead = `a` → use `S → a`, push `a`
- Match `a`
- Stack: `$ S`, Input: `a $`
- TOS = S, lookahead = `a` → use `S → a`, match `a`
- Stack: `$`, Input: `$` → **ACCEPT**

---

### Q3.6 LR(0) Automata and SLR Parsing

**Answer:**

**LR(0) Item:** A production with a dot indicating how far parsing has progressed. E.g., `A → α . β`.

**Algorithm:**

1. Augment grammar: add `S' → S`.
2. Compute CLOSURE of initial item set.
3. Compute GOTO(I, X) for each state I and symbol X.
4. Repeat until no new states found.

**SLR Parsing Table Construction:**

- If `[A → α . aβ]` in state i, and GOTO(i, a) = j: Action[i, a] = shift j
- If `[A → α .]` in state i: for each a in FOLLOW(A): Action[i, a] = reduce A → α
- If `[S' → S .]` in state i: Action[i, $] = accept

**Worked example: `S → SS+ | SS* | a`**

Augmented: `S' → S`

Items and states:

- I₀: { S' → .S, S → .SS+, S → .SS*, S → .a }
- GOTO(I₀, S) = I₁: { S' → S., S → S.S+, S → S.S*, S → .SS+, S → .SS*, S → .a }
- GOTO(I₀, a) = I₂: { S → a. }
- GOTO(I₁, S) = I₃: { S → SS.+, S → SS.* }
- GOTO(I₁, a) = I₂
- GOTO(I₃, +) = I₄: { S → SS+. }
- GOTO(I₃, *) = I₅: { S → SS*. }

**FOLLOW(S)** = {+, *, $}

SLR Table:

| State | a | + | * | $ | S |
|---|---|---|---|---|---|
| 0 | s2 | | | | 1 |
| 1 | s2 | | | acc | 3 |
| 2 | r(S→a) | r(S→a) | r(S→a) | r(S→a) | |
| 3 | s2 | s4 | s5 | | |
| 4 | r(S→SS+) | r(S→SS+) | r(S→SS+) | r(S→SS+) | |
| 5 | r(S→SS*) | r(S→SS*) | r(S→SS*) | r(S→SS*) | |

No conflicts → **grammar is SLR(1)**.

**Parsing `aa+`:**

| Stack | Input | Action |
|---|---|---|
| 0 | aa+$ | shift 2 |
| 0 2 | a+$ | reduce S→a |
| 0 1 | a+$ | shift 2 |
| 0 1 2 | +$ | reduce S→a |
| 0 1 3 | +$ | shift 4 |
| 0 1 3 4 | $ | reduce S→SS+ |
| 0 1 | $ | accept |

---

### Q3.7 Canonical LR(1) / CLR(1) Parsing

**Answer:**

**LR(1) Item:** `[A → α . β, a]` where `a` is the **lookahead** terminal.

**Why CLR(1) is more powerful than SLR:**

- SLR uses FOLLOW(A) as the lookahead set for all reduce items involving A — this is imprecise and may create conflicts.
- CLR uses the actual lookahead computed during item set construction, which is more precise. This allows CLR to parse grammars that SLR cannot (no spurious reduce-reduce conflicts from imprecise lookaheads).
- CLR generates a larger number of states than SLR, making it more memory-intensive but more powerful.

---

## 4. Syntax-Directed Translation & Semantic Analysis

### Q4.1 Synthesized vs Inherited Attributes

**Answer:**

**Synthesized Attribute:**

- Defined at a parse tree node N using attribute values of N's **children**.
- Information flows **upward** (bottom-up) in the parse tree.
- Can be evaluated in a single bottom-up traversal.
- A grammar with only synthesized attributes is called **S-attributed**.

**Example:** `E → E₁ + T { E.val = E₁.val + T.val }`

**Inherited Attribute:**

- Defined at a parse tree node N using attribute values of N's **parent** and/or **siblings**.
- Information flows **downward or sideways** in the parse tree.
- Only non-terminals can have inherited attributes.
- Cannot be evaluated by a simple pre-order traversal (except when not depending on right siblings).

**Example:** In `D → T L`, `L.inh = T.type` — type info flows from T down to L.

---

### Q4.2 S-Attributed vs L-Attributed SDT

**Answer:**

| | S-Attributed | L-Attributed |
|---|---|---|
| Attributes used | Only synthesized | Synthesized + inherited (from left siblings or parent) |
| Evaluation order | Bottom-up (single pass) | Depth-first, left-to-right |
| Semantic action placement | Only at end of production | Anywhere in production body |
| Suitable for | Bottom-up parsing | Top-down parsing (and bottom-up with restrictions) |

**Rule for L-attributed:** In production `A → X₁X₂...Xₙ`, the inherited attribute of `Xᵢ` can only depend on:

1. Inherited attributes of `A`
2. Synthesized or inherited attributes of `X₁, X₂, ..., Xᵢ₋₁` (left siblings)

Every S-attributed SDD is also L-attributed, but not vice versa.

---

### Q4.3 SDD for Type Declarations (Symbol Table)

**Answer:**

**Grammar:**

```
D → TL
T → int | float
L → L₁, id | id
```

**SDD (with inherited attribute L.in for type):**

| Production | Semantic Rules |
|---|---|
| D → TL | L.in = T.type |
| T → int | T.type = integer |
| T → float | T.type = float |
| L → L₁, id | L₁.in = L.in; addType(id.entry, L.in) |
| L → id | addType(id.entry, L.in) |

**SDT (L-attributed, suitable for top-down parsing):**

```
D → T { L.inh = T.type } L
T → int  { T.type = integer }
T → float { T.type = float }
L → { L₁.inh = L.inh } L₁ , id { addType(id.entry, L.inh) }
L → id   { addType(id.entry, L.inh) }
```

---

### Q4.4 SDD for While-Loop Intermediate Code

**Answer:**

**Production:** `S → while ( C ) S₁`

**SDD:**

| Production | Semantic Rules |
|---|---|
| S → while (C) S₁ | L1 = new(); L2 = new(); C.true = L2; C.false = S.next; S₁.next = L1; S.code = label\|\|L1\|\|C.code\|\|label\|\|L2\|\|S₁.code |

**Explanation:**

- L1: label at the beginning of the while condition (loop back target).
- L2: label at the beginning of S₁ body (taken when condition is true).
- If C is true → jump to L2 (execute body).
- If C is false → jump to S.next (exit loop).
- End of S₁ code jumps back to L1 (re-evaluate condition).

**SDT form:**

```
S → while ( { L1=new(); L2=new(); C.false=S.next; C.true=L2; } C )
           { S1.next=L1; } S1
    { S.code = label||L1||C.code||label||L2||S1.code }
```

**Generated code structure:**

```
L1: [code to evaluate C]
    if C.true goto L2
    goto S.next
L2: [code for S1]
    goto L1
```

---

### Q4.5 SDD for Do-While Loop

**Answer:**

**Production:** `S → do S₁ while ( C )`

| Production | Semantic Rules |
|---|---|
| S → do S₁ while (C) | L1 = new(); L2 = new(); S₁.next = L2; C.true = L1; C.false = S.next; S.code = label\|\|L1\|\|S₁.code\|\|label\|\|L2\|\|C.code |

**Generated code structure:**

```
L1: [code for S1]
L2: [code to evaluate C]
    if C.true goto L1
    goto S.next
```

---

### Q4.6 SDD for If-Else Statement

**Answer:**

**Production:** `S → if ( C ) S₁ else S₂`

| Production | Semantic Rules |
|---|---|
| S → if (C) S₁ else S₂ | L1=new(); L2=new(); C.true=L1; C.false=L2; S₁.next=S.next; S₂.next=S.next; S.code = C.code\|\|label\|\|L1\|\|S₁.code\|\|label\|\|L2\|\|S₂.code |

**Generated code:**

```
[code for C]
if C.true goto L1
goto L2
L1: [code for S1]
    goto S.next
L2: [code for S2]
```

---

### Q4.7 SDD for For-Loop

**Answer:**

**Production:** `S → for ( S₁ ; C ; S₃ ) S₄`

| Production | Semantic Rules |
|---|---|
| S → for(S₁;C;S₃)S₄ | L1=new(); L2=new(); L3=new(); S₁.next=L1; C.true=L2; C.false=S.next; S₄.next=L3; S₃.next=L1; S.code = S₁.code\|\|label\|\|L1\|\|C.code\|\|label\|\|L2\|\|S₄.code\|\|label\|\|L3\|\|S₃.code |

**Generated code:**

```
[code for S1 (init)]
L1: [code for C (condition)]
    if C.true goto L2
    goto S.next
L2: [code for S4 (body)]
L3: [code for S3 (increment)]
    goto L1
```

---

### Q4.8 SDD for Boolean Expressions (Short-Circuit)

**Answer:**

**B → B₁ || B₂:**

```
L1 = new()
B1.true  = B.true        // if B1 true → whole expression true
B1.false = L1            // if B1 false → evaluate B2
B2.true  = B.true
B2.false = B.false
B.code   = B1.code || label||L1 || B2.code
```

**B → B₁ && B₂:**

```
L1 = new()
B1.true  = L1            // if B1 true → evaluate B2
B1.false = B.false       // if B1 false → whole expression false
B2.true  = B.true
B2.false = B.false
B.code   = B1.code || label||L1 || B2.code
```

**B → !B₁:**

```
B1.true  = B.false
B1.false = B.true
B.code   = B1.code
```

---

### Q4.9 Binary to Decimal SDD (Translation Scheme)

**Answer:**

**Grammar:** `BN → L; L → L₁B | B; B → 0 | 1`

**Goal:** Compute `BN.val` = decimal equivalent of binary string.

**SDD:**

| Production | Semantic Rule |
|---|---|
| BN → L | BN.val = L.val |
| L → L₁B | L.val = L₁.val × 2 + B.val |
| L → B | L.val = B.val |
| B → 0 | B.val = 0 |
| B → 1 | B.val = 1 |

**Translation scheme (postfix SDT):**

```
BN → L   { BN.val = L.val }
L  → L₁B { L.val = L₁.val * 2 + B.val }
L  → B   { L.val = B.val }
B  → 0   { B.val = 0 }
B  → 1   { B.val = 1 }
```

**Annotated parse tree for `10111` (= 23):**

```
BN (val=23)
└── L (val=23)
    ├── L (val=11)
    │   ├── L (val=5)
    │   │   ├── L (val=2)
    │   │   │   ├── L (val=1)
    │   │   │   │   └── B (val=1) ← '1'
    │   │   │   └── B (val=0) ← '0'
    │   │   └── B (val=1) ← '1'
    │   └── B (val=1) ← '1'
    └── B (val=1) ← '1'
```

Calculation: L(1)=1, L(10)=1×2+0=2, L(101)=2×2+1=5, L(1011)=5×2+1=11, L(10111)=11×2+1=23.

---

### Q4.10 Dependency Graph

**Answer:**

A **dependency graph** depicts the dependencies between attribute instances at nodes of a parse tree. It is used to determine a valid evaluation order for attributes.

- Each node represents an **attribute instance** at a parse tree node.
- A directed edge from attribute `b` to attribute `c` (written `b → c`) means: "compute `b` before `c`" (c depends on b).
- A valid evaluation order is any topological sort of the dependency graph.
- If the dependency graph has a cycle, no valid evaluation order exists.

---

## 5. Intermediate Code Generation

### Q5.1 Syntax Tree vs DAG

**Answer:**

**Syntax Tree:** A tree where each interior node represents an operation and each leaf represents an operand. Common subexpressions are replicated.

**DAG (Directed Acyclic Graph):** Like a syntax tree but identifies and shares common subexpressions. A node with multiple parents represents a common subexpression appearing multiple times.

**Example: `((x+y) – ((x+y)*(x–y))) + ((x+y)*(x–y))`**

In a DAG, node for `(x+y)` is constructed once and shared; node for `(x–y)` is constructed once and shared; node for `(x+y)*(x–y)` is constructed once and shared.

**DAG construction:** Use a hash table. Before creating a node for `op(left, right)`, check if an identical node already exists; if so, return that node rather than creating a new one.

---

### Q5.2 Three-Address Code and Its Representations

**Answer:**

**Three-Address Code (TAC):** Each instruction has at most one operator on the right side and at most three operands (addresses). Form: `x = y op z`.

**For `x = y[i] + z[j]`:**

TAC:

```
t1 = i * w        (w = element width)
t2 = y[t1]
t3 = j * w
t4 = z[t3]
t5 = t2 + t4
x  = t5
```

**(Assuming w=4, simplified to addresses)**

**Quadruple Representation:** Each instruction is a 4-tuple `(op, arg1, arg2, result)`.

| Op | arg1 | arg2 | result |
|---|---|---|---|
| * | i | w | t1 |
| []= | y | t1 | t2 |
| * | j | w | t3 |
| []= | z | t3 | t4 |
| + | t2 | t4 | t5 |
| = | t5 | | x |

**Triple Representation:** Implicit result = instruction number. `(op, arg1, arg2)`. References use instruction numbers.

| # | Op | arg1 | arg2 |
|---|---|---|---|
| (1) | * | i | w |
| (2) | []= | y | (1) |
| (3) | * | j | w |
| (4) | []= | z | (3) |
| (5) | + | (2) | (4) |
| (6) | = | x | (5) |

**Indirect Triple:** A pointer array (instruction list) references triples. Allows reordering by rearranging pointers without changing the triple table.

---

### Q5.3 Static Single Assignment (SSA) Form

**Answer:**

**SSA:** An IR where every variable is assigned exactly once. When a variable is reassigned, a new version is created. At merge points in the CFG (join nodes), **φ-functions** are inserted to select the correct version.

**φ-function:** `x₃ = φ(x₁, x₂)` means "x₃ is either x₁ or x₂ depending on which path was taken."

**Benefits:** Simplifies many compiler optimizations (constant propagation, dead code elimination, register allocation).

**Example:**

```
Original:          SSA form:
x = u - t;         x₁ = u₁ - t₁
y = x * v;         y₁ = x₁ * v₁
if(y > 100)        if(y₁ > 100)
  x = y + w;         x₂ = y₁ + w₁
else               else
  x = y - w;         x₃ = y₁ - w₁
y = t - z;         x₄ = φ(x₂, x₃)
y = x * y;         y₂ = t₁ - z₁
                   y₃ = x₄ * y₂
```

**Φ-node placement motivation:** A φ-node is needed at a join point in the CFG when two different paths can reach that point with different definitions of the same variable. They are placed at the **dominance frontiers** of the blocks containing assignments to that variable.

---

### Q5.4 Basic Blocks and Flow Graphs

**Answer:**

**Basic Block:** A maximal sequence of consecutive three-address instructions such that:

1. Control can only enter through the first instruction (no jumps into the middle).
2. Control leaves only at the last instruction (no internal halts/branches).

**Leader detection rules:**

1. The first instruction is a leader.
2. Any target of a conditional/unconditional jump is a leader.
3. Any instruction immediately following a conditional/unconditional jump is a leader.

**Flow Graph (CFG):** A directed graph where:

- Nodes are basic blocks.
- Edges: block B → block C if C can immediately follow B (either B ends with a jump to C, or C immediately follows B and B doesn't end with an unconditional jump).

**Worked example (17-instruction program):**

Leaders: instructions 1, 2, 3 (target of jump at 11), 10, 12, 13 (target of jump at 17). Basic blocks:

- B1: {1}; B2: {2}; B3: {3–9}; B4: {10–11}; B5: {12}; B6: {13–17}

CFG edges: B1→B2, B2→B3, B3→B3 (self-loop via goto 3), B3→B4, B4→B3 (via goto 2 when true), B4→B5, B5→B3, B5→B6, B6→B2 (via goto 13), B6→exit.

---

## 6. Code Optimization & Data Flow Analysis

### Q6.1 Code Optimization Techniques

**Answer:**

**Criteria for optimization:**

1. Must be **semantics-preserving** (does not change program output/behavior).
2. Must **speed up programs** on average.
3. Should be **worth the effort** (not delay compilation excessively).

**Techniques:**

**1. Constant Folding:** Evaluate constant expressions at compile time.

- `i = 30 * 20 * 10` → `i = 6000`

**2. Constant Propagation:** Replace a variable known to be a constant with that constant value.

- `x = 5; y = x + 3` → `y = 8`

**3. Dead Code Elimination:** Remove code whose results are never used.

- If `x` is assigned but never read before reassignment, the assignment is dead.

**4. Copy Propagation:** After `u = v`, replace uses of `u` with `v` where safe.

- `u = v; x = u + 1` → `x = v + 1`

**5. Strength Reduction:** Replace expensive operations with cheaper equivalents.

- `x = y * 2` → `x = y + y` or `x = y << 1`

**6. Common Subexpression Elimination (CSE):** Compute a repeated expression once and reuse.

**7. Loop Invariant Code Motion:** Move computations that produce the same result on every iteration outside the loop.

**8. Induction Variable Elimination:** Replace multiplication in a loop by addition.

- `i = 0; L: t = 4*i; ...i = i+1; goto L` → `t = 0; L: ...t = t+4; goto L`

**9. Loop Unrolling:** Reduce loop overhead by replicating the loop body.

---

### Q6.2 Live Variable Analysis

**Answer:**

**Definitions:**

- **use[B]:** Set of variables used in B before any definition in B.
- **def[B]:** Set of variables defined in B before any use in B.
- **IN[B]:** Variables live on entry to block B.
- **OUT[B]:** Variables live on exit from block B.

**Equations:**

```
IN[EXIT] = ∅
IN[B]    = use[B] ∪ (OUT[B] − def[B])
OUT[B]   = ∪ {IN[S] | S is a successor of B}
```

**Algorithm:** Iterative backward analysis. Initialize all IN[B] = ∅. Repeatedly apply equations until fixed point (no changes).

**Example:**

Given CFG with blocks B1, B2, B3, B4, B5:

| Block | Instructions | use[B] | def[B] |
|---|---|---|---|
| B1 | x:=2 | {} | {x} |
| B2 | y:=4 | {} | {y} |
| B3 | x:=1 | {} | {x} |
| B4 | if(y>x) | {y,x} | {} |
| B5 | z:=y | {y} | {z} |

Iteratively compute IN and OUT working backwards from exit.

**Application:** Register allocation — two variables can share a register if they are not simultaneously live. Dead code elimination — if x is dead after `x = ...`, that assignment can be removed.

---

## 7. Runtime Storage Organization

### Q7.1 Structure of Activation Record

**Answer:**

An **activation record** (or stack frame) is a block of memory allocated on the runtime stack for a single execution (activation) of a procedure. It stores all information needed for that call.

**General Activation Record Layout (top to bottom on stack):**

```
┌─────────────────────┐ ← top of stack (sp)
│    Actual Parameters│  Arguments passed by caller
├─────────────────────┤
│    Return Value     │  Space for returned result
├─────────────────────┤
│    Control Link     │  Pointer to caller's activation record
├─────────────────────┤
│    Access Link      │  Pointer to enclosing procedure's AR (for nested procs)
├─────────────────────┤
│  Saved Machine      │  Saved registers, return address (PC)
│  Status             │
├─────────────────────┤
│    Local Data       │  Local variables of the procedure
├─────────────────────┤
│    Temporaries      │  Compiler-generated temporary values
└─────────────────────┘
```

**Fields explained:**

1. **Temporaries:** Intermediate results that can't be held in registers.
2. **Local Data:** Variables local to the procedure, not accessible outside.
3. **Saved Machine Status:** Return address (PC value), saved registers.
4. **Access Link (Static Link):** Points to the AR of the lexically enclosing procedure (for languages with nested procedures like Pascal, ML).
5. **Control Link (Dynamic Link):** Points to the AR of the calling procedure.
6. **Return Value:** Space for the function's return value (sometimes in register).
7. **Actual Parameters:** Arguments provided by the caller.

**Function calls and returns:**

- Calling a function **pushes** a new AR onto the stack.
- Returning from a function **pops** the current AR.

---

### Q7.2 Activation Tree

**Answer:**

An **activation tree** represents the hierarchy of all procedure activations during one execution of a program:

- Each **node** represents one activation (call) of a procedure.
- The **root** is the activation of `main`.
- Node `a` is the **parent** of node `b` if `a` calls `b` (control flows from `a` to `b`).
- Node `a` is to the **left** of node `b` if the lifetime of `a` occurs before the lifetime of `b`.

**Properties:**

- Sequence of calls = **pre-order** traversal
- Sequence of returns = **post-order** traversal
- Flow of control = **depth-first** traversal
- Currently live activations = nodes on the **path from root to the current node**

**Stack relationship:** The runtime stack holds activation records corresponding to the path from root to the current node in the activation tree. Stack top = current (deepest) activation.

**Example: `fib(3)` activation tree:**

```
main
└── fib(3)
    ├── fib(2)
    │   ├── fib(1) → returns 1
    │   └── fib(0) → returns 0
    └── fib(1) → returns 1
```

---

### Q7.3 Calling Sequence and Return Sequence

**Answer:**

**Calling Sequence** (code executed when a procedure is called):

**Caller's tasks:**

1. Evaluate actual parameters and place them in the beginning of the callee's AR.
2. Store the return address into callee's AR.
3. Store old value of `top_sp` into callee's AR (control link).
4. Increment `top_sp` past caller's local data, temporaries, and callee's parameters + status fields.

**Callee's tasks:**

5. Save register values and other status information.
6. Initialize local data and begin execution.

**Return Sequence:**

**Callee's tasks:**

1. Place return value next to the parameters (in callee's AR).
2. Restore `top_sp` and other registers using the machine-status field.
3. Branch to the return address.

**Caller's task:**

4. Access the return value (knows its location relative to current `top_sp`).

---

### Q7.4 Accessing Nonlocal Data — Access Links and Displays

**Answer:**

**Access Links (Static Links):**

- An **access link** in an AR of procedure `p` points to the AR of the lexically enclosing procedure.
- If `p` is at nesting depth `nₚ` and needs a variable from procedure `q` at depth `nq` (`nq < nₚ`):
  - Follow the access link `nₚ − nq` times to reach q's AR.
- Access links are needed for languages with nested procedures (ML, Pascal).

**Displays:**

- An auxiliary global array `d` where `d[i]` points to the highest AR on the stack for any procedure at nesting depth `i`.
- **Access:** To find variable in procedure at depth `i`, directly use `d[i]` → O(1) access.
- **On entry at depth `i`:** Save old `d[i]` in current AR; set `d[i]` to current AR.
- **On exit:** Restore `d[i]` from saved value.
- **Advantage over access links:** Constant-time access regardless of nesting depth.

| Feature | Access Links | Displays |
|---|---|---|
| Lookup cost | O(nesting depth difference) | O(1) constant |
| Maintenance cost | Variable | Constant |

**Data access in C (no nested procedures):**

- **Global constants:** Static addresses, compiled in.
- **Local variables:** Accessed via `top_sp` pointer with fixed offsets.

---

## 8. Code Generation & Target Code

### Q8.1 Issues in the Design of a Code Generator

**Answer:**

The five main issues:

**1. Input to the Code Generator:**

- The IR (three-address code, syntax tree, DAG, etc.) and symbol table information (addresses, types of variables).
- Assumes front-end has detected and reported all errors.

**2. Target Program:**

- Output can be: absolute machine code, relocatable machine code, or assembly language.
- Target machine architecture (RISC vs CISC) affects code generation strategy.

**3. Instruction Selection:**

- Mapping IR operations to target machine instructions.
- Complexity depends on: (a) level of IR, (b) ISA (instruction set architecture), (c) desired code quality.
- Naive translation produces correct but inefficient code (redundant loads/stores).
- Example: `a = a + 1` should use `INC a` if available, not three instructions.

**4. Register Allocation:**

- **Register allocation:** Deciding which variables to keep in registers at each program point.
- **Register assignment:** Choosing specific registers for those variables.
- Values in registers avoid memory accesses (faster). Registers are scarce.
- Problem is NP-complete in general; heuristics are used.
- Consider: next-use information (when is a value used next?), liveness (is the value needed after?).

**5. Evaluation Order (Instruction Ordering):**

- Order of computation affects efficiency (fewer registers may suffice with a good order).
- Picking the optimal order is NP-complete; compilers use heuristics.

---

### Q8.2 Static Allocation — Target Code Generation

**Answer:**

**Approach:** Each procedure has a fixed, pre-determined location for its activation record. No runtime stack management.

**Target machine instruction set:**

- `LD Rᵢ, M` — Load from memory location M into register Rᵢ
- `ST M, Rᵢ` — Store register Rᵢ into memory M
- `OP Rᵢ, Rⱼ, Rₖ` — Compute Rⱼ op Rₖ → Rᵢ

**Example (qp1):** `p()` code at 100, `q()` code at 300; AR for `p()` at 400, AR for `q()` at 600.

```
// Procedure p()
100: ACTION  m = 5        // code for: m = 5
     ST      400, #5      // store 5 into p's AR at offset for m
     LD      R1, #5       // load m
     MUL     R2, R1, #2   // n = m * 2
     ST      404, R2      // store n
     ST      600, #300    // save return address in q's AR
     GOTO    300          // call q
     HALT

// Procedure q()
300: LD      R1, 608      // load x
     MUL     R1, R1, #2   // x = 2 * x
     ST      608, R1      // store x
     GOTO *  (return addr in AR)  // return
```

---

### Q8.3 Register Allocation using Simple Code Generator

**Answer:**

**Descriptors:**

- **Register Descriptor:** For each register, tracks which variable(s) currently reside in it. Initially empty.
- **Address Descriptor:** For each variable, tracks all locations (registers and/or memory) where its current value resides. Initially: variable's memory location.

**getReg(I) algorithm:**

1. Return a free register if available.
2. If operand `y` is in register `R` and `R` only holds `y` and `y` is dead (no next use): return `R`, clear `y` from address descriptor.
3. Find register `R` whose value is needed after the longest time; spill (generate `ST M, R` for every M in R's address descriptor); return `R`.
4. If none: use memory location.

**After each instruction `x = y op z`:**

- Remove `x` from all register and address descriptors.
- Update register descriptor: register now holds `x`.
- Update address descriptor for `x`: `x` is in the register.
- If `y` or `z` are dead after this instruction and only in registers, free those registers.

**Worked Example: `x=y+z; z=x*x; y=z; x=y+z` (2 registers R1, R2; all variables live on exit)**

| TAC | Target Code | Reg Desc | Addr Desc |
|---|---|---|---|
| **start** | — | R1:∅, R2:∅ | x:mem, y:mem, z:mem |
| x=y+z | LD R1,y | R1:{y} | y:{R1} |
| | LD R2,z | R2:{z} | z:{R2} |
| | ADD R1,R1,R2 | R1:{x} | x:{R1} |
| z=x*x | MUL R2,R1,R1 | R2:{z} | z:{R2} |
| y=z | ST y,R2 | R2:{z} | y:{mem}, z:{R2} |
| x=y+z | ADD R1,R2,R2 | R1:{x} | x:{R1} |
| **exit** | ST x,R1 | | x:{R1,mem} |
| | ST z,R2 | | z:{R2,mem} |

**Note:** At exit, all live variables must be stored back to memory.

---

### Q8.4 Live Variable Analysis — Worked Example

**Answer:**

**Given CFG (typical exam question):**

```
B1: i=1; j=1       →  B2
B2: t1=10*i        →  B3
...
```

**Step 1: Compute use[B] and def[B] for each block.**

- **use[B]:** variables used before being defined in B.
- **def[B]:** variables defined before being used in B.

**Step 2: Initialize IN[B] = ∅ for all B; IN[EXIT] = ∅.**

**Step 3: Iteratively apply:**

```
OUT[B] = ∪ IN[succ(B)]
IN[B]  = use[B] ∪ (OUT[B] − def[B])
```

**Step 4: Repeat until convergence (no change in any IN or OUT).**

This is a **backward dataflow problem** — start from exit, propagate backwards.

**Key insight:** A variable is live at a point if there exists a path from that point to a use of the variable with no intervening assignment.

---

> **Note on image-based questions:** Several questions in qp2–qp15 include code fragments or flow graphs as images (not extractable as text). The answers above cover the methodology and worked examples. For specific image-based TAC/CFG optimization or live-variable problems, apply the algorithms described in sections 6.1 and 6.2 step by step.
