#ifndef _TYPES_INCLUDE
#define _TYPES_INCLUDE
// prompt types
enum ptype_t {
    QUESTION,
    COMMENT,
    MATH
};

// prompt object structure
typedef struct {
    ptype_t type,
    char* text
} prompt_t;

#endif