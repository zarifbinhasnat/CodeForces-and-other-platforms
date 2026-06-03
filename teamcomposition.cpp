#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    #include <iostream>

    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
            cout << min(min(a, b), (a + b) / 4) << '\n';
    }               
    


    return 0;
}
