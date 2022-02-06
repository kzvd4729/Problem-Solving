/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 18:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/509/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2,inf=1e9;
int aa[N+2],mt[N+2][N+2],pt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int mx=*max_element(aa+1,aa+n+1);
    int cl=0,f=1;
  for(int i=1;i<=mx;i++)
  {
    if(f)f=0,++cl;
    for(int j=1;j<=n;j++)
    {
      if(aa[j]<i)f=1;
      else mt[j][i]=cl;
    }
  }
  if(cl>k)cout<<"NO\n",exit(0);
  cout<<"YES\n";
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=mx;j++)
      if(mt[i][j])cout<<mt[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}