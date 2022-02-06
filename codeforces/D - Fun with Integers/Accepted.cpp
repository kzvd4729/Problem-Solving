/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2018 23:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/1062/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int vis[N+2];
long ans[N+2];
void seive(void)
{
  vis[1]=1;int sq=sqrt(N+2);
  for(int i=4;i<=N;i+=2)vis[i]=1;
  for(int i=3;i<=N;i+=2)
  {
    if(vis[i])continue;
    if(i>sq)continue;
    for(int j=i*i;j<=N;j+=2*i)
      vis[j]=1;
  }
}
void whore(void)
{
  for(int i=2;i<=N;i++)
  {
    for(int j=i+i;j<=N;j+=i)
    {
      ans[j]+=(j/i)*1LL;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();whore();int n;cin>>n;
  if(n<4)cout<<0<<endl,exit(0);
  long sum=0;
  for(int i=4;i<=n;i++)
  {
    if(!vis[i])continue;
    sum+=ans[i];
  }
  cout<<sum*4<<endl;
  return 0;
}