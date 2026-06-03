#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    
int a,b,x,y;
cin>>a>>b>>x>>y;
int d,j,i;
if (a>y)
d= a-y;
else
d= y-a;
if (b>x)
j=b-x;
else
j=x-b;
i = j+d;
cout<<i<<endl;


    return 0;
}
