/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2019 01:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1121/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-12;
int aa[N+2],kk[N+2],id[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int cm=0,sl=0;int ans=0;
  for(int i=1;i<=150000;i++)
  {
    double pr=100.0*((cm*1.0)/(n*1.0));
    pr+=0.5+eps;int p=floor(pr);
    for(int j=1;j<=k;j++)
    {
      if(!id[j])id[j]=++sl;
      if(id[j]>n)continue;
      kk[j]++;
      if(kk[j]==p)
        ans+=vis[id[j]]^1,vis[id[j]]=1;
      if(kk[j]==aa[id[j]])
        kk[j]=0,id[j]=0,cm++;
    }
  }
  cout<<ans<<endl;
  return 0;
}