#ifndef _TYPES_INCLUDE
#define _TYPES_INCLUDE 1
// prompt types
typedef enum {
    QUESTION,
    COMMENT,
    MATH
} ptype_t;

// prompt object structure
typedef struct prompt_t{
    ptype_t type;
    char* text;
} prompt_t;

typedef enum {// really just thought of all the operations I could lol
    ADD,
    SUB,
    MUL,
    DIV,
    SQRT,
    SQR,
    NUM,
    FACT// factorial
} operation_t;

typedef struct token_t {
    operation_t type;
    int val;
} token_t;

#endif
