#include <stdio.h>
#include <stdlib.h>
#include "googleit.h"
#include "classify.h"
#include "types.h"

/*
*   CODE STRUCTURE:
*   Take data as input
*   Classify data; sort data into enum type
*   printf() a response
*/

int main(int argc, char* argv[]) {
    prompt_t p;
    if (argc > 1) {
        p.text = argv[1];
    } else {
        printf("\n\n\aHello, I am absolutely Siri.\n");
        printf(" >> ");
        {
            char inp[200];
            scanf("%[^\n]%*c", inp);
            p.text = inp;
        }
    }
    classify(p);
    switch (p.type) {// i could just make classify return a ptype_t but i dont feel like that and i'm gonna be presenting this and this is easier to understand
        case QUESTION:
            googleit(p.text);
            break;
        case COMMENT:
            printf("\n\nok\n\n");// TODO: instead, make it choose random response from a list of responses
            break;
        case MATH:
            googleit(p.text);
            break;
        default:
            perror("Invalid Type. || siri.c");
            break;
    }
    return 0;
}