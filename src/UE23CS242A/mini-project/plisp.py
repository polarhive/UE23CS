# [UE23CS242A] mini-project
# lisp syntax validation
# license: MIT

# authors: [PES2UG23CS368] Nathan Matthew Paul
# authors: [PES2UG23CS371] Navneet Nayak

import ply.lex as lex
import ply.yacc as yacc
syntax_error = False # flag

# ---------------- Lexer -----------------
reserved = {
    'if': 'IF',
    'while': 'WHILE',
    'setq': 'SETQ',
    'true': 'TRUE',
    'false': 'FALSE'
}

tokens = [
    'LPAREN', 'RPAREN',
    'NUMBER', 'VARIABLE',
    'PLUS', 'MINUS', 'MULT', 'DIV'
] + list(reserved.values())

# token regex patterns
t_LPAREN = r'\('
t_RPAREN = r'\)'
t_PLUS = r'\+'
t_MINUS = r'-'
t_MULT = r'\*'
t_DIV = r'/'

# literals and reserved word tokens
def t_VARIABLE(t):
    r'[a-zA-Z_][a-zA-Z_0-9]*'
    t.type = reserved.get(t.value, 'VARIABLE')
    return t

def t_NUMBER(t):
    r'\d+'
    t.value = int(t.value)
    return t

# ignore tabs and whitespace in lisp
t_ignore = ' \t'

# invalid tokens
def t_error(t):
    print(f"Illegal character '{t.value[0]}' at line {t.lineno}")
    t.lexer.skip(1)

# build the lexer
lexer = lex.lex()

# ---------------- Parser -----------------
def p_program(p):
    '''program : statement
               | statement program'''
    pass

def p_statement_if(p): # if statement rule
    '''statement : LPAREN IF condition statement statement RPAREN
                    | LPAREN IF condition statement RPAREN '''
    pass

def p_statement_while(p): # while statement rule
    '''statement : LPAREN WHILE condition statement RPAREN'''
    pass

def p_statement_assign(p): # var assignment rule
    '''statement : LPAREN SETQ VARIABLE expression RPAREN'''
    pass

def p_condition(p):
    '''condition : expression
                 | TRUE
                 | FALSE'''
    pass

def p_expression(p):
    '''expression : VARIABLE
                  | NUMBER
                  | LPAREN operator expression expression RPAREN'''
    pass

def p_operator(p):
    '''operator : PLUS
                | MINUS
                | MULT
                | DIV'''
    pass

# rule for syntax errors (debugging at line no/pos)
def p_error(p):
    global syntax_error
    syntax_error = True
    if p: print(f"Syntax error at '{p.value}' (line {p.lineno}, position {p.lexpos})")
    else: print("Syntax error at EOF")

# build the parser
parser = yacc.yacc()

# tests
code_samples = [
    "(if true (setq x 10) (setq y 20))",       # valid if statement
    "(if (setq x 10) (setq y 20))",            # invalid if syntax

    "(while false (setq x (+ x 1)))",          # valid while statement
    "(while true setq x 10)",                  # invalid while syntax

    "(setq z (* 5 5))",                        # valid var assignment
    "(setq (+ x 10))"                          # invalid var assignment
]

def parse_input(code):

    parser.parse(code)
    if syntax_error: print("Rejected")
    else: print("Accepted")

# test each code sample
for i, code in enumerate(code_samples, start=1):
    syntax_error = False
    print(f"\n--- Sample {i} ---")
    print("Code:", code)

    print("\nTokens:")
    lexer.input(code)
    tokens = []
    for tok in lexer:
        tokens.append(tok)
        print(tok)

    print("\nParsing Result:")
    parse_input(code)

