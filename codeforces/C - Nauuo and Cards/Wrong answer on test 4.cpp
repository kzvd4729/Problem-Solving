/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/19/2019 16:32                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/1173/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],bb[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;deque<int>dq;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];vis[aa[i]]=1;
  }
  for(int i=1;i<=n;i++)
  {
    cin>>bb[i];dq.push_back(bb[i]);
  }
  int f=0;
  for(int i=1;i<=n;i++)
  {
    if(bb[i]==1)
    {
      for(int j=i+1;j<=n;j++)
        if(bb[j]!=bb[j-1]+1)f=1;
      break;
    }
  }
  int tar=1,ans=0;
  if(!f)tar=bb[n]+1;
  while(true)
  {
    if(tar>n)break;
    if(vis[tar])
    {
      tar++;
      if(dq.size())vis[dq.front()]=1;
      if(dq.size())dq.pop_front();ans++;
    }
    else
    {
      if(dq.size())vis[dq.front()]=1;
      if(dq.size())dq.pop_front();ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}