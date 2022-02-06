/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2020 10:52                        
*  solution_verdict: Wrong answer on test 53                 language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1329/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],ans[N+2];
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
  int em=n;
  for(int i=1;i<=m;i++)
    em=min(em,n-(i+aa[i]-1));
  int ad=0;
  for(int i=1;i<=m;i++)
  {
    ans[i]=i+ad;if(i==m)continue;
    if(aa[i]-1<em)em-=(aa[i]-1),ad+=aa[i]-1;
    else {ad+=em;em=0;}
  }
  if(em)no();
  for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    cout<<endl;
  return 0;
}