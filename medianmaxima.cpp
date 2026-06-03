#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        int m=n/2 +1;
        cout<<s/m<<'\n';
    }


    return 0;
}
