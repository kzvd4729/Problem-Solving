/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2018 21:04                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1055/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,l;cin>>n>>m>>l;
  for(int i=1;i<=n;i++)
    cin>>aa[i]; 
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]>l&&aa[i-1]<=l)ans++;
  }
  while(m--)
  {
    int ty;cin>>ty;
    if(ty==0)cout<<ans<<"\n";
    else
    {
      int id,vl;cin>>id>>vl;
      if(aa[id]>l)continue;
      aa[id]+=(vl*1LL);
      if(aa[id-1]<=l&&aa[id+1]<=l)ans++;
      else if(aa[id-1]>l&&aa[id+1]>l)ans--;
    }
  }
  return 0;
}