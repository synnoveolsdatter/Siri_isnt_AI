#ifndef TYPES_INCLUDE
#define TYPES_INCLUDE
// prompt types
enum ptype_t {
    QUESTION,
    COMMENT,
    MATH,
    UNRECOGNISED
};

// prompt object structure
typedef struct {
    ptype_t type,
    char* text
} prompt_t;

#endif