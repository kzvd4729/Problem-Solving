/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/21/2018 22:43                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/474/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long R=1e15;
long aa[N+2],dp[N+2];
map<long,int>bit,btt;
void upd(long x,int vl)
{
  for( ;x<=R;x+=x&-x)
    bit[x]=max(bit[x],vl);
}
int qry(long x)
{
  int mx=0;
  for( ;x>0;x-=x&-x)
    mx=max(mx,bit[x]);
  return mx;
}
void _upd(long x,int vl)
{
  for( ;x>0;x-=x&-x)
    btt[x]=max(btt[x],vl);
}
int _qry(long x)
{
  int mx=0;
  for( ;x<=R;x+=x&-x)
    mx=max(mx,btt[x]);
  return mx;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,d;cin>>n>>d;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=n;i>=1;i--)
  {
    dp[i]=max(qry(aa[i]-d),_qry(aa[i]+d))+1;
    upd(aa[i],dp[i]);_upd(aa[i],dp[i]);
  }
  // for(int i=1;i<=n;i++)
  //   cout<<dp[i]<<" ";
  // cout<<endl;
   int ans=dp[1];
  cout<<ans<<endl;cout<<1<<" ";long last=aa[1];
  for(int i=2;i<=n;i++)
  {
    if(dp[i]==ans-1&&abs(aa[i]-last)>=d)
    {
      cout<<i<<" ";last=aa[i];ans--;
    }
  }
  cout<<endl;
  return 0;
}