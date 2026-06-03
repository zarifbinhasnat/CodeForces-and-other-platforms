#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    int maxIndex = max_element(a.begin(), a.end()) - a.begin();
    while (maxIndex > 0) {
        swap(a[maxIndex], a[maxIndex - 1]);
        maxIndex--;
        cnt++;
    }

    int minIndex = min_element(a.begin(), a.end()) - a.begin();
    while (minIndex < n - 1) {
        swap(a[minIndex], a[minIndex+1 ]);
        minIndex++;
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}
