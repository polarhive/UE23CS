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