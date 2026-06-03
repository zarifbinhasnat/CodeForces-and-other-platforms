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
    while(t--)
    {
        int n;
        cin>>n;
   string s;
    cin>>s;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1] && s[i]=='1')
        {
            cout<<"NO"<<endl;
            goto end;
        }
        else cout<<"YES"<<endl;


    return 0;
}
