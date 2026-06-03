#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
bool isnondecreasing(vector<int> &v)
{
    for(int i =1;i<v.size();i++)
    {
        if(v[i]<v[i-1])
        {
            return false;
        }
    }
    return true;
}
bool canrmv1elemnet(vector<int> &v)
{
    int n = v.size();
    vector<int > prefixgcd(n),gcd_suffix(n);
    prefixgcd[0] = v[0];
    for(int i =1;i<n;i++)
    {
        prefixgcd[i] = gcd(prefixgcd[i-1],v[i]);
    }
    gcd_suffix[n-1] = v[n-1];
    for(int i =n-2;i>=0;i--)
    {
        gcd_suffix[i] = gcd(gcd_suffix[i+1],v[i]);
    }
    for(int i =0;i<n;i++)
    {
        vector<int> temp;
        for(int j =0;j<n-1;j++)
        {
            if(j==0)
            {
                temp.push_back(v[j+1]);
            }
            else
            {
                int x=(j==i)?v[j+1]:v[j];
                int y=(j==i)?gcd_suffix[j+1]:prefixgcd[j-1];
                temp.push_back(gcd(x,y));
            }
        }
        if(isnondecreasing(temp))
        {
            return true;
        }
    }
    return false;
}


}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int  t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i =0;i<n;i++)
        {
            cin>>v[i];
        }
        if(canrmv1elemnet(v))
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
