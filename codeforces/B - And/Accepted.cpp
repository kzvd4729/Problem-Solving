/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/30/2018 14:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1013/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e8;
const int N=1e5;
int n,arr[N+2],vis[N+2],x;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>x;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    if(vis[arr[i]])cout<<0<<endl,exit(0);
    vis[arr[i]]=1;
  }
  for(int i=1;i<=n;i++)
  {
    vis[arr[i]]=0;
    if(vis[arr[i]&x])cout<<1<<endl,exit(0);
    vis[arr[i]]=1;
  }
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++)
  {
    arr[i]=arr[i]&x;
    if(vis[arr[i]])cout<<2<<endl,exit(0);
    vis[arr[i]]=1;
  }
  cout<<-1<<endl;
  return 0;
}