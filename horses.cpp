#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    vector<long long> v(4);
    for(int i=0;i<4;i++)
    {
        cin>>v[i];
    }
    int cnt=0;
    sort(v.begin(),v.end());
    for(int i=1;i<4;i++)
    {
        if(v[i]==v[i-1])
        cnt++;
    }
    cout<<cnt<<endl;



    return 0;
}
