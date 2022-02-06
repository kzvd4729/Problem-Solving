/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2018 11:18                        
*  solution_verdict: Wrong answer on test 47                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/798/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,l;
string s;
map<string,long>mp;
int main()
{
cin>>n;
for(long i=1;i<=n;i++)
{
cin>>s;
l=s.size();
mp[s]+=0;
for(long i=1;i<l;i++)
{
s=s.substr(1,l-1)+s.substr(0,1);
mp[s]+=i;
}
}
if(mp.size()>l)cout<<-1<<endl;
else
{
long ans=99999999;
for(map<string,long>::iterator it=mp.begin();it!=mp.end();it++)
{
ans=min(ans,it->second);
}
cout<<ans<<endl;
}
return 0;
}