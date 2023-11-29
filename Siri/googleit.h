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
#include <shellapi.h>
void google_it(const char* prompt, int pl) {// pl -> prompt_len
    char url[500] = "https://www.google.com/search?q=";
    for (int i = 0; i < pl; i++) {
        if (prompt[i]==32) url[(int)strlen(url)]='+' else url[(int)strlen(url)]=prompt[i];
    }
    printf("\nHere's what I found.\7\n");
    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
}
#else
void google_it(const char* prompt, int pl) {// pl -> prompt_len
    char url[500] = "open https://www.google.com/search?q=";
    for (int i = 0; i < pl; i++) {
        if (prompt[i]==32) url[(int)strlen(url)]='+' else url[(int)strlen(url)]=prompt[i];// USUALLY doesn't crash!
    }
    printf("\nHere's what I found.\7\n");
    system(url);// runs the command 'open' because i included it in the url variable
}
#endif