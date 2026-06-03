#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n,l;
    cin >> n >> l;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    double max_dist = v[0] - 0;
    int maxi = 0;
    for(int i = 1; i < n; i++) {
        if(v[i] - v[i-1] > maxi) {
            maxi = v[i] - v[i-1];
        }
    }
    double f = max(double(maxi), double(l - v.back()));
    f/=2;
    f = max(f,max_dist);
        cout << fixed << setprecision(9) << f  << endl;


 

    return 0;
}
