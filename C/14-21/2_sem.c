#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double x;
    scanf("%d",&n);
    scanf("%lf",&x);
    double last,ans;
    last = sin(x);
    for (int i=1;i<n;i++){
        ans = sin(last) + ans;
        last = sin(last);
    }
    printf("%lf",ans);
    return 0;
}