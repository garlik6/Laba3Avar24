#include <stdio.h>
#include<malloc.h>
#include <string.h>

typedef struct Word{
    char *word;
    unsigned int Length;
}Word;
//typedef struct Text {
//    Word *wor
//    unsigned int Length;
//}Text;
char *getstr() {
    char *ptr = (char *) malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';

    do {
        n = scanf("%5[^\n]", buf);
//        if (n < 0) {
//            free(ptr);
//            ptr = NULL;
//            continue;
//        }
        if (n == 0) scanf("%*c");
        else {
            len += strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strncat(ptr, buf, len);
        }
    } while (n > 0);
    return ptr;
}
char *skipfirstSpace(char *s)
{
    unsigned int k = strspn(s," \t");
    return s+k;
}

Word *trim(char *s,Word *Text) {
    char* Ns="/0";
    char * k;
    Word *pointeR=(Word*)malloc(sizeof(Word));
    char *pointer=pointeR->word;
    do {
        pointer=pointeR->word;
         k = strchr(s, ' ');
        pointeR->Length=strlen(s)-strlen(k);
        strncpy(pointer,s,pointeR->Length);
        s=k;
        pointeR++;
        pointeR=(Word*)malloc(sizeof(Word));
    } while(k!=NULL);
        return Text;
}

void output(int len, Word *Text)
{
    int i,j,*p;
    Word* pointer;
    pointer=Text;
    for (i=0;i<len;i++){
        printf("%d ",*(pointer->word));
        pointer++;
        printf("\n");
    }

}
int main() {
char * a;
Word *Text=(Word *) malloc(sizeof(Word));
Word W= {NULL,0};

trim(skipfirstSpace(getstr()),Text);
output(2,trim(skipfirstSpace(getstr()),Text));
    return 0;
}







//char *skipSpace(char *s,)
//{   //skiplastSpace(s);
//    skipfirstSpace(s);
//    return s;
//char *Justify(char **str,unsigned int wantlen){
//   unsigned int size=strlen(str),i=0;
//   char =str;
////   while (*sim != "\n") sim++;
////   while(*sim == " ") {
////       sim--;
////       i++;//колличество пробелов
////   }
//while (*sim==" "){
//    sim++;
//    i++;
//}
//    return str=(char *) realloc(sim,size+1-i);
//}