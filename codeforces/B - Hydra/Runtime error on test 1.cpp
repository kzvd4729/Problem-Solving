/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/12/2020 19:54                        
*  solution_verdict: Runtime error on test 1                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/243/problem/B
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
vector<int>ad[N+2];int h,t;
int cnt[N+2];
void clear(int u,int v)
{
  for(auto x:ad[u])cnt[x]=0;
  for(auto x:ad[v])cnt[x]=0;  
}
void tryCatch(int u,int v)
{
  //if((int)ad[u].size()<=h||(int)ad[v].size()<=t)return ;
  cnt[u]=3;cnt[v]=3;
   for(auto x:ad[u])cnt[x]++;
  for(auto x:ad[v])cnt[x]++;
   int common=0;
  for(auto x:ad[u])if(cnt[x]==2)common++;
   int d1=(int)ad[u].size()-1-common;
  int d2=(int)ad[v].size()-1-common;
  if(d1+d2+common<h+t){clear(u,v);return ;}
   cout<<"YES"<<endl;
  cout<<u<<" "<<v<<endl;
  vector<int>head,tail,com;
  for(auto x:ad[u])
  {
    if(cnt[x]==1)head.push_back(x);
    else if(cnt[x]==2)com.push_back(x);
  }
  for(auto x:ad[v])
  {
    if(cnt[x]==1)tail.push_back(x);
    else if(cnt[x]==2)com.push_back(x);
  }
  //cout<<head.size()<<" "<<tail.size()<<" "<<com.size()<<endl;
  while((int)head.size()<h)
  {
    head.push_back(com.back());
    com.pop_back();
  }
  while((int)tail.size()<t)
  {
    tail.push_back(com.back());
    com.pop_back();
  }
  for(int i=0;i<h;i++)cout<<head[i]<<" ";cout<<endl;
  for(int i=0;i<t;i++)cout<<tail[i]<<" ";cout<<endl;
  exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m>>h>>t;
  vector<pair<int,int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    ed.push_back({u,v});
    ad[u].push_back(v);ad[v].push_back(u);
  }
  for(auto x:ed)
  {
    tryCatch(x.first,x.second);
    tryCatch(x.second,x.first);
  }
  cout<<"NO\n";
  return 0;
}