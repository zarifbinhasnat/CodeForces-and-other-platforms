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
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<k;j++)
            {
                cout<<char(j+'a');
            }
        }
        cout<<"\n";
    }


    return 0;
}
