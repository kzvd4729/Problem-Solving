/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 17:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 514 ms                                          memory_used: 41100 KB                             
*  problem: https://codeforces.com/contest/1208/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=(1<<21);
int dp[N+2],aa[N+2],po1[N+2],po2[N+2],fr[N+2];
void upd(int i,int x)
{
  if(i>po1[x])
  {
    po2[x]=po1[x];po1[x]=i;
  }
  else if(i>po2[x])po2[x]=i;
}
void sos(int n)
{
  for(int i=0;i<(1<<n);i++)
    dp[i]=fr[i];
  for(int i=0;i<n;i++)
  {
    for(int msk=(1<<n)-1;msk;msk--)
    {
      if(!(msk&(1<<i)))
      {
        int nms=msk^(1<<i);
        dp[msk]+=dp[nms];
        upd(po1[nms],msk);upd(po2[nms],msk);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];fr[aa[i]]++;
    upd(i,aa[i]);
  }
  sos(21);int mx=0;
  for(int i=1;i<=n-2;i++)
  {
    int now=aa[i],msk=0;
    for(int j=21;j>=0;j--)
    {
      if(now&(1<<j))continue;
      msk|=(1<<j);
      if(po2[msk]<=i)msk^=(1<<j);
      else now|=(1<<j);
    }
    mx=max(mx,now);
  }
  cout<<mx<<endl;
  return 0;
}