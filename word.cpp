#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    string s;
    cin>>s;
    int cntma=0,mi=0;
    //iterate through string
    for(int i=0;i<s.length();i++)
    {
        if(isupper(s[i]))
            cntma++;
        else 
            mi++;
    }  
    if(cntma>mi)
    {
        for(int i=0;i<s.length();i++)
        {
            s[i] = toupper(s[i]);
        }
    }
    else if(cntma<mi)
    {
        for(int i=0;i<s.length();i++)
        {
            s[i] = tolower(s[i]);
        }
    }
    else if (cntma==mi)
    {
        for(int i=0;i<s.length();i++)
        {
            s[i] = tolower(s[i]);
        }
    }
    cout<<s<<endl;
    
    return 0;
}
