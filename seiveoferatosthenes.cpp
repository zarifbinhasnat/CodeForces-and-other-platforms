#include<bits/stdc++.h>
using namespace std;
void simpleSieve(int limit){
    bool mark[limit+1];
    memset(mark,true,sizeof(mark));
    for(int p=2;p*p<limit;p++){
        if(mark[p]==true){
            for(int i=p*p;i<limit;i+=p){
                mark[i]=false;
            }
        }
    }
    for(int p=2;p<limit;p++){
        if(mark[p]==true){
            cout<<p<<" ";
        }
    }

}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int limit = 30;
    simpleSieve(limit);


    return 0;
}
