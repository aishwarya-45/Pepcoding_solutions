//https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/

#include <bits/stdc++.h>
using namespace std;


bool dfs(vector<pair<int,int>> adj[],int sr,int dis,vector<bool> vis,int k)
{
    if(dis>k) return true;
    vis[sr]=true;
    
    for(int i=0;i<adj[sr].size();i++)
    {
        int b=adj[sr][i].first,w=adj[sr][i].second;
        
        if(vis[b]) continue;
        if(dfs(adj,b,dis+w,vis,k)) return true;
    }
    
    return false;
}


int main() {
    int n,e,k; cin>>n>>e>>k;
    vector<pair<int,int>> adj[n];
    
    for(int i=0;i<e;i++)
    {
        int a,b,w; cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    
    int sr; cin>>sr; vector<bool> vis(n,false);
    
    if(dfs(adj,sr,0,vis,k)) cout<<"Yes";
    else cout<<"No";
}