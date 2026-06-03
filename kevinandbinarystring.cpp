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
        string s;
        cin>>s;
        int x = -1;
        for (int i=0;i<s.size();i++)
        {if (s[i] == '0')
            {
                x = i;
                break;
            }
        }
    }


    return 0;
}
