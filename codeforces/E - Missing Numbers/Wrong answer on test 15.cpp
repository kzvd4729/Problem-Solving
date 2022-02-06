/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2018 19:46                        
*  solution_verdict: Wrong answer on test 15                 language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 21900 KB                             
*  problem: https://codeforces.com/contest/1081/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],dis[N+2],mx,vis[N+2];
vector<pair<int,int> >vc[N+2];
vector<int>adj[N+2],ans;
void pre(void)
{
  for(int i=3;i<=N;i+=2)
  {
    int sum=0;
    for(int j=i;j<=N;j+=2)
    {
      sum+=j;
      if(sum>N)break;
      vc[sum].push_back({i/2,(j+1)/2});
    }
  }
}
int dfs(int node)
{
  if(dis[node]!=-1)return dis[node];
  dis[node]=0;
  for(auto x:adj[node])
    dis[node]=max(dis[node],1+dfs(x));
  return dis[node];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pre();
  int n;cin>>n;
  for(int i=2;i<=n;i+=2)
    cin>>aa[i];
   vector<int>last,tmp;tmp.push_back(0);
  for(int i=2;i<=n;i+=2)
  {
    int x=aa[i];last=tmp;tmp.clear();
    for(auto xx:vc[x])
    {
      adj[xx.first].push_back(xx.second);
      for(auto zz:last)
      {
        if(zz<xx.first)
          adj[zz].push_back(xx.first);
      }
      tmp.push_back(xx.second);
    }
  }
  memset(dis,-1,sizeof(dis));
  mx=dfs(0);//cout<<mx<<endl;
  if(mx<n)cout<<"No"<<endl,exit(0);
  cout<<"Yes"<<endl;int nd=0;
   vector<int>v;
  while(true)
  {
    v.push_back(nd);
    if(!mx)break;
    for(auto x:adj[nd])
    {
      if(dis[x]==mx-1)
      {
        nd=x;mx--;
        break;
      }
    }
    if(nd==0)break;
  }
  for(int i=1;i<v.size();i++)
  {
    long y=v[i],x=v[i-1];
    long z=y*y-x*x;
    cout<<z<<" ";
  }
  cout<<endl;
  return 0;
}