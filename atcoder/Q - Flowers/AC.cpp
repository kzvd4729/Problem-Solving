/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-11 09:27:28                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 52 ms                                           memory_used: 14080 KB                             
*  problem: https://atcoder.jp/contests/dp/tasks/dp_q
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
/*************** BIT *****************/
long Bit[N+2];
void Upd(int x,long vl)
{
  for( ;x<=N;x+=(x&-x))
    Bit[x]=max(Bit[x],vl);
}
long Sum(int x)
{
  long sum=0;
  for( ;x>0;x-=(x&-x))
    sum=max(sum,Bit[x]);
  return sum;
}
////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long ans=0;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)cin>>bb[i];
  for(int i=1;i<=n;i++)
  {
    long mx=Sum(aa[i]);
    Upd(aa[i],mx+bb[i]);
    ans=max(ans,mx+bb[i]);
  }
  cout<<ans<<endl;
  return 0;
}