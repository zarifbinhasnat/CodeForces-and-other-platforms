#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& v, int target) {
    int low = 0;
    int high = v.size() - 1;
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (v[mid] >= target) {
            result = mid;
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    
    return result;
}

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int n;
    cin >> n;
    vector<int> v(n); 
    for(int i = 0; i < n; ++i) {                       
        cin >> v[i];      
    }
    
    for(int i = 1; i < n; ++i) {                       
        v[i] += v[i - 1];  
    }
    
    int m;
    cin >> m;
    vector<int> f(m);
    for(int i = 0; i < m; ++i) {
        cin >> f[i];  
    }
    
    for(int i = 0; i < m; ++i) {
        int index = binarySearch(v, f[i]);
        if (index != -1) {
            cout << index + 1 << endl;
        } else {
            cout << n + 1 << endl; 
        }
    }
    
    return 0;
}
