/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 9 ms                                            memory_used: 760 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;int ans=0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='#'||s[i-1]=='#')continue;
        if(s[i]==s[i-1])ans++,s[i-1]='#';
    }
    for(int i=2;i<s.size();i++)
    {
        if(s[i]=='#'||s[i-2]=='#')continue;
        if(s[i]==s[i-2])ans++,s[i]='#';
    }
    cout<<ans<<endl;
    return 0;
}