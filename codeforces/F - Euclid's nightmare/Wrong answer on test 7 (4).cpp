/****************************************************************************************
*  @author: kzvd4729#                                        created: May/02/2021 15:41                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++17 (64)                          
*  run_time: 1263 ms                                         memory_used: 168200 KB                            
*  problem: https://codeforces.com/contest/1466/problem/F
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=5e5,inf=1e9,mod=1e9+7;
 int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
 set<int>st[N+2],an[N+2];
vector<int>ans;
void insert(pair<int,int>p,int id)
{
  if((int)st[p.second].size())
  {
    p.second=*st[p.second].begin();
  }
  if((int)st[p.first].size())
  {
    p.first=*st[p.first].begin();
  }
   if(p.first<p.second)swap(p.first,p.second);
  if(p.first==p.second)return ;
    if(p.first==0)assert(0);
  vector<pair<int,int> >dl,in;
  for(auto x:st[p.first])
  {
    if(x==p.second);
    else 
    {
      dl.push_back({p.first,x});
      in.push_back({p.second,x});
    }
  }
  for(auto x:an[p.first])
  {
    if(x==p.second);
    else 
    {
      dl.push_back({p.first,x});
      in.push_back({p.second,x});
    }
  }
   for(auto x:dl)
  {
    int u=x.first,v=x.second;
    if(u>v)swap(u,v);
     st[u].erase(v);an[v].erase(u);
  }
  for(auto x:in)
  {
    int u=x.first,v=x.second;
    if(u>v)swap(u,v);
     st[u].insert(v);an[v].insert(u);
  }
    st[max(p.first,p.second)].insert(min(p.first,p.second));
  an[min(p.first,p.second)].insert(max(p.first,p.second));
  ans.push_back(id);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
   vector<vector<int> >v(n);
  for(int i=0;i<n;i++)
  {
    int k;cin>>k;v[i].resize(k);
    for(int j=0;j<k;j++)cin>>v[i][j];
  }
   for(int i=0;i<n;i++)
  {
    pair<int,int>p;
    if(v[i].size()==1)p={v[i][0],0};
    else p={max(v[i][0],v[i][1]),min(v[i][0],v[i][1])};
     insert(p,i);
   }
   cout<<big(2,(int)ans.size())<<" "<<(int)ans.size()<<endl;
  for(auto x:ans)cout<<x+1<<" ";cout<<endl;
    return 0;
}