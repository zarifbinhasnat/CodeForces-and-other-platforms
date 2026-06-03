#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    while(t--) {
        int x, flag = 0;
        int c1 = 0, c2 = 0;
        cin >> x;
        string s1, s2;
        cin >> s1 >> s2;

        for(int i = 0; i < x; i++) {
            if (s1[i] == '1')
                c1++;
        }

        for(int i = 0; i < x; i++) {
            if (s2[i] == '1')
                c2++;
        }

        int d = abs(c1 - c2);  // Calculate the absolute difference in the count of '1's


       {
            for(int i = 0; i < x; i++) {
            if (s1[i] != s2[i])
            s1[i]=s2[i]
                flag++;
        }

if(flag%2 != 0)
    flag -=1;
       }

        int ans = d + flag/2;
        cout << ans << endl;
    }


    return 0;
}
