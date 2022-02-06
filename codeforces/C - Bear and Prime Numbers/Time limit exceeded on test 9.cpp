/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/30/2018 18:13                        
*  solution_verdict: Time limit exceeded on test 9           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 81600 KB                             
*  problem: https://codeforces.com/contest/385/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e7;
int vis[N+2],u,v,cnt[N+2],n,x,q;
void seive(void)
{
  int lim=sqrt(N+1);
  for(int i=4;i<=N;i+=2)vis[i]=1;
  for(int i=3;i<=N;i+=2)
  {
    if(vis[i]||i>lim)continue;
    for(int j=i*i;j<=N;j+=2*i)vis[j]=1;
  }
}
void factorize(int z)
{
  if(z%2==0)cnt[2]++;
  while(z%2==0)z/=2;
  while(true)
  {
    if(vis[z]==0)
    {
      cnt[z]++;
      break;
    }
    for(int i=3;i<=z;i+=2)
    {
      if(z%i==0)
      {
        cnt[i]++;
        while(z%i==0)z/=i;
        break;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  seive();
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    factorize(x);
  }
  for(int i=1;i<=N;i++)cnt[i]+=cnt[i-1];
  cin>>q;
  while(q--)
  {
    cin>>u>>v;
    if(u>N)
    {
      cout<<0<<endl;
      continue;
    }
    v=min(v,N);
    cout<<cnt[v]-cnt[u-1]<<endl;
  }
  return 0;
}