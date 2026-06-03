#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    string s;
    cin>>s;
    //find all the substrings of s
    for(int i=0;i<s.size();i++){
        for(int j=1;j<=s.size()-i;j++){
            cout<<s.substr(i,j)<<endl;
        }
    }
    //find all the subsequences of s
    for(int i=0;i<(1<<s.size());i++){
        for(int j=0;j<s.size();j++){
            if(i&(1<<j)){
                cout<<s[j];
            }
        }
        cout<<endl;
    }
    //find the lexicographically largest subsequence which is a palindrome
    string ans="";
    for(int i=0;i<(1<<s.size());i++){
        string temp="";
        for(int j=0;j<s.size();j++){
            if(i&(1<<j)){
                temp+=s[j];
            }
        }
        string temp2=temp;
        reverse(temp2.begin(),temp2.end());
        if(temp==temp2){
            if(temp.size()>ans.size()){
                ans=temp;
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}
