#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<int> a(n);
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(i);
        }
        int mex = 0;
        set<int> f; // Corrected the declaration
        vector<int> b;
        for(auto i : a){
            if(s.find(mex-i) != s.end()){
                b.push_back(mex-i);
                s.erase(mex-i);
                f.insert(mex-i);
            }
            else{
                s.erase(mex);
                b.push_back(mex);
                f.insert(mex);
            }
            while(f.find(mex) != f.end()){
                mex++;
            }
        }
        for(auto i : b){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
        
}
