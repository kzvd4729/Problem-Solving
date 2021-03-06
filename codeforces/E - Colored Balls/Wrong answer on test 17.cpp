/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2019 18:10                        
*  solution_verdict: Wrong answer on test 17                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/792/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long inf=1e18;
int aa[N+2],n;
long ck(int x)
{
  if(x<0)return inf;
  long ret=0;
  for(int i=1;i<=n;i++)
  {
    int ad=(aa[i]+x)/(x+1);
    if(ad*(x+1)-aa[i]>ad)return inf;
    ret+=ad;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
   long ans=1e18;
  for(int i=1;i<=2*sqrt(aa[1]);i++)
  {
    ans=min(ans,ck(i));
    ans=min(ans,ck(aa[1]/i));
    //ans=min(ans,ck((aa[1]/i)-1));
  }
  cout<<ans<<endl;
  return 0;
}