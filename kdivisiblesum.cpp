#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t; 
    while(t--)
    {
        int n,k;
        cin>>n>>k;
         if(n <= k){

cout<<(k + n - 1) / n<<endl;            }
        else{
            cout<< 1 + (n % k<0 )<<endl;
            }
    }


    return 0;
}
