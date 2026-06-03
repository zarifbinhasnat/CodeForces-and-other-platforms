#include<stdio.h>
void printtop(int n){
    if(n==0)
    {
        return;
    }
        printf("%d\n",n);

    printtop(n-1);
}
bool ispalindromeusingrecursion(char *s,int start,int end)
{
    if(start>=end)
    {
        return true;
    }
    if(s[start]!=s[end])
    {
        return false;
    }
    return ispalindromeusingrecursion(s,start+1,end-1);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char s[] = "madam";
    if(ispalindromeusingrecursion(s,0,4))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}