/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2019 20:49                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
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
  int ans=1e9;
  for(int i=n;i>=1;i--)
  {
    if(vis[aa[i]])break;
    vis[aa[i]]=1;
    for(int j=1;j<i;j++)
    {
      if(vis[aa[j]])
      {
        ans=min(ans,i-j);
        for(int k=1;k<j;k++)
          vis[aa[k]]=0;
        break;
      }
      vis[aa[j]]=1;
    }
  }
  if(ans==1e9)ans=0;
  cout<<ans<<endl;
  return 0;
}