#include <stdio.h>

char * reverseWords(char * s){
    char *p = &s[0], *q = &s[0];
    while (*q != '\0') {
        char *end = p;
        while (*q != ' ' && *q != '\0') {
            q++;
        }
        if (q != p) {
            end = q;
            q--;
        }
        while (q > p) {
            char tmp = *p;
            *p = *q;
            *q = tmp;
            q--;
            p++;
        }
        q = end;
        while (*q == ' ') {
            q++;
            p = q;
        }
    }
    return s;
}