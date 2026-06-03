#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int count = 0, maxcount = 0;
    for(int i = 1; i < n; i++) {
        if(v[i] != v[i - 1])
            count++;
            if (count > maxcount)
                maxcount = count;

    }
    if (maxcount == 0)
        cout << 1 << endl;
    else    
    cout << maxcount +1<< endl;
    



    return 0;
}
