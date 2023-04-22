#include <stdio.h>

void hanoi(int n, int k1, int k2, int k3)
{

  if (n==1) printf("Move from %d to %d \n", k1, k3);
  else
  {
    hanoi(n-1, k1, k3, k2);
    printf("Move from %d to %d \n", k1, k3);
    hanoi(n-1, k2, k1, k3);
  }
}

int main()
{

   hanoi(64,1,2,3);
   return 0;
}