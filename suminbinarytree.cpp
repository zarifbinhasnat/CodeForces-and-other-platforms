#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    
int t;
cin>>t;
while(t--)
{
    long long n;
    cin>>n;
    int cnt=0;
    long long temp=n;
    while(n>=1)
    {
        n/=2;
         temp+=n;
    }
   
    cout<<temp<<endl;
}

    return 0;
}
