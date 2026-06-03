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
    while(t--){
    string s;
    cin>>s;
    int n=s.length();
    int count=1;
    for(int i=1;i<n;i++){
        if(s[i]<s[i-1]){
            count++;
        }//vul0101 e
    }
    cout<<count<<endl;
    }


    return 0;
}
