#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    vector<string> v(4);
    v[0]="I hate ";
    v[1]="I love ";
    v[2]="that ";
    v[3]="it ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<v[i%2];
        if(i!=n-1)
        cout<<v[2];
    }   
    cout<<v[3];
    return 0;
}
