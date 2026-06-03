#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int a,b;
    cin>>a>>b;
    int i=0;
    while(a<b)
    {
        a *= 3;
		b *= 2;
        i++;//++i hobe cause ghotona ghotbe aage

    }
    cout<<i<<endl;


    return 0;
}
