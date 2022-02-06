/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 10700 KB                             
*  problem: https://codeforces.com/contest/839/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
double ans;
vector<int>adj[N+2];
void dds(int node,int par,double pr,int ds)
{
  int sz;
  if(node==1)sz=adj[node].size();
  else sz=adj[node].size()-1;
  if(!sz)
  {
    ans+=ds*pr;return ;
  }
  double fc=1.0/(sz*1.0);
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dds(x,node,pr*fc,ds+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dds(1,-1,1,0);
  cout<<setprecision(9)<<fixed<<ans<<endl;
  return 0;
}