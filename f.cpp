#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int a,b,ans,j,d;
    cin>>a>>b;
    if(b>a)
    {
         d= b-a;
     j =0;
    for (int i=1;i<=d;i++)
    {
j+=i;
    }
 ans = b-j;
    }
    else if (a>b)
    {
       d= a-b;
        j =0;
    for (int i=1;i<=d;i++)
    {
j+=i;
    }
 ans = a-j;

    }
cout<<ans<<endl;

    return 0;
}
