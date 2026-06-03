#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        if ((a % 2 != 0 && b % 2 != 0) || (a % 2 == 0 && b % 2 == 0) || (a == b))
            cout << "Bob" << endl;
        else 
            cout << "Alice" << endl;
    }

    return 0;
}
