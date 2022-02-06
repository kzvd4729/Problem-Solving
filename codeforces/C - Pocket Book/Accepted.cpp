/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2018 10:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/152/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1000000007;
long n,m,ans,cnt;
string s[102];
map<char,long>mp;
int main()
{
cin>>n>>m;
for(long i=0;i<n;i++)cin>>s[i];
ans=1;
for(long i=0;i<m;i++)
{
mp.clear();
cnt=0;
for(long j=0;j<n;j++)
{
if(mp[s[j][i]]==0)cnt++;
mp[s[j][i]]=1;
}
ans=(ans*cnt)%mod;
}
cout<<ans%mod<<endl;
return 0;
}