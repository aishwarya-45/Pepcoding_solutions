//https://www.geeksforgeeks.org/combinational-sum/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void knapsack(vector<int>& arr,int n,int x,int idx,vector<int> ans)
{
    if(x==0) {res.push_back(ans); return;}
    if(x<0||idx>=n) return;
    
    knapsack(arr,n,x,idx+1,ans);
    ans.push_back(arr[idx]);
    knapsack(arr,n,x-arr[idx],idx,ans);
}

int main() {
   int n; cin>>n; vector<int> arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];
   int x; cin>>x;
   sort(arr.begin(),arr.end());
   vector<int> ans;
   knapsack(arr,n,x,0,ans);
   
  sort(res.begin(),res.end());
   for(int i=0;i<res.size();i++) 
   {
       vector<int> c=res[i];
       for(int j=0;j<c.size();j++)
       {
           cout<<c[j]<<" ";
       }
       cout<<endl;
   }
}