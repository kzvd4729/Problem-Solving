/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/20/2020 22:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 39500 KB                             
*  problem: https://codeforces.com/contest/1370/problem/E
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
int vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string a,b;cin>>a>>b;
  if(a==b)cout<<0<<endl,exit(0);
  int c=0,d=0;
  for(int i=0;i<n;i++)c+=(a[i]=='0');
  for(int i=0;i<n;i++)d+=(b[i]=='0');
  if(c!=d)cout<<-1<<endl,exit(0);
    string x;
  for(int i=0;i<n;i++)
    if(a[i]!=b[i])x.push_back(a[i]);
  //cout<<x<<endl;
   set<int>st[2];
  for(int i=0;i<x.size();i++)
  {
    if(x[i]=='0')st[0].insert(i);
    else st[1].insert(i);
  }
  int ans=0;
  for(int i=0;i<x.size();i++)
  {
    if(vs[i])continue;int id=i-1;
    int f=x[i]-'0';ans++;
     while(true)
    {
      auto it=st[f].upper_bound(id);
      if(it==st[f].end())break;
       auto ti=st[f^1].upper_bound(*it);
      if(ti==st[f^1].end())break;
        id=*ti;vs[*it]=1,vs[*ti]=1;
      st[f].erase(*it);st[f^1].erase(*ti);
    }
  }
  cout<<ans<<endl;
  return 0;
}