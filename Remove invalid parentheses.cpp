//https://www.geeksforgeeks.org/remove-invalid-parentheses/

#include <bits/stdc++.h>
using namespace std;


bool isValid(string s)
{
    stack<char> st;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')')
        {
            if(st.empty()) return false;
            st.pop();
        }
    }
    
    if(!st.empty()) return false;
    return true;
}

int main() {
    string s; cin>>s;
    map<string,int> is_present;
    
    queue<string> q;
    q.push(s); is_present[s]++; bool is_found=false;
    
    while(!q.empty())
    {
        string t=q.front(); q.pop();
        if(isValid(t))
        {
            cout<<t<<endl;
            is_found=true;
        }
        if(is_found) continue;
        
        for(int i=0;i<t.size();i++)
        {
            if(t[i]==')'||t[i]=='(')
            {
                string r=t.substr(0,i)+t.substr(i+1,t.size()-i);
                if(is_present.find(r)==is_present.end()) 
                {
                    q.push(r); is_present[r]++;
                }
            }
        }
    }
}