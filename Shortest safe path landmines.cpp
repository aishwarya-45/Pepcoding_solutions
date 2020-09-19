//https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-with-landmines/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& mat,int n,int m,int i,int j,int steps)
{
    if(i<0||i>=n||j<0||j>=m||mat[i][j]==0||mat[i][j]==-1) return INT_MAX;
    if(j==m-1) return steps;
    
    mat[i][j]=-1;
    int ans=min(dfs(mat,n,m,i-1,j,steps+1),min(dfs(mat,n,m,i,j-1,steps+1),min(dfs(mat,n,m,i,j+1,steps+1),dfs(mat,n,m,i+1,j,steps+1))));
    mat[i][j]=1;
    return ans;
}

bool isSafe(int i,int j,int n,int m)
{
    if(i<0||i>=n||j<0||j>=m) return false;
    return true;
}

int main() {
   int n,m; cin>>n>>m;
   vector<vector<int>> mat(n,vector<int>(m));
   
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cin>>mat[i][j];
       }
   }
   
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(mat[i][j]==0)
           {
               if(isSafe(i-1,j,n,m)&&mat[i-1][j]==1) mat[i-1][j]=-1;
               if(isSafe(i,j-1,n,m)&&mat[i][j-1]==1) mat[i][j-1]=-1;
               if(isSafe(i,j+1,n,m)&&mat[i][j+1]==1) mat[i][j+1]=-1;
               if(isSafe(i+1,j,n,m)&&mat[i+1][j]==1) mat[i+1][j]=-1;
           }
       }
   }
   
   int ans=INT_MAX;
   
   for(int i=0;i<n;i++)
   {
       if(mat[i][0]==1) 
       {
           ans=min(ans,dfs(mat,n,m,i,0,0));
       }
   }
   
   cout<<ans;
}