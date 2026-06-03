#include<bits/stdc++.h>
using namespace std;

string toBinary(unsigned int n) {
    string r;
    while(n != 0) {
        r = ( n % 2 == 0 ? "0" : "1" ) + r;
        n /= 2;
    }
    return r;
}

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
string a,b;
cin>>a>>b;
for(int i=0;i<a.length();i++)
{
    if(a[i]==b[i])
    cout<<0;
    else
    cout<<1;
}   

    return 0;
}