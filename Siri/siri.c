#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "googleit.h"
#include "classify.h"
#include "types.h"

/*
*   CODE STRUCTURE:
*   Take data as input
*   Classify data; sort data into enum type
*   printf() a response, possibly google it
*
*   this code loosely follows NASA's C++ style guide, most notable features being 
*     - functions do one thing and one thing only (I'm allowing main to be an exception)
*     - always checking return values (yes, even printf()), voiding ones you don't care about.
*/

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

int findPtrs(unsigned int l, unsigned int r, char* t) {
    l = 0;
    r = 0;
    for (int i = 0; i < (int)strlen(t); i++) {
        if (rptr > lptr) continue; // I'm sure there's a much better way to break the loop, but I honestly can't think of it
        if (t[i] >= 48 && t[i] <= 57) {
            if (l == 0) l = i;
            if (l > 0 && r < i && (t[i - 1] < 48 || t[i - 1] > 57)) r = i;// third condition makes sure that both pointers dont point to the same number
        }
    }
    if (l == 0 || r == 0) return -1;
    return 0;
}

int trimTxt(unsigned int l, unsigned int r, prompt_t p) {
    if (*p == NULL) return -1;
    char new[(r - l) + 1] = {'\0'};
    for (unsigned int i = l; i < r; i++) new[i] = p.text[i];
    p.text = new;
    return 0;
}

int main(int argc, char* argv[]) {
    prompt_t p;
    if (argc > 1) {
        p.text = argv[1];
    } else {
        (void)printf("\n\n\aHello, I am absolutely Siri.\n");
        (void)printf(" >> ");
        {
            char inp[200];
            scanf("%[^\n]%*c", inp);// I want inp to go out of scope and be freed, thus the braces. 
            snprintf(p.text, sizeof(p.text), "%s", inp);// p.text = inp;
        }
    }
    classify(p);
    switch (p.type) {// i could just make classify return a ptype_t but i dont feel like that and i'm gonna be presenting this and this is easier to understand
        /*case MATH:
            unsigned int lptr = 0;
            unsigned int rptr = 0;
            if (findPtrs(lptr, rptr, p.text) < 0) {
                errno = 1;
                perror("Less than 2 numbers found. Attempting to shut down computer.");// hope they get a kick outta that one
            }
            break;*/
        case COMMENT:
            srand(time(NULL));// initialise rand() function
            char* responses[] = {"You see, killbots have a preset kill limit. Knowing their weakness, I sent wave after wave of my own men at them until they reached their limit and shut down. -Zapp Brannigan, Futurama", "At the risk of sounding negative, no.", "Fry, it's been years since medical school, so remind me. Disemboweling in your species, fatal or non-fatal? -Zoidberg, Futurama", "I'm not sure I can do that..", "I'm so embarrassed, I wish eveyrone else was dead! -Bender, Futurama", "I'm not sure I understand.", "That is a possibility...", "Ok", "{insert neutral comment here}"};
            int res = rand() % (RAND_MAX / 9);// the above line is filled with as many futurama quotes as I could think of
            (void)printf("\n\n%s\n\n", responses[res]);
            break;
        default:
            google_it(p, (int)strlen(p.text));
            break;
    }
    return 0;
}
