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
    {int a,b,c;
        cin>>a>>b>>c;
        int x = a+b+c;
        if (x%3 == 0&& x/3>= a && x/3>=b )
        {
            cout<<"YES"<<endl;
        }
        else
        {
                cout<<"NO"<<endl;
            }
        }


    return 0;
}
