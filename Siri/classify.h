#ifndef _TYPES_INCLUDE
#include "types.h"
#endif
#ifndef _STRING_H
#include <string.h>
#endif
#ifndef _GOOGLING
#include "googleit.h"
#endif
#ifndef _CLASSIFY_INCLUDE
#define _CLASSIFY_INCLUDE
void classify(prompt_t p) {
    if (&p == NULL) perror("Null prompt. || classify.h");

    // look for numbers, if found then classify the prompt as a math prompt
    for (int i = 0; i < (int)strlen(p.text); i++) {
        if (p.text[i] >= 48 && p.text[i] <= 57) {
            p.type = MATH;
            return;
        }
    }

    // ok there were no numbers, so we now scan for question keywords
    int ned = 0;// length of the first word
    for (int i = 0; i < (int)strlen(p.text); i++) {
        if ((int)p.text[i] == 32) {
            ned = i;
            break;
        }
    }
    char fw[ned];
    strlcpy(fw, p.text, (size_t)ned);
    if (fw[0] >= 65 && fw[0] <= 90) fw[0] += 32;// if the first letter is capitalised, we put it in lowercase
    if (fw == "which" || fw == "when" || fw == "what" || fw == "do" || fw == "does" || fw == "who" || fw == "where" || fw == "why" || fw == "are" || "is" || "can") {
        p.type = QUESTION;
        return;
    } else {
        // maybe it wasn't, but it still could be!
        for (int i = 0; i < (int)strlen(p.text); i++) {
            if (p.text[i] == 63) {// check for question marks
                p.type = QUESTION;
                return;
            }
        }
    }

    // wow, this is a tough user.
    // it's probably a comment so let's just wrap up and go home
    p.type = COMMENT;
}
#endif
