#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     long long int t,n,k,a;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(n%k==0)
            cout<<n<<endl;
        else
        {
            a=n/k*k;
            cout<<min(n,a+k/2)<<endl;
        }
    }
    return 0;
}