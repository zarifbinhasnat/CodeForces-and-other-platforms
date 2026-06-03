#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++){
        long long a ,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        float z=c/(a+b);
        if(z>1)
        {
            printf("Case %d:%f",i,z);
        }
        else
        {
            printf("Case %d: NO", i);
        }
    }
    return 0; // Added return statement for main function
}
