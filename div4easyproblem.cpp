#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin>>a;
        int cnt = 0;
        int x = 1;
        while(a>0)
        {
            if(a-x>0)
            {
                a-=x;
                x++;
                cnt++;
            }
            
        }
                        cout << cnt << endl;

    }
    
}