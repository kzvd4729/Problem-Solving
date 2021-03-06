/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2020 19:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1343/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],qm[N+2];
void upd(int l,int r,int ad)
{
  if(l>r)return ;
  qm[l]+=ad;qm[r+1]-=ad;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n/2;i++)
    {
      int a=aa[i],b=aa[n-i+1];
      upd(2,min(a,b),2);
      upd(min(a,b)+1,a+b-1,1);
      upd(a+b+1,k+max(a,b),1);
      upd(k+max(a,b)+1,k+k,2);
    }
    int ans=inf;
    for(int i=2;i<=k+k;i++)
    {
      qm[i]+=qm[i-1];ans=min(ans,qm[i]);
    }
    cout<<ans<<"\n";
    for(int i=1;i<=k+k+2;i++)qm[i]=0;
  }
  return 0;
}