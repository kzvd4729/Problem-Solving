/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2019 20:56                        
*  solution_verdict: Wrong answer on pretest 9               language: GNU C++14                               
*  run_time: 405 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1208/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
map<int,int>vis;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    vis.clear();int cnt=0;
    for(int j=i;j<=n;j++)
    {
      if(vis[aa[j]])break;
      vis[aa[j]]=1;cnt++;
    }
    ans=max(ans,cnt);
  }
  cout<<n-ans<<endl;
  return 0;
}