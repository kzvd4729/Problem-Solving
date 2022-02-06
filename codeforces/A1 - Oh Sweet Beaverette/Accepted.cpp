/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 11900 KB                             
*  problem: https://codeforces.com/contest/331/problem/A1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long qm[N+2];int aa[N+2];
map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;qm[i]=qm[i-1]+max(x,0)*1LL;
    mp[x]=i;aa[i]=x;
  }
  long ans=-1e18;int a,b;
  for(int i=1;i<=n;i++)
  {
    int ls=mp[aa[i]];if(ls==i)continue;
    if(aa[i]+aa[i]+qm[ls-1]-qm[i]>ans)
    {
      ans=aa[i]+aa[i]+qm[ls-1]-qm[i];
      a=i,b=ls;
    }
  }
  cout<<ans<<" ";int cnt=0;
  for(int i=a+1;i<b;i++)
  {
    if(aa[i]<0)cnt++;
  }
  cout<<cnt+a-1+n-b<<endl;
  for(int i=1;i<a;i++)cout<<i<<" ";
  for(int i=a+1;i<b;i++)
  {
    if(aa[i]<0)cout<<i<<" ";
  }
  for(int i=b+1;i<=n;i++)
    cout<<i<<" ";
  return 0;
}