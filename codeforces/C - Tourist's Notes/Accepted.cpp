/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/15/2019 23:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/538/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
    cin>>aa[i]>>bb[i];
  int ans=max(bb[1]+aa[1]-1,bb[m]+n-aa[m]);
   for(int i=2;i<=m;i++)
  {
    if(abs(aa[i]-aa[i-1])<abs(bb[i]-bb[i-1]))
      cout<<"IMPOSSIBLE"<<endl,exit(0);
    int xx=abs(aa[i]-aa[i-1])-abs(bb[i]-bb[i-1]);
    ans=max(ans,max(bb[i-1],bb[i])+xx/2);
  }
  cout<<ans<<endl;
  return 0;
}