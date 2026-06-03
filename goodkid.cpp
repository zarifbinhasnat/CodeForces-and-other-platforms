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
        int n;
        cin>>n;

        vector<int >v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        v.front() = v.front()+1;
        int sum = 1;
        for(int i=0;i<n;i++)
        {
            sum*=v[i];
        }
        cout<<sum<<endl;


    }
    


    return 0;
}
