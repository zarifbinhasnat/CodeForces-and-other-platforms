#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin>>t;
    while(t--)
    {
        int n,h;
        cin>>n>>h;
        vector<int >v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];

        }
sort(v.begin(), v.end(), greater<int>());
int temp=0;
int i;
int cnt=0;
for ( i=0;i<n;i++)
{
temp+=v[i%2];
cnt++;
if(temp>=h)
break;
} 
cout<<cnt<<endl  ;     
    }


    return 0;
}
