/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 419 ms                                          memory_used: 768 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int ans=1e9;
void dfs(int i,string s,int cnt)
{
    if(i>=s.size())
    {
        for(int i=2;i<s.size();i++)
        {
            if(s[i]=='#'||s[i-2]=='#')continue;
            if(s[i]==s[i-2])
                cnt++,s[i]='#';
        }
        ans=min(ans,cnt);
        return ;
    }
    string tmp;
    if(s[i]==s[i-1])
    {
        tmp=s;tmp[i]='#';dfs(i+1,tmp,cnt+1);
        tmp=s;tmp[i-1]='#';dfs(i+1,tmp,cnt+1);
    }
    else dfs(i+1,s,cnt);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;dfs(1,s,0);
    cout<<ans<<endl;
    return 0;
}