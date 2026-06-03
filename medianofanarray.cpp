#include <iostream>
#include <fstream> // For file handling
#include <algorithm> // For sort
using namespace std;

int main() {
    int t;
    cin >> t; // Read number of test cases from input file
    while(t--) {
        int n;
        cin >> n; // Read size of array from input file
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i]; // Read array elements from input file
        }
        sort(a, a + n); // Sort array
        int c = 1, mid = (n % 2 == 0) ? n / 2 : n / 2 + 1;
        for(ll i=mid; i<n; i++){
            if(ar[i]==ar[mid-1]){
                c+=1;
        cout << c << endl; // Write frequency to output file
    }
   
    return 0;
}
