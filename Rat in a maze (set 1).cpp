//https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

#include <bits/stdc++.h>
using namespace std;

int x[2]={0,1};
int y[2]={1,0};

bool backtrack(vector<vector<int>>& mat,int n,int m,int i,int j)
{
    if(i<0||i>=n||j<0||j>=m||mat[i][j]==0) return false;
    if(i==n-1&&j==m-1) {mat[i][j]=2; return true;}
    
    mat[i][j]=2;
    
    for(int k=0;k<2;k++)
    {
        if(backtrack(mat,n,m,i+x[k],j+y[k])) return true;
    }
    mat[i][j]=1; return false;
}

int main() {
    int n,m; cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m,-1));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    
    if(!backtrack(mat,n,m,0,0)) cout<<"Not possible"<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}