#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    if(n%2==0)
    {
        int sum=0;
        for(int i=1;i<n;i++)
        {
            sum+=v[i];
        }
        cout<<v[1]*v[1]+sum*sum<<endl;
    }
        else 
        {
            int sum=0;for(int i=2;i<n;i++)
        {
            sum+=v[i];
        }
        int l= v[0]+v[0];
        cout<<l*l+sum*sum<<endl;
        }

    return 0;
}
