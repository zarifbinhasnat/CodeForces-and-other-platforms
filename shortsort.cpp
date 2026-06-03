#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        if(s[0]=='a'||s[1]=='b'||s[2]=='c')
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    


    return 0;
}
