#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> pieces(k);
        for (int i = 0; i < k; ++i) {
            cin >> pieces[i];
        }
        
        priority_queue<int> pq(pieces.begin(), pieces.end());
        int operations = 0;

        while (pq.top() > 1) {
            int largest = pq.top();
            pq.pop();
            pq.push(1);
            pq.push(largest - 1);
            ++operations;
        }

        // Merging operations (remaining pieces - 1)
        cout << operations + (pq.size() - 1) << endl;
    }

    return 0;
}
