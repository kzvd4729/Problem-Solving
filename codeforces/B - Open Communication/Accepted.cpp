/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2020 20:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/993/problem/B
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
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i].first>>a[i].second;
    if(a[i].first>a[i].second)swap(a[i].first,a[i].second);
  }
  for(int i=1;i<=m;i++)
  {
    cin>>b[i].first>>b[i].second;
    if(b[i].first>b[i].second)swap(b[i].first,b[i].second);
  }
  set<int>st1,st2;
  for(int i=1;i<=n;i++)
  {
    int f=0,l=0;
    for(int j=1;j<=m;j++)
    {
      if(a[i]==b[j])continue;
      if(a[i].first==b[j].first||a[i].first==b[j].second)f=1;
      if(a[i].second==b[j].first||a[i].second==b[j].second)l=1;
    }
    if(f&l)cout<<-1<<endl,exit(0);
    if(f)st1.insert(a[i].first);
    if(l)st1.insert(a[i].second);
  }
  for(int j=1;j<=m;j++)
  {
    int f=0,l=0;
    for(int i=1;i<=n;i++)
    {
      if(a[i]==b[j])continue;
      if(a[i].first==b[j].first||a[i].second==b[j].first)f=1;
      if(a[i].first==b[j].second||a[i].second==b[j].second)l=1;
    }
    if(f&l)cout<<-1<<endl,exit(0);
    if(f)st2.insert(b[j].first);
    if(l)st2.insert(b[j].second);
  }
  if(st1.size()==1&&st1==st2)cout<<*st1.begin()<<endl;
  else cout<<0<<endl;
  return 0;
}