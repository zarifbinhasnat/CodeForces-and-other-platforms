#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for (int i=0;i<m;i++)
{
    int a ,b,c;
    cin>>a>>b>>c;
    adj[a].emplace_back(c,b);
}
vector<long long>dist(n+1,LLONG_MAX);
dist[1]=0;
priority_queue<pli

}