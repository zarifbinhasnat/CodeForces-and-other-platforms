#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    
int t;
cin>>t;
while(t--)
{
    int n,a,b;
    cin>>n>>a>>b;
    if((a==b && b==n) || a+b+2<=n)
    cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }

}
}
