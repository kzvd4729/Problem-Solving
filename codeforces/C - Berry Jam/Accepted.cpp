/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/19/2019 21:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 18200 KB                             
*  problem: https://codeforces.com/contest/1278/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],pre[N+2],suf[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=2*n;i++)cin>>aa[i];
     map<int,int>mp;int ans=0;
    for(int i=1;i<=n;i++)
    {
      pre[i]=pre[i-1];
      if(aa[i]==1)pre[i]++;
      else pre[i]--;
       mp[pre[i]]=i;
      if(pre[i]==0)ans=max(ans,i);
    }
    suf[2*n+1]=0;
    for(int i=2*n;i>n;i--)
    {
      suf[i]=suf[i+1];
      if(aa[i]==1)suf[i]++;
      else suf[i]--;
       if(mp[-suf[i]])ans=max(ans,mp[-suf[i]]+2*n-i+1);
      if(suf[i]==0)ans=max(ans,2*n-i+1);
    }
    cout<<2*n-ans<<endl;
  }
  return 0;
}