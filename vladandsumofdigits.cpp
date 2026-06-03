#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        int val = n; // Initialize val with n
        for(int i = 0; i < n; i++) {
            arr[i] = val--; // Decrement val after assigning its value to arr[i]
        }
        
        for(int i = 0; i < n; i++) {
            if(arr[i] >= 10) {
                int sum = 0;
                int temp = arr[i];
                while(temp != 0) {
                    sum += temp % 10;
                    temp /= 10;
                }
                arr[i] = sum;
            }
        }
        
        int s = 0; // Initialize s to 0
        for(int i = 0; i < n; i++) {
            s += arr[i];
        }
        cout << s << endl;
    }
    return 0;
}
