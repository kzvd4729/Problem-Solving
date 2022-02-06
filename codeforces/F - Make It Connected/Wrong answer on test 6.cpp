/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/27/2018 21:45                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 31300 KB                             
*  problem: https://codeforces.com/contest/1095/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2];
pair<long,long>aa[N+2];
vector<pair<long,long> >ed[N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n,m;cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  cin>>aa[i].first;aa[i].second=i;
 }
 sort(aa+1,aa+n+1);
 while(m--)
 {
  int u,v;long w;cin>>u>>v>>w;
  ed[u].push_back(make_pair(v,w));
  ed[v].push_back(make_pair(u,w));
 }
 long ans=0;vis[aa[1].second]=1;
 for(int i=2;i<=n;i++)
 {
  long mn=aa[1].first+aa[i].first;
  int id=aa[i].second;
  for(int j=0;j<ed[id].size();j++)
  {
   if(vis[ed[id][j].first])mn=min(mn,ed[id][j].second);
  }
  ans+=mn;vis[aa[i].second]=1;
 }
 cout<<ans<<endl;
 return 0;
}