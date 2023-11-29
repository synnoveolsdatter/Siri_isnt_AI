#ifndef _STDLIB_H
#include <stdlib.h>
#endif
#ifndef _STRING_H
#include <string.h>
#endif
#ifndef _GOOGLING
#define _GOOGLING
#endif
#ifdef _WIN32
//TODO: ADD CODE AFTER COMPLETED USING ShellExecute(NULL, "open", "https://URL", NULL, NULL, SW_SHOWNORMAL) instead
#else
void google_it(const char* prompt, int pl) {// pl -> prompt_len
    char url[500] = "open https://www.google.com/search?q=";
    for (int i = 0; i < pl; i++) {
        if (prompt[i]==32) url[(int)strlen(url)]='+' else url[(int)strlen(url)]=prompt[i];// USUALLY doesn't crash!
    }
    system(url);// runs the command 'open' because i included it in the url variable
}
#endif