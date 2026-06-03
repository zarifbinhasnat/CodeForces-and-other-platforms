#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
      string s, s1, s2;
    cin >> s;
if (n%2!=0)
    cout<<"No";

   else
   {
      

    // Resize s1 and s2 to accommodate the substrings
    s1.resize(n / 2);
    s2.resize(n / 2);

    // Copy the first half of s to s1
    for (int i = 0; i < n / 2; i++)
        s1[i] = s[i];

    // Copy the second half of s to s2
    for (int i = n / 2; i < n; i++)
        s2[i - n / 2] = s[i];

    if (s1 == s2)
        cout << "Yes";
    else
        cout << "No";

    return 0;
   }
}
