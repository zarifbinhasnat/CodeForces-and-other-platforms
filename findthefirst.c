#include<stdio.h>
int binarysearch(int ar[],int n,int x)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(ar[mid]==x)
        {
                if (mid == 0 || ar[mid - 1] != x) {
                    return mid;
                } else {
                    r = mid - 1;
                }
        
        }
        else if(ar[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return -1;
}
int main()
{
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n,q;
    scanf("%d %d",&n,&q);
    int ar[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    while(q--)
    {
        int x;
        scanf("%d",&x);
       printf("%d\n", binarysearch(ar,n,x));
    }
        
}