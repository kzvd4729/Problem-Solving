/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/17/2018 13:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1248 ms                                         memory_used: 21300 KB                             
*  problem: https://codeforces.com/contest/243/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],ans;
bool vis[100*N];
vector<int>vv[22];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
    for(int j=0;j<=20;j++)
    {
      if(aa[i]&(1<<j))
        vv[j].push_back(i);
    }
  }
  for(int i=1;i<=n;i++)
  {
    int nm=aa[i],ii=i;
    while(true)
    {
      if(!vis[nm])ans++;vis[nm]=1;
      int mn=N+2;
      for(int j=0;j<=20;j++)
      {
        if(nm&(1<<j))continue;
        int id=upper_bound(vv[j].begin(),vv[j].end(),ii)-vv[j].begin();
        if(id<vv[j].size())mn=min(mn,vv[j][id]);
      }
      if(mn>N)break;
      nm|=aa[mn];ii=mn;
    }
  }
  cout<<ans<<endl;
  return 0;
}