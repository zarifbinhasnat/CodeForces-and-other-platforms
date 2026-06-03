#include<bits/stdc++.h>
using namespace std;
int print(int n)
{
    if(n==0)
    {
        return 0;
    }
    return print(n-1)+n;
cout<<n<<endl;}

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    
cout<<print(1000)<<endl;

    return 0;
}
