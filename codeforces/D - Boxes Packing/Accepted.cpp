/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/12/2018 22:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1066/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],n,m,k;
bool ok(int id)
{
  int box=0,cap=0;
  for(int i=id;i<=n;i++)
  {
    if(cap+aa[i]>k)
    {
      box++;cap=aa[i];
    }
    else cap+=aa[i];
  }
  if(cap)box++;
  return box<=m;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int lo=1,hi=n,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ok(md))hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(ok(md))break;
  cout<<n-md+1<<endl;
  return 0;
}