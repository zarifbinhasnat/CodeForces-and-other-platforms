#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin>>t;
    while(t--)
    {
        int a ,b,c;
        cin>>a>>b>>c;
        if (a==b && b==c)
        {
            cout<<0<<endl;
        }
        else if (abs(a-b)==1 || abs(b-c)==1 || abs(c-a)==1)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<abs(a-b)+abs(b-c)+abs(c-a)-4<<endl;
        }
        
    }


    return 0;
}
