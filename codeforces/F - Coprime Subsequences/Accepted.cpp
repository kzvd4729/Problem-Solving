/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2019 20:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 5400 KB                              
*  problem: https://codeforces.com/contest/803/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,mod=1e9+7;
int vis[N+2],pw[N+2],aa[N+2],fr[N+2];
vector<int>fac[N+2];
void factorise(void)
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      vis[j]=1;
      fac[j].push_back(i);
    }
  }
}
void add(int id,int i,int nm)
{
  if(i>=fac[id].size())
  {
    fr[nm]++;return ;
  }
  add(id,i+1,nm);
  add(id,i+1,nm*fac[id][i]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  factorise();pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(pw[i-1]*2)%mod;
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];add(aa[i],0,1);
  }
  long ans=(pw[n]-1+mod)%mod;
  for(int i=2;i<=N;i++)
  {
    int sz=fac[i].size();
    if(sz%2)ans=(ans-(pw[fr[i]]-1)+mod)%mod;
    else ans=(ans+(pw[fr[i]]-1)+mod)%mod;
  }
  cout<<ans<<endl;
  return 0;
}