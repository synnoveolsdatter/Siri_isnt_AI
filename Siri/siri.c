#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "googleit.h"
#include "classify.h"
#include "types.h"

// TODO: TEST

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
        case COMMENT:
            srand(time(NULL));// initialise rand() function
            char* responses[] = {"You see, killbots have a preset kill limit. Knowing their weakness, I sent wave after wave of my own men at them until they reached their limit and shut down. -Zapp Brannigan, Futurama", "At the risk of sounding negative, no.", "Fry, it's been years since medical school, so remind me. Disemboweling in your species, fatal or non-fatal? -Zoidberg, Futurama", "I'm not sure I can do that..", "I'm so embarrassed, I wish eveyrone else was dead! -Bender, Futurama", "I'm not sure I understand.", "That is a possibility...", "Ok", "{insert neutral comment here}"};
            int res = rand() % (RAND_MAX / 9);
            printf("\n\n%s\n\n", responses[res]);// TODO: instead, make it choose random response from a list of responses
            break;
        default:
            google_it(p, (int)strlen(p.text));
            break;
    }
    return 0;
}
