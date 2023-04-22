#include <stdio.h>
int main()
{
 
 int c, p = ' ';
 int countMinus = 0, countPlus = 0 ,f = 0;
 while ( (c = getchar()) != EOF && c !='.' )
 {  
  if ((c == '+' && p == '-') || (c == '-' && p == '+'))            
   f = 1;
            
  if (c =='+')
   countPlus++;

  if (c =='-') 
            countMinus++;

        p = c;
 }

    printf("resminus = %d\n", countMinus);
    printf("resplus = %d\n", countPlus);

    if (f) printf("YES");
    else printf("NO");
    
    printf("\n");

 return 0;
}