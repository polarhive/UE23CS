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