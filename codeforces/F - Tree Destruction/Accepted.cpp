/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2020 22:09                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 343 ms                                          memory_used: 49400 KB                             
*  problem: https://codeforces.com/contest/911/problem/F
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
#include<random>
#define long long long 
using namespace std;
const int N=1e6;
vector<int>ad[N+2];
int mx,tr,rt,par[N+2],lv[N+2];
long ans;
void dfs(int nd,int pr,int d)
{
  if(d>mx)mx=d,tr=nd;par[nd]=pr;
  for(auto x:ad[nd])
    if(x!=pr)dfs(x,nd,d+1);
}
vector<vector<int> >prn;
void dds(int nd,int pr,int d,int ls)
{
  if(lv[nd]!=-1)ls=lv[nd];
  for(auto x:ad[nd])
    if(x!=pr)dds(x,nd,d+1,ls);
   if(lv[nd]!=-1)return ;
  if(d>d+mx-2*ls)ans+=d,prn.push_back({nd,rt,nd});
  else ans+=d+mx-2*ls,prn.push_back({nd,tr,nd});
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);ad[v].push_back(u);
  }
  dfs(1,-1,0);mx=-1;rt=tr;dfs(rt,-1,0);
   int nd=tr;vector<vector<int> >ex;int dc=mx;
  memset(lv,-1,sizeof lv);
  while(nd!=-1)
  {
    if(nd!=rt)ex.push_back({rt,nd,nd});
    ans+=dc;lv[nd]=dc--;
    nd=par[nd];
  }
  dds(rt,-1,0,0);cout<<ans<<endl;
  for(auto x:prn)cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<'\n';
  for(auto x:ex)cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<'\n';
  return 0;
}