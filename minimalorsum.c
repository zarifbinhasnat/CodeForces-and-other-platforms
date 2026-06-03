#include<stdio.h>
#include<stdlib.h>
int leftmostBit(int n) {
    int shifts = 0;
    while (n > 1) {
        n = n >> 1;
        shifts++;
    }
    return 1 << shifts;
}
int main()
{

    int t ;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int ar[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
       int  sum=0;
        for(int i=0;i<n;i++)
        {
            int x=leftmostBit(ar[i]);
            sum+=x;
        }
        printf("%d\n",sum);


    }

}
