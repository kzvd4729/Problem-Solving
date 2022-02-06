/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/06/2019 19:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1132/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long w,aa[10],f;
void dfs(long w,long i)
{
  if(w==0)
  {
    f=1;return ;
  }
  if(i<1)return ;
  long mx=min(w/i,aa[i]);
  for(long j=mx;j>=max(0LL,mx-5);j--)
    dfs(w-i*j,i-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>w;for(int i=1;i<=8;i++)cin>>aa[i];
   long mx=0;
  for(int i=1;i<=8;i++)
    mx+=(i*aa[i]);
  if(mx<=w)cout<<mx<<endl,exit(0);
  while(true)
  {
    f=0;dfs(w,8);
    if(f)cout<<w<<endl,exit(0);
    w--;
  }
  return 0;
}