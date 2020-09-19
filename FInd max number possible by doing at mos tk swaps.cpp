//https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/

#include <bits/stdc++.h>
using namespace std;

vector<int> res;

void backtrack(string org,string &max_str,int idx,int k)
{
    if(k==0)
    {
        if(org>max_str) max_str=org;
        return;
    }
    if(idx>=org.size()) return;
    
    for(int i=idx;i<org.size();i++)
    {
        swap(org[idx],org[i]);
        if(i==idx) backtrack(org,max_str,idx+1,k);
        else backtrack(org,max_str,idx+1,k-1);
        swap(org[idx],org[i]);
    }
    
}

int main() {
    int n,k; cin>>n>>k; string org="";
    while(n)
    {
        org+=to_string(n%10); n/=10;
    }
    reverse(org.begin(),org.end());
    string max_str="";
    backtrack(org,max_str,0,k);
    
    cout<<max_str;
}