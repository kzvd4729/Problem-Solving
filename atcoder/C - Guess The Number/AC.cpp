/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-01 18:15:27                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 2304 KB                              
*  problem: https://atcoder.jp/contests/abc157/tasks/abc157_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int d(int x)
{
  if(x==0)return 1;
  int ret=0;
  while(x)
  {
    ret++;x/=10;
  }
  return ret;
}
int th(int x,int i)
{
  if(x==0)return 0;
  vector<int>v;
  while(x)
  {
    v.push_back(x%10);x/=10;
  }
  reverse(v.begin(),v.end());
  return v[i-1];
}
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
    cin>>aa[i]>>bb[i];
   for(int i=0;i<=10000;i++)
  {
    if(d(i)!=n)continue;
     int f=0;
    for(int j=1;j<=m;j++)
    {
      if(th(i,aa[j])!=bb[j])f=1;
    }
    if(!f)cout<<i<<endl,exit(0);
  }
  cout<<-1<<endl;
  return 0;
}