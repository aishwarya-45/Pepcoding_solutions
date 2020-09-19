//https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#include <bits/stdc++.h>
using namespace std;

int x[8]={2, 1, -1, -2, -2, -1,  1,  2};
int y[8]={ 1, 2,  2,  1, -1, -2, -2, -1};


bool backtrack(vector<vector<int>>& mat,int i,int j,int cnt)
{
    if(i<0||i>=8||j<0||j>=8||mat[i][j]!=-1) return false;
    if(cnt>=63) {mat[i][j]=cnt; return true;}
    mat[i][j]=cnt++;
    
    for(int k=0;k<8;k++)
    {
        if(backtrack(mat,i+x[k],j+y[k],cnt)) return true;
    }
    mat[i][j]=-1; return false;
}

int main() {
    vector<vector<int>> mat(8,vector<int>(8,-1));
    
    backtrack(mat,0,0,0);
    
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}