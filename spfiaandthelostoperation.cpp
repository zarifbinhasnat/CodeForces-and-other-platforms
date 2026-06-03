#include<bits/stdc++.h>
using namespace std;
bool isvalid(vector<int> &v,vector<int> &a,vector<int> &b)
{unordered_map<int,int> mp;
    for(int value:b)
    {
        mp[value]++;
    }
    for(int i =0;i<v.size();i++)
    {
     if(v[i]!=a[i]){
        if(mp[a[i]]>0)
        {
            mp[a[i]]--;
        }else{
            return false;
        }
    }
}
    return true;
}
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
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i =0;i<n;i++)
        {
            cin>>v[i];
        }
        vector<int> a(n);
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
        }
        int m;
        cin>>m;
        vector<int> b(m);
        for(int i =0;i<m;i++)
        {
            cin>>b[i];
        }
        if(isvalid(v,a,b))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }


    return 0;
}
