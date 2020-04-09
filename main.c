#include <stdio.h>
#include<malloc.h>
#include <string.h>
#define rty 40
char *getstr() {
    char *ptr = (char *) malloc(1);
    char buf[81];
    int n, len = 0;
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
    char *buf = (char*) calloc(1000,1),*s = (char *) malloc(1);
    int len=0;
    *buf='4';
    *s = '\0';
        while (strcmp(buf," \n")) {
            buf=getstr();
            strcat(buf," \n");
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

char *skipallSpace(char *s){
    s=skipfirstSpace(s);
    strcat(s," ");
  char* pointer,*pointeR=s,*newS=(char*)calloc(strlen(s)+1,1),*pointerN=newS;
  int i=0,len=strlen(pointer),count=0,Bcount=0;
  if (strpbrk(s," ")==0) return s; else {
      //for (i = 0; i < len - 1; i++)
      while(*pointeR!='\0'){
          pointer = pointeR;
          count = 0;
          do {
              pointer++;
              count++;
              Bcount++;
         } while (*pointer != ' ');

              strncpy(pointerN, pointeR, count + 1);
          pointerN += count + 1;

          i = len-strlen(pointeR);
          pointeR += count;
          pointeR = skipfirstSpace(pointeR);
      }
      *pointerN='\0';
      char *t;
      t=newS + strlen(newS);
    // memset(t-1,'\0',1);
    memset(s,'\0',len);
    // newS = (char *) realloc(newS, (strlen(newS)-1));
      return newS;
  }
}
char* string_rty_byWidth(char * s, short int * words, char*new_string)
{ short int* moving_words=words,spaces=0,simbols=0,len=0,i=0,j=0;
    char *moving_s=s,*__SS__="                                                                        ";
    while (*moving_words!=0){
        spaces++;
        (simbols+=*moving_words) ;
        moving_words++;
    }
    //spaces--;
    len=simbols+spaces;
    int new_spaces = (rty-simbols)/spaces;
    int add_new_spaces = (rty-simbols)%spaces;
    strncat(new_string,moving_s,*words);
    moving_s+=(*words+1);
    strncat(new_string,__SS__,new_spaces+add_new_spaces);
    words++;
    for (i=0;i<spaces;i++)
    {
        strncat(new_string,moving_s,*words);
        moving_s+=(*words)+1;
        if(i!=spaces-1)strncat(new_string,__SS__,new_spaces);
        words++;
    }
    strcat(new_string,"\n");
    return new_string;
}


char * by_width(char *s)
{   s=skipallSpace(s);
    short int row=0, len=0 , i=0 , j=0, count=0 , *words=(short int*)calloc(41,sizeof(short int)) ;
    char* pointer , *flag=s , *pointeR=s , *newS=(char*)calloc(strlen(s)+1,1);
    while(strlen(pointeR) != 0) {
        len=strcspn(pointeR,"\n");

            if ((strpbrk(flag, " ") != 0) && (strpbrk(pointeR, " ") - flag < rty))

                for (i = 0; i < ((len / rty)+1); i++) {

                    pointer = pointeR;
                    pointeR += rty;
                    while (*pointeR != ' ')
                        pointeR--;

                    flag=strpbrk(flag,"\n");

                    if (flag<pointeR)
                        pointeR=flag;
                    flag= pointer

                    row = 0;

                    while (pointer != pointeR) {
                        count = 0;
                        while (*pointer != ' ') {
                            pointer++;
                            *pointer != ' ' ? count++ : row++;
                        }
                        if (pointeR != pointer) pointer++;
                        count++;
                        *words = count;
                        printf("%d ", *words);
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
flag = pointeR;

}
if(strpbrk(flag, " ") == 0) {

}


}
return newS;
}




int main() {
    char*  s="assd sddоa sdf lkgg gggggggg ggggggggggggggggggggg gpppppppp ppppppppppppppp pppppppp pppppppppppppppppppppgggggjsldkjfg assd sddia pppppppppppppppppppppgggggjsldkjfg\n assd sddiapppppppppppppppppppppgggggjsldkjfg assd sddia";
    printf("'%s'",by_width(getext()));

    return 0;
}
