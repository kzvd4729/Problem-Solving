/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/17/2019 15:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 390 ms                                          memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/632/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2],ans[N+2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;aa[i]=x;
    if(x<=m)fr[x]++;
  }
  for(int i=1;i<=m;i++)
  {
    if(!fr[i])continue;
    for(int j=i;j<=m;j+=i)
      ans[j]+=fr[i];
  }
  int mx=0,nm;
  for(int i=1;i<=m;i++)
  {
    if(ans[i]>mx)
    {
      mx=ans[i];nm=i;
    }
  }
  cout<<nm<<" "<<mx<<endl;
  for(int i=1;i<=n;i++)
    if(nm%aa[i]==0)cout<<i<<" ";
  cout<<endl;
  return 0;
}