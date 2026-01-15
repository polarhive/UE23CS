# UE23CS341B: Compiler Design

> Language design and implementation is an active topic in programming, and will likely always be. How we program and the tools we use, changes constantly. We try new ideas and come up with better or alternative approaches frequently. Any language that doesn‟t continue to adapt will fall into disuse, and any tool chain that remains stagnant will be forgotten. Hence knowledge of compilers in order to tweak these changes in the language design is a must for a Computer Science Engineer. This course requires the student to have a desirable knowledge of Data Structures and its Applications and Automata Formal Languages and Logic.

## Course Objectives

- Introduce the major concept areas of language translation and compiler design
- Develop a greater understanding of the issues involved in programming language design and implementation.
- Provide practical programming skills necessary for constructing a compiler. Develop an awareness of the function and complexity of modern compilers.
- Provide an understanding of the importance and techniques of optimizing code

## Course Outcomes

- Use the knowledge of patterns, tokens, and regex for solving the problems in the field of data mining
- Analyze and design the semantic behavior of a compiler. Choose the appropriate compiler internal representation for different kinds of compiler tasks.
- Translate a source-level language into a low-level compiler internal representation.
- Optimize the performance of a program in terms of speed and space using new code optimization techniques.

# Course Content

> **U1**: [[U1_Lexical_Analysis|Compilers: Introduction, Lexical Analysis, Top-down Parsers]]:

The Language Processing System, The Phases of a Compiler, The Grouping of Phases into Passes. Lexical Analysis: The Role of the Lexical Analyzer, Input Buffering, Specification of Tokens, Recognition of Tokens, Design of a Lexical Analyzer Generator. The role of the parser, Syntax Error Handling, and Error-Recovery Strategies. Top-down parsing: LL (1) Parser.

> **U2**: [[U2_Syntax_Analysis|Syntax Analysis: Bottom-up Parsers, Syntax-Directed Translation]]:

Bottom-up parsing: Shift-Reduce Parsing, viable prefixes, CLR, LALR, Error recovery for Bottom- up parsers Syntax- directed definitions, Evaluation orders for SDD‟s: S-attributed SDD, L-attributed SDD.

> **U3**: [[U3_IR_Generation|Implementation of Syntax Directed Translation Schemes and Intermediate Code Generation]]:

Applications of Syntax-Directed Translation - SDD for Syntax Trees, Expressions, Basic Types and flow control statements, Type Checking, Syntax-directed Translation Schemes – Parser Stack Implementation of Postfix SDT's, SDT's with actions inside Productions, SDT's for L-Attributed Definitions. Implementing L-Attributed SDD‟s: Bottom-Up Parsing. Variants ofSyntax Trees – Directed Acyclic Graphs for Expressions, Three-Address Code – Addresses and Instructions, Quadruples, Triples, Indirect Triples, SSA Form, Control Flow Graph.

> **U4**: [[U4_Code_Optimization|Machine Independent Code Optimization, Code Generation and Run Time]]

Machine Independent Optimization: Different Optimizations, Optimization of Basic Blocks. Data Flow Analysis: Live-variable analysis, Next-use algorithm. Storage Organization, Different Allocation Strategies, Stack Allocation of space, Access to Non-local Data on the stack. Code Generation: Issues in the design of a code generator, the target language, addresses in the target code, static allocation, stack allocation, run-time addresses for names. A Simple Code generator - The Code generation algorithm, Register allocation problem (Graph coloring)

---

prerequisites: [[AFLL|UE23CS342A]], [[DSA|UE23CS252A]]