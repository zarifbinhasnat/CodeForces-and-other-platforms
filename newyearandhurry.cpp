#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n,k;
    cin>>n>>k;
    int temp = 240-k;
    int sum=0;
    int i=1;
    for (i=1;i<=n;i++)
    {
sum+=5*i;
if (sum>temp)
break;
    }
    cout<<i-1<<endl;



    return 0;
}
