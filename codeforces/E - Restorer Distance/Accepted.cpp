/****************************************************************************************
*  @author: * kzvd4729                                       created: May/16/2020 18:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/1355/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2],qm[N+2];
int n,a,r,m;
long ck(long md)
{
  long ad=0,rm=0;//cout<<md<<endl;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]<md)ad+=md-aa[i];
    else rm+=aa[i]-md;
  }
  long mn=min(ad,rm);
  return mn*m+(ad-mn)*a+(rm-mn)*r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>a>>r>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
   sort(aa+1,aa+n+1);
  for(int i=1;i<=n;i++)qm[i]=qm[i-1]+aa[i];
  long ans=1e18;
  for(int i=1;i<=n;i++)
  {
    long rm=qm[n]-qm[i]-aa[i]*(n-i);
    long ad=aa[i]*(i-1)-qm[i-1];
    long mn=min(rm,ad);
    long now=min(ad*a+rm*r,mn*m+(ad-mn)*a+(rm-mn)*r);
    ans=min(ans,now);
  }
  long md=qm[n]/n;//cout<<md<<endl;
  for(long i=max(0LL,md-100);i<=md+100;i++)
    ans=min(ans,ck(i));
  cout<<ans<<endl;
  return 0;
}