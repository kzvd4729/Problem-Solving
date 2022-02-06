/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/09/2018 09:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/913/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,cnt,f;
vector<long>adj[1003];
int main()
{
cin>>n;
for(long i=2;i<=n;i++)
{
cin>>x;
adj[x].push_back(i);
}
for(long i=1;i<=n;i++)
{
if(!adj[i].size())continue;
cnt=0;
for(long j=0;j<adj[i].size();j++)
{
x=adj[i][j];
if(!adj[x].size())cnt++;       
}
if(cnt<3)f=1;
}
if(f)cout<<"NO"<<endl;
else cout<<"YES"<<endl;
return 0;
}