#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin>>t;
    while(t--)
{
    int n;
    cin>>n;
    int j=1;
    for(int i=1;i<=7;i++)
    {
       j*=2;
    }
    if(j<=n)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}

    return 0;
}
