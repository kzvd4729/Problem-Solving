/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/18/2018 22:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 8500 KB                              
*  problem: https://codeforces.com/contest/1079/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,aa[N+2],f,vis[N+2][6];
vector<int>v;
void dfs(int st,int last)
{
  if(st>n)
  {
    f=1;return ;
  }
  if(vis[st][last])return ;
  vis[st][last]=1;
  if(aa[st]>aa[st-1])
  {
    for(int i=last+1;i<=5;i++)
    {
      dfs(st+1,i);
      if(f)
      {
        v.push_back(i);return ;
      }
    }
  }
  else if(aa[st]<aa[st-1])
  {
    for(int i=last-1;i>=1;i--)
    {
      dfs(st+1,i);
      if(f)
      {
        v.push_back(i);return ;
      }
    }
  }
  else
  {
    for(int i=1;i<=5;i++)
    {
      if(i==last)continue;
      dfs(st+1,i);
      if(f)
      {
        v.push_back(i);return ;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  if(n==1)cout<<1<<endl,exit(0);
   for(int i=1;i<=5;i++)
  {
    dfs(2,i);
    if(f)
    {
      v.push_back(i);
      reverse(v.begin(),v.end());
       for(auto x:v)
      {
        cout<<x<<" ";
      }
      exit(0);
    }
  }
  cout<<-1<<endl;
   return 0;
}