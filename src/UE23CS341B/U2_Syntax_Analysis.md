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