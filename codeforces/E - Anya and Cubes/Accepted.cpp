/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2020 11:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 421 ms                                          memory_used: 43900 KB                             
*  problem: https://codeforces.com/contest/525/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];long fac[N+2],s;
map<long,int>a[15+2],b[15+2];
void dfs(int i,int n,int k,long sm)
{
  if(sm>s)return ;
  if(i==n){a[k][sm]++;return;}
  dfs(i+1,n,k,sm);
  dfs(i+1,n,k,sm+aa[i]);
  if(aa[i]<=18)dfs(i+1,n,k+1,sm+fac[aa[i]]);
}
void dds(int i,int n,int k,long sm)
{
  if(sm>s)return ;
  if(i==n){b[k][sm]++;return;}
  dds(i+1,n,k,sm);
  dds(i+1,n,k,sm+aa[i]);
  if(aa[i]<=18)dds(i+1,n,k+1,sm+fac[aa[i]]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1;
  for(int i=1;i<=18;i++)fac[i]=fac[i-1]*i;
  int n,k;cin>>n>>k;cin>>s;
  for(int i=0;i<n;i++)cin>>aa[i];
  int md=n/2;dfs(0,md,0,0);dds(md,n,0,0);
  long ans=0;
  for(int i=0;i<=min(n,15);i++)
  {
    for(int j=0;j<=min(n,15);j++)
    {
      if(i+j>k)continue;
      for(auto x:a[i])ans+=(1LL*b[j][s-x.first]*x.second);
    }
  }
  cout<<ans<<endl;
  return 0;
}