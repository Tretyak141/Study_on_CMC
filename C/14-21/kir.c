#include <stdio.h>

int main(){
    int c;
    int ct=0,ch=0;
    while ((c=getchar())!= EOF && c!='.'){
        if (c=='t'){
            if (ct==0){
                ct = 1;
            }
            else{
                printf("%c",c);
                ct = 1;
                if (ch==1){
                    putchar('h');
                    ch=0;
                }
            }
        }
        if (c=='h'){
            if ((ct==1)){
                if (ch==0){
                    ch = 1;
                }
                else{
                    putchar('t');
                    printf("%c",c);
                    printf("%c",c);
                    ct = 0;
                    ch = 0;
                }
            }
            else{
                printf("%c",c);
                ch = 0;
                ct = 0;
            }
        }
        if (c=='e'){
            if ((ct==1)&&(ch==1)){
                ct = 0;
                ch = 0;
                continue;
            }
            else{
                if (ct==1){
                    ct = 0;
                    putchar('t');
                }
                printf("%c",c);
            }
        }
        if ((c!='e')&&(c!='h')&&(c!='t')){
            printf("%c",c);
        }
    }
    if (ct==1){
        if (ch==1){
            putchar('t');
            putchar('h');
        }
        else{
            putchar('t');
        }
    }
}