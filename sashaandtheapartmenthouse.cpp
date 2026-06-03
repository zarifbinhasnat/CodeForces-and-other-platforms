#include<bits/stdc++.h>
using namespace
std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        multiset<int> s;
        for(int i=0;i<n;i++)
        {
            if(abs(i -(n-1-i))<=k+1)
            {
                s.insert(a[i]);
            }
        }
        cout<<*s.rbegin()-*s.begin()<<endl;
    }
}