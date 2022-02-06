/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2020 17:26                        
*  solution_verdict: Wrong answer on test 103                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 13000 KB                             
*  problem: https://codeforces.com/contest/776/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],vs[N+2],cl[N+2];
vector<int>v[N+2];
vector<pair<int,int> >adj[N+2];
void dfs(int node,int c)
{
  if(cl[node]!=-1&&cl[node]!=c)cout<<"NO\n",exit(0);
  if(cl[node]!=-1)return ;cl[node]=c;
  for(auto x:adj[node])
    dfs(x.first,c^(!x.second));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    while(x--)
    {
      int a;cin>>a;
      v[a].push_back(i);
    }
  }
  for(int i=1;i<=n;i++)
  {
    assert(v[i].size()==2);
    adj[v[i][0]].push_back({v[i][1],aa[i]});
    adj[v[i][1]].push_back({v[i][0],aa[i]});
    //cout<<v[i][0]<<" -- "<<v[i][1]<<" "<<aa[i]<<endl;
  }
  memset(cl,-1,sizeof cl);
  for(int i=1;i<=n;i++)
  {
    if(cl[i]!=-1)continue;
    dfs(i,0);
  }
  cout<<"YES\n";
  return 0;
}