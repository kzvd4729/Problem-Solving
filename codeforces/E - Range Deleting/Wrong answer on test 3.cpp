/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2019 21:54                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1167/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int lft[N+2],rgt[N+2],aa[N+2],now[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x;cin>>n>>x;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
    if(!lft[aa[i]])lft[aa[i]]=i;
    rgt[aa[i]]=i;
  }
  int ls=0,ok=0;
  for(int i=1;i<=n;i++)
  {
    if(!lft[i])
    {
      ok++;continue;
    }
    if(lft[i]<ls)break;
    ok++;ls=max(ls,rgt[i]);
    now[ok]=ls;
  }
  ls=n+1;int i=x;long ans=0;
  while(true)
  {
    if(ok<0)break;
    while(true)
    {
      if(lft[i]<now[ok])break;
      if(rgt[i]&&rgt[i]>ls)break;
      if(lft[i])ls=lft[i];
      i--;
    }
    ans+=(x-i+1)*1LL;ok--;
  }
  cout<<ans<<endl;
  return 0;
}