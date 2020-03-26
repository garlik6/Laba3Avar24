#include <stdio.h>
#include<malloc.h>
#include <string.h>

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
     memset(t-1,'\0',1);
      memset(s,'\0',len);
     // newS = (char *) realloc(newS, (strlen(newS)-1));
      return newS;
  }
}
char* string_80_byWidth(char * s, short int * words, char*new_string)
{ short int* moving_words=words,spaces=0,simbols=0,len=0,i=0,j=0;
    char *moving_s=s,*__SS__="                                                                        ";
    while (*moving_words!=0){
        spaces++;
        (simbols+=*moving_words) ;
        moving_words++;
    }
    spaces--;
    len=simbols+spaces;
    int new_spaces = (80-simbols)/spaces;
    int add_new_spaces = (80-simbols)%spaces;
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
    new_string+='\n';
    return new_string;
}
char * by_width(char *s)
{   s=skipallSpace(s);
    short int row=0, i=0 , count=0, *words=(short int*)calloc(41,sizeof(short int));
    char* pointer,*flag=s,*pointeR=s,*newS=(char*)calloc(strlen(s)+1,1);
    while(strlen(pointeR)!=0) {


            if ((strpbrk(flag, " ") != 0) && (strpbrk(pointeR, " ") - flag < 80))

                for (i = 0; i < strlen(s) / 80; i++) {

                    pointer = pointeR;
                    pointeR += 80;
                    row=0;

                    while (*pointeR != ' ')
                        pointeR--;

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

                    string_80_byWidth(flag,words,newS);

                    pointeR++;
                    flag=pointeR;

                }

    }
    return newS;
}




int main() {
  char*  s="assd sddоa sdf lkgg gggggggg ggggggggggggggggggggg gpppppppp ppppppppppppppp pppppppp pppppppppppppppppppppgggggjsldkjfg assd sddоa sdf lkgg gggggggg ggggggggggggggggggggg gpppppppp ppppppppppppppp pppppppp pppppppppppppppppppppgggggjsldkjfgassd sddоa sdf lkgg gggggggg ggggggggggggggggggggg gpppppppp ppppppppppppppp pppppppp pppppppppppppppppppppgggggjsldkjfgassd sddоa sdf lkgg gggggggg ggggggggggggggggggggg gpppppppp ppppppppppppppp pppppppp pppppppppppppppppppppgggggjsldkjfgassd sddоa sdf lkgg gggggggg ggggggggggggggggggggg gpppppppp ppppppppppppppp pppppppp pppppppppppppppppppppgggggjsldkjfg";
printf("'%s'",by_width(getstr()));
    return 0;
}
