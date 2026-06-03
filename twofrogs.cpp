#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        if (a>b)
        {
            cout<<"YES"<<endl;
        }
        else if ((a ^ b) & 1) cout << "NO\n";
        else cout << "YES\n";
      
    }
}