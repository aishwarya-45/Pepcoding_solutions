//https://www.geeksforgeeks.org/tug-of-war/

#include <bits/stdc++.h>
using namespace std;

vector<int> res;

void backtrack(vector<int>& a,int idx,int n,int t_s,int s,int m,vector<int> sol,int &min_diff)
{
    if(m==0) 
    {
        if(abs(s-(t_s-s))<min_diff) {res=sol; min_diff=abs(s-(t_s-s));}
        return;
    }
    if(idx>=n) return;
    
    sol.push_back(a[idx]); backtrack(a,idx+1,n,t_s,s+a[idx],m-1,sol,min_diff);
    sol.pop_back(); backtrack(a,idx+1,n,t_s,s,m,sol,min_diff);
}

int main() {
    int n; cin>>n; vector<int> a(n); int t_s=0;
    for(int i=0;i<n;i++) {cin>>a[i]; t_s+=a[i];}
    
    int m=n/2; 
    vector<int> sol; int min_diff=INT_MAX;
    backtrack(a,0,n,t_s,0,m,sol,min_diff);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
}