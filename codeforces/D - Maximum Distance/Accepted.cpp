/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2020 20:43                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 140 ms                                          memory_used: 6400 KB                              
*  problem: https://codeforces.com/contest/1081/problem/D
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
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e5;
int nm[N+2],par[N+2];
int get(int x)
{
  if(x==par[x])return par[x];
  return par[x]=get(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=k;i++)
  {
    int x;cin>>x;nm[x]=1;
  }
  vector<vector<int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ed.push_back({w,u,v});
  }
  for(int i=1;i<=n;i++)par[i]=i;
  sort(ed.begin(),ed.end());int ans,cnt=0;
  for(auto x:ed)
  {
    int a=get(x[1]),b=get(x[2]);
    if(a==b)continue;
    if(nm[a]&&nm[b])
    {
      par[a]=b;cnt++;
      if(cnt==k-1){ans=x[0];break;}
    }
    else if(nm[a])par[b]=a;
    else par[a]=b;
  }
  for(int i=1;i<=k;i++)cout<<ans<<" ";cout<<endl;
  return 0;
}