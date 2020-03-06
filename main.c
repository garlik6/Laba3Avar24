#include <stdio.h>
#include<malloc.h>
#include <string.h>


char *getstr() {
    char *ptr = (char *) malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';

    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            free(ptr);
            ptr = NULL;
            continue;
        }
        if (n == 0) scanf("%*c");
        else {
            len += strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strncat(ptr, buf, len);
        }
    } while (n > 0);
    return ptr;
}

char *Justify(char* str,unsigned int wantlen){
   unsigned int size=strlen(str);



}
int main() {
char * a;
    return 0;
}
