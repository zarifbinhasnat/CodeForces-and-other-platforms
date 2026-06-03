#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b;
        if(a>b)
        {
           c=(a-b)%10;
           cout<<c<<endl; 
        }
         if(a<b)
        {
           c=(b-a)%10;
           cout<<c<<endl; 
        }
    }


    return 0;
}
