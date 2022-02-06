/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2021 20:13                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++17 (64)                          
*  run_time: 202 ms                                          memory_used: 47400 KB                             
*  problem: https://codeforces.com/contest/1508/problem/C
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
const int N=1e6,inf=1e9,mod=1e9+7;
 int par[N+2],par2[N+2];
vector<int>ad[N+2];
 int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int get2(int x)
{
  if(x==par2[x])return x;
  return par2[x]=get2(par2[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
   vector<vector<int> >ed;int xx=0;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;xx^=w;
     ad[u].push_back(v);ad[v].push_back(u);
    ed.push_back({w,u,v});
  }
   for(int i=1;i<=n;i++)sort(ad[i].begin(),ad[i].end());
   for(int i=1;i<=n;i++)par[i]=i;
   set<int>st;
  for(int i=1;i<=n;i++)st.insert(i);
  queue<int>q;
   int edge=0;
  while((int)st.size())
  {
    int b=*st.begin();st.erase(b);
    q.push(b);
     while((int)q.size())
    {
      int u=q.front();q.pop();
       vector<int>del;
      for(auto x:st)
      {
        if(binary_search(ad[u].begin(),ad[u].end(),x))continue;
         del.push_back(x);
        int r1=get(u),r2=get(x);if(r1==r2)assert(0);
        par[r1]=r2;edge++;
      }
      for(auto x:del)st.erase(x),q.push(x);
    }
  }
  long bad=(1LL*n*(n-1))/2-m;
  long sp=0,mx=0;
  if(bad==edge)sp=xx,mx=xx;
    sort(ed.begin(),ed.end());
  for(int i=1;i<=n;i++)par2[i]=par[i];
   for(auto x:ed)
  {
    int r1=get(x[1]),r2=get(x[2]);
     if(r1==r2 && x[0]<mx)
    {
      sp-=mx;sp+=x[0];
      mx=x[0];
    }
     r1=get2(x[1]),r2=get2(x[2]);
    if(r1==r2)continue;
     sp+=x[0];
    par2[r1]=r2;
   }
  cout<<sp<<endl;
   return 0;
}