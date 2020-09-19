//https://www.geeksforgeeks.org/match-a-pattern-and-string-without-using-regular-expressions/

#include <bits/stdc++.h>
using namespace std;

bool backtrack(string s,string p,map<char,string>& mp,int i,int j)
{
    if(i==s.size()&&j==p.size()) return true;
    if(i==s.size()||j==p.size()) return false;
    
    if(mp.find(p[j])!=mp.end())
    {
        string x=mp[p[j]];
        int k=x.size();
        if(s.substr(i,k)!=x) return false;
        
        return backtrack(s,p,mp,i+k,j+1);
    }
    
    else
    {
        string c="";
        for(int k=i;k<s.size();k++)
        {
            c+=s[k];
            mp[p[j]]=c;
            if(backtrack(s,p,mp,k+1,j+1)) return true;
            mp.erase(p[j]);
        }
        return false;
    }
    
}

int main() {
   string s,pattern; cin>>s>>pattern;
   map<char,string> mpp;
   
   
  if(backtrack(s,pattern,mpp,0,0)) cout<<"YES";
  else cout<<"NO";
}