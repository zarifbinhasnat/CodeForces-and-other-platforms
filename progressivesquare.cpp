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
       int n,c,d;
         cin>>n>>c>>d;
         vector<int> a(n*n);

         for(int i=0;i<n*n;i++)
         {
             cin>>a[i];
         }
            sort(a.begin(),a.end());
            vector<vector<int>> b(n,vector<int>(n));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i == 0 && j == 0)
                    {
                        b[i][j] = a[0];
                    }
                    else 
                    {
                        b[i][j] = a[0]+(j * d) + (i * c);
                    }
                }
            }
            vector<int >f(n*n);
            int index = 0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    f[index++] = b[i][j];
                }
            }
            sort(f.begin(),f.end());
            if(f == a)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
                        
    }


    return 0;
}
