#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int size = 2*n;
    vector<int>v(size);
    for(int i =0;i<size;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    //sort based on the max difference between two numbers 
    map<int,int>mp(size);
    for(int i =0;i<size;i++)
    {
        int min ;
        for(int j =0;j<size && j!=i;j++)
        {
if (//smallest store into key value style )
        }
    }
    //sort according to the value which is the difference 
    //pair up the smallest differnce and a counter +=difference 
    // largest 2 values get stored without the +=difference 

    return 0;
}
