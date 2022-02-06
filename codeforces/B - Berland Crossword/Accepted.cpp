/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/02/2021 21:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1494/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,u,r,d,l;cin>>n>>u>>r>>d>>l;
     int f=0;
    for(int i=0;i<(1<<4);i++)
    {
      int uu=u,rr=r,dd=d,ll=l;
      if(i&(1<<0))ll--,uu--;
      if(i&(1<<1))uu--,rr--;
      if(i&(1<<2))rr--,dd--;
      if(i&(1<<3))dd--,ll--;
       if(uu<0||rr<0||dd<0||ll<0)continue;
      if(uu>n-2||rr>n-2||dd>n-2||ll>n-2)continue;
      f=1;
     } 
    if(f)cout<<"YES\n";else cout<<"NO\n";
  }  
  return 0;
}