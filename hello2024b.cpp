#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin>>t;
    while(t--)
    {
        int a =0,b=0,c;
        cin>>c;
        string s;
        cin>>s;
        for (int i=0;i<c;i++)
        {
            if(s[i]=='+')
            a++;
            else
            b++;
        }
        if (a==b)
        cout<<'0'<<endl;
        else if(a>b)
        cout<<a-b<<endl;
        else if(b>a)
        cout<<b-a<<endl;
        

    }


    return 0;
}
