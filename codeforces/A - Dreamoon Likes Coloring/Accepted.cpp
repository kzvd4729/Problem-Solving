/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2020 11:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/1329/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],mx[N+2],ans[N+2];
void no()
{
  cout<<-1<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>aa[i];
    if(i+aa[i]-1>n)no();
  }
  for(int i=m;i>=1;i--)
    mx[i]=max(mx[i+1],i+aa[i]-1);
  int pr=0;
  for(int i=1;i<=m;i++)
  {
    int mn=min(pr-i+1,n-mx[i]);
    ans[i]=i+mn;pr=max(pr,ans[i]+aa[i]-1);
  }
  if(pr!=n)no();
  for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    cout<<endl;
  return 0;
}