#ifndef _TOKENIZE
#define _TOKENIZE 1

token_t* tokenize(char* t, unsigned int tlen) {
    token_t* ret = (token_t*)malloc((int)strlen(t));
    unsigned int curpos = 0;
    for (int i = 0; i < tlen; i++) {
        switch (t[i]) {
            case 33:
                ret[curpos].type = FACT; break;
            case 42:
                ret[curpos].type = MUL; break;
            case 43:
                ret[curpos].type = ADD; break;
            case 45:
                ret[curpos].type = SUB; break;
            case 47:
                ret[curpos].type = DIV; break;
            case 94:
                ret[curpos].type = SQR; break;
            default: continue;
        }
    }
    return ret;
}
#endif
