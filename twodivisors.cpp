#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    
int n;
cin>>n;
while(n--)
{
    int a ,b,z;
    cin>>a>>b;
    if (b%a ==0)
    z= (b*b)/a;
    else 
    z= a*b;
    cout<<z<<endl;

}

    return 0;
}
