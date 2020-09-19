//https://www.geeksforgeeks.org/print-palindromic-partitions-string/

bool isPalindrome(string s)
{
    string r=s;
    reverse(r.begin(),r.end());
    return r==s;
}

void partition(string s,string ss,int idx,int n)
{
    if(idx>=n) {cout<<ss<<endl; return;}
    
    string x="";
    
    for(int i=idx;i<n;i++)
    {
        x+=s[i];
        if(isPalindrome(x))
        {
            partition(s,ss+x+" ",i+1,n);
        }
    }
}


int main()
{
    string s; cin>>s;
    partition(s,"",0,s.size());
}