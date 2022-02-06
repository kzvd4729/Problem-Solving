/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2020 22:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 685 ms                                          memory_used: 106600 KB                            
*  problem: https://codeforces.com/contest/1380/problem/E
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
int com,par[N+2];
vector<int>v[N+2];set<int>st[N+2];
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
void add(int a,int b)
{
  if(abs(a-b)!=1)return;
  int pa=get(a),pb=get(b);if(pa==pb)return;
  com--;par[pa]=pb;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;com=n;
  for(int i=1;i<=n;i++)par[i]=i;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(v[x].size())add(v[x].back(),i);
    v[x].push_back(i);st[x].insert(i);
  }
  cout<<com-1<<"\n";
  for(int i=1;i<m;i++)
  {
    int a,b;cin>>a>>b;
    if(st[a].size()>=st[b].size())
    {
      for(auto x:st[b])
      {
        if(st[a].find(x-1)!=st[a].end())add(x-1,x);
        if(st[a].find(x+1)!=st[a].end())add(x+1,x);
      }
      for(auto x:st[b])st[a].insert(x);
    }
    else
    {
      for(auto x:st[a])
      {
        if(st[b].find(x-1)!=st[b].end())add(x-1,x);
        if(st[b].find(x+1)!=st[b].end())add(x+1,x);
      }
      for(auto x:st[a])st[b].insert(x);
      swap(st[a],st[b]);
    }
    cout<<com-1<<"\n";
  }
  return 0;
}