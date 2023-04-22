#include <stdio.h>
int gcd(int a,int b)
{
	while ((a!=0)&&(b!=0))
	{
		if (a>b) a = (a%b);
		else b = (b%a);
	}
	return (a+b);
}
int main()
{
	printf("%d\n",gcd(10,5));
	return 0;
}
