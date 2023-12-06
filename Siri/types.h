#ifndef _TYPES_INCLUDE
#define _TYPES_INCLUDE 1
// prompt types
typedef enum {
    QUESTION,
    COMMENT,
    MATH
} ptype_t;

// prompt object structure
typedef struct {
    ptype_t type;
    char* text;
} prompt_t;

#endif
