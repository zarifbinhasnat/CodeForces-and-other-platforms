#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
     int t;
    cin >> t;
    while (t--) {
        int p, l;
        cin >> p >> l;
        int perc = (l / p) * 100;  // Fix: Change '}' to ')'
        int perc2 = (l*100)/p;
        cout<<perc<<endl;
        cout<<perc2<<endl;
    }


    return 0;
}
