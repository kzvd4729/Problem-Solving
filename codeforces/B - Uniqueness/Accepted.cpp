/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2019 21:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1208/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
map<int,int>vis,fr;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];fr[aa[i]]++;
  }
  int cnt=0;vis=fr;
  for(auto x:fr)if(x.second>1)cnt++;
  if(cnt==0)cout<<0<<endl,exit(0);
  int ans=1e9,Cnt=cnt;
  for(int i=1;i<=n;i++)
  {
    int now=0;
    for(int j=i;j<=n;j++)
    {
      fr[aa[j]]--;now++;
      if(fr[aa[j]]==1)cnt--;
      if(cnt==0)
      {
        ans=min(ans,now);
        break;
      }
    }
    cnt=Cnt;fr=vis;
  }
  cout<<ans<<endl;
  return 0;
}