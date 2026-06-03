#include<bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
long long power (long long base ,long long exp)
{
    long long res = 1;
    while(exp>0)
    {
        if(exp%2==1)
        {
            res = (res*base)%Mod;
        }
        base = (base*base)%Mod;
        exp/=2;
    }
    return res;
}
long long modInverse(long long n)
{
    return power(n,Mod-2);  
}
long long nCr(long long n,long long r)
{
    long long fact[n+1];
    fact[0] = 1;
    for(long long i=1;i<=n;i++)
    {
        fact[i] = (fact[i-1]*i)%Mod;
    }
    return (fact[n]*modInverse(fact[r])%Mod*modInverse(fact[n-r])%Mod)%Mod;

}
long long factorial(long long n)
{
    long long fact = 1;
    for(long long i=1;i<=n;i++)
    {
        fact = (fact*i)%Mod;
    }
    return fact;
}

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
       int n,k;
         cin>>n>>k;
         vector<int >rowcnt(n+1,0);
            vector<int >colcnt(n+1,n);
            for(int i=0;i<k;i++)
            {
                int x,y;
                cin>>x>>y;
                rowcnt[x]++;
                colcnt[y]--;
            }
            long long ans = 1;
            for(int i=1;i<=n;i++)
            {
                ans = (ans*nCr(n,rowcnt[i]))%Mod;
                                ans = (ans*nCr(n,colcnt[i]))%Mod;

                 

            }
            cout<<ans<<endl;

    }


    return 0;
}
