#include <bits/stdc++.h>
using namespace std;

 int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     long long t;
    cin >> t;
    while (t--)
    {
         long long n;
        cin >> n;
         long long a[n];
        for ( long long i = 0; i < n; i++)
            cin >> a[i];
         long long sum = 0;
        for ( long long i = 0; i < n; i++)
        {
            sum += a[i];
        }
        if (sum % n != 0)
        {
            cout << "NO" << endl;
        }
        else{
             long long req = sum/n;
             long long oddpos= (n+1)/2;
             long long evenpos= n-oddpos;
             long long ods=0,evs=0;
            for ( long long i = 0; i < n; i++)
            {
              if((i+1)%2==1)//hehehehhehe
              ods+=a[i];
              else
                evs+=a[i];
            }
            if(evs ==req*evenpos && ods==req*oddpos)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;

        }

    }
    return 0;
}