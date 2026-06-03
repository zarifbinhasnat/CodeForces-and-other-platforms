#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int count = 0;
        int scale = 1;
        vector<int> v;
        while (n > 0)
        {
            int rem = n % 10;
            if (rem != 0)
            {
                count++;
                v.push_back(rem * scale);
            }
            n = n / 10;
            scale *= 10;
        }
        cout << count << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }


    return 0;
}
