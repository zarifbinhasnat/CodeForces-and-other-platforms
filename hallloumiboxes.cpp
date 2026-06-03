#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(is_sorted(a,a+n) || k>1)
        cout<<"yes"<<endl;
        else
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}
