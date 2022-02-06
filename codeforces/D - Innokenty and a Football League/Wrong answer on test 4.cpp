/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/08/2018 16:32                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/782/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,f;
string x,y,ans[1003];
map<string,long>mp;
struct data
{
string s1,s2;
}s[1003];
void dfs(long now)
{
if(now>n)
{
f=1;
return;
}
if(mp[s[now].s1]==0)
{
mp[s[now].s1]=2;
ans[now]=s[now].s1;
dfs(now+1);
}
if(f)return ;
if(mp[s[now].s2]!=2&&mp[s[now].s1]!=2)
{
mp[s[now].s1]=1;
mp[s[now].s2]=2;
ans[now]=s[now].s2;
dfs(now+1);
}
if(f)return ;
mp[s[now].s1]=0;
mp[s[now].s2]=0;       
}
int main()
{
cin>>n;
for(long i=1;i<=n;i++)
{
cin>>x>>y;
s[i].s1=x.substr(0,3);
s[i].s2=x.substr(0,2)+y.substr(0,1);
}
dfs(1);
if(f==0)cout<<"NO"<<endl;
else
{
cout<<"YES"<<endl;
for(long i=1;i<=n;i++)cout<<ans[i]<<endl;
}
return 0;
}