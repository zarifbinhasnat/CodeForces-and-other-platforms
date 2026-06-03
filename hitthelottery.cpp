#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    
int n;
cin>>n;
int cnt = 0;
cnt += n/100;
n = n%100;
cnt += n/20;
n = n%20;
cnt += n/10;
n = n%10;
cnt += n/5;
n = n%5;
cnt += n/1;
cout<<cnt;

    return 0;
}
