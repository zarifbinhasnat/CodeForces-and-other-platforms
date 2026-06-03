#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int num   =  2*n;
    int ar[num];
    for (int i =0;i<num;i++)
    {
        cin>>ar[i];
    }
    sort (ar,ar+n);
    for (int i =0;i<n;i++)
    {
        if(abs(ar[i]-ar[i+n])>=x)
        continue;
        else 
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;

}