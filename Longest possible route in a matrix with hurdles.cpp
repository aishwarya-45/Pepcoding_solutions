//https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& mat,int n,int m,int i,int j,int dr,int dc,int steps)
{
    if(i<0||i>=n||j<0||j>=m||mat[i][j]==0) return INT_MIN;
    if(i==dr&&j==dc) return steps;
    
    mat[i][j]=0;
    int ans=max(dfs(mat,n,m,i-1,j,dr,dc,steps+1),max(dfs(mat,n,m,i,j-1,dr,dc,steps+1),max(dfs(mat,n,m,i,j+1,dr,dc,steps+1),dfs(mat,n,m,i+1,j,dr,dc,steps+1))));
    mat[i][j]=1;
    
    return ans;
}

int main() {
   int n,m; cin>>n>>m; vector<vector<int>> mat(n,vector<int>(m));
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cin>>mat[i][j];
       }
   }
   
   int sr,sc,dr,dc; cin>>sr>>sc>>dr>>dc;
   cout<<dfs(mat,n,m,sr,sc,dr,dc,0);
}