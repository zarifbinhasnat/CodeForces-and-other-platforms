#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,a,b,c;
        cin>>m>>a>>b>>c;
        if(a>m)
        a =m;
        if(b>m)
        b =m;
        if(a+b+c >=2*m)
        c = 2*m -(a+b);
        int ans = a+b+c;
        cout<<ans<<endl;

    }
}