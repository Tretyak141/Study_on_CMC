#include <stdio.h>
//3.48: b
//3.49: h

int main()
{
    int c;
    int last =  ' ';
    int cp = 0;
    int counterp = 0;
    int counterz = 0;
    while ((c=getchar())!= EOF && c!='.'){
        if ((c>'0')&&(c<='9')){
            cp = 1;
            printf("%c",c);
            counterp++;
        }
        else{
            if (cp==0){
                if (c=='0'){
                    cp = 1;
                    counterz++;
                    counterp++;
                }
                else{
                    if (last=='0'){
                        printf("%c",last);
                    }
                    printf("%c",c);
                }
            }
            else{
                if (c!='0'){
                    cp = 0;
                    if ((counterz==counterp)&&(last=='0')){
                        printf("%c",last);
                    }
                    counterz = 0;
                    counterp = 0;
                    printf("%c",c);

                }
                else{
                    if (counterz!=counterp){
                        printf("%c",c);
                        counterp++;
                        counterz++;
                    }
                }
            }
        }
        
        last = c;
    }
    if (last=='0'){
        if (counterz==counterp){
            printf("%c",last);
        }
    }
    printf("\n");
    return 0;
}