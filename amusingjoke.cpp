#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string t;
    string u;
    cin>>s>>t>>u;
    s+=t;
    sort(s.begin(),s.end());
    sort(u.begin(),u.end());
    if(s==u)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }


    return 0;
}

