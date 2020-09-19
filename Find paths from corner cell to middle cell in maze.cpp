//https://www.geeksforgeeks.org/find-paths-from-corner-cell-to-middle-cell-in-maze/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void backtrack(vector<vector<int>>& mat,int i,int j,int n,int m,int dr,int dc,int steps,vector<int> paths)
{
    if(i<0||i>=n||j<0||j>=m||mat[i][j]==-1) return;
    if(steps==0&&i==dr&&j==dc) {paths.push_back(mat[i][j]); res.push_back(paths); return;}
    
    if(steps==0) steps=mat[i][j];
    
    paths.push_back(mat[i][j]); int x=mat[i][j]; mat[i][j]=-1;
    
    backtrack(mat,i-1,j,n,m,dr,dc,steps-1,paths);
    backtrack(mat,i,j-1,n,m,dr,dc,steps-1,paths);
    backtrack(mat,i,j+1,n,m,dr,dc,steps-1,paths);
    backtrack(mat,i+1,j,n,m,dr,dc,steps-1,paths);
    
    paths.pop_back();
    
    mat[i][j]=x;
}

int main() {
    int n,m; cin>>n>>m; vector<vector<int>> mat(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<int> paths;
    
    int dr=n/2,dc=m/2;
    
    backtrack(mat,0,0,n,m,dr,dc,0,paths);
    backtrack(mat,0,m-1,n,m,dr,dc,0,paths);
    backtrack(mat,n-1,0,n,m,dr,dc,0,paths);
    backtrack(mat,n-1,m-1,n,m,dr,dc,0,paths);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
}