#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define rty 40
char *getstr() {
    char *ptr = (char *) malloc(1);
    char buf[81];
    unsigned int n, len = 0;
    *ptr = '\0';

    do {
        n = scanf("%5[^\n]", buf);
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

char *getext(){
    char *buf = (char*) malloc(1),*s = (char *) malloc(1);
    int len=0;
    *buf='\0';
    *s = '\0';
        while (strcmp(buf,"\n ") != 0) {
            buf=getstr();
            strcat(buf,"\n ");
            len += strlen(buf);
            s = (char *) realloc(s, len + 1);
            strcat(s,buf);

        }
    return s;
}

char *skipfirstSpace(char *s)
{
    unsigned int k = strspn(s," \t");
    return s+k;
}

char *skipallSpace_Long_words(char *s){
    s=skipfirstSpace(s);
    strcat(s," ");
  char* pointer,*pointeR=s,*newS=(char*)calloc(1000000,1),*pointerN=newS;
  int i=0,len=strlen(pointer),count=0,Bcount=0;
  int j;
  if (strpbrk(s," ")==0) return s; else {
      //for (i = 0; i < len - 1; i++)
      while(*pointeR!='\0'){
          pointer = pointeR;
          count = 0;
          do {
              pointer++;
              if(*pointer=='\t')
                  *pointer=' ';
              count++;
              Bcount++;
         } while (*pointer != ' ');

          if(count<=rty)
          {
              strncpy(pointerN, pointeR, count + 1);
              pointerN += count + 1;
              i = len-strlen(pointeR);
              pointeR += count;
              pointeR = skipfirstSpace(pointeR);
          }
          else {

              for(j=0;j<(count / rty);j++)
              {
                  strncpy(pointerN, pointeR, rty);
                  strcat(pointerN,"\n ");
                  pointerN+=2;
                  pointerN += rty;
                  pointeR+=rty;
              }
              strncpy(pointerN, pointeR, count + 1-rty);
              pointerN += count + 1-j*rty;
              pointeR += count-j*rty;
              pointeR = skipfirstSpace(pointeR);
          }



  }
      *pointerN='\0';
      char *t;
      t=newS + strlen(newS);
      free(s);
      newS=(char*)realloc(newS,strlen(newS)+1);
     return newS;
  }
}
char* string_rty_byWidth(char * s, short int * words, char*new_string)
{ short int* moving_words=words,spaces=0,simbols=0,len=0,i=0,j=0;
if(*words==0) return "\0";
    char *moving_s=s,*__SS__="                                                                        ";
    while (*moving_words!=0){
        spaces++;
        (simbols+=*moving_words) ;
        moving_words++;
    }
    if(spaces!=1) spaces--;
    len=simbols+spaces;
    int new_spaces = (rty-simbols)/spaces;
    int add_new_spaces = (rty-simbols)%spaces;
    for (i=0;i<spaces+1;i++)
    {
        strncat(new_string,moving_s,*words);
        moving_s+=(*words)+1;
        if(i!=spaces)
            strncat(new_string,__SS__,new_spaces);
        if(add_new_spaces>0)
            strncat(new_string,__SS__,1);
        add_new_spaces--;
        words++;
    }
    strcat(new_string,"\n");
    return new_string;
}


char * by_width(char *s)
{   printf("Processing...\n");
    s=skipallSpace_Long_words(s);
    short int row=0, len=0 , i=0 , j=0, count=0 , *words=(short int*)calloc(100000,sizeof(short int)) ;
    char* pointer , *flag=s , *pointeR=s , *newS=(char*)calloc(1000000,1);

    while(strlen(pointeR) != 0) {
        len=strcspn(pointeR,"\n");

            if (strpbrk(flag, " ") != 0)
                for (i = 0; i < ((len / rty)+1); i++) {
                    if (strpbrk(pointeR, " ") - flag < rty) {
                        pointer = pointeR;
                        if (strlen(pointeR) > rty)
                            pointeR += rty;
                        else
                            pointeR += strlen(pointeR);
                        while (*pointeR != ' ') {
                            pointeR--;

                            //                        if (*pointeR=='\0')
                            //                        {
                            //                            return newS;
                            //
                            //                        }
                        }

                        flag = strpbrk(flag, "\n");

                        if (flag < pointeR)
                            pointeR = flag;
                        flag = pointer;

                        row = 0;

                        while (pointer != pointeR) {
                            count = 0;
                            while ((*pointer != ' ') && (*pointer != '\n')) {
                                pointer++;
                                (*pointer != ' ') && (*pointer != '\n') ? count++ : row++;
                            }
                            if (pointeR != pointer) pointer++;
                            count++;
                            *words = count;
                            //printf("%d ", *words);
                            words++;
                        }

                        row++;
                        words -= row - 1;
                        string_rty_byWidth(flag, words, newS);

                        words += row - 1;
                        for (j = 0; j < row - 1; j++) {
                            *words = 0;
                            words--;
                        }
                        *words = 0;

                        pointeR++;
                        if (*pointeR == ' ') pointeR++;
                        flag = pointeR;

                    }
                    if(strcspn(flag, " ")>rty) {
                        *words=strcspn(flag, "\n");
                        string_rty_byWidth(flag,words,newS);
                        *words = 0;
                        pointeR+=strcspn(flag, "\n")+2;
                        flag=pointeR;

                    }
                }

}
    free(s);
    free(words);
    newS=(char*)realloc(newS,strlen(newS)+1);
return newS;
}




int main() {
    printf("your text:\n'\n%s'",by_width(getext()));
    return 0;
}
