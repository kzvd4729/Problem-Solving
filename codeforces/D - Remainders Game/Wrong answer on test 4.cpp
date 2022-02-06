/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/07/2018 13:29                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 42800 KB                             
*  problem: https://codeforces.com/contest/688/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2];
vector<int>fc[N+2];
void seive(void)
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i+i;j<=N;j+=i)
      fc[j].push_back(i),vis[j]=1;
  }
}
void yes(void)
{
  cout<<"Yes"<<endl,exit(0);
}
void no(void)
{
  cout<<"No"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();int n,k;cin>>n>>k;
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;vis[x]=1;
    if(x==k)yes();
  }
  if(fc[k].size()==0)no();
  int f=0;
  for(auto x:fc[k])
    if(vis[x]==0)f=1;
  if(!f)yes();
  else no();
  return 0;
}