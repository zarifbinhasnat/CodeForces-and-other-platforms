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
    while(t--)
    {
        int a;
        cin>>a;
        vector<int> v(a);
        for(int i=0;i<a;i++)
        {
            cin>>v[i];
        }
        unordered_map<int,int> m;
        for(int i=0;i<a;i++)
        {
            m[v[i]]++;
        }
        int count=0;
        for(int i =0;i<=a;i++)
        {
            if(m.find(2*v[i])!=m.end())
            {
                count+=m[v[i]]/2;
        }

    }

    }

    return 0;
}
