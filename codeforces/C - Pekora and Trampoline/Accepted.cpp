/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2021 20:28                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 109 ms                                          memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1491/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=5000,inf=1e9,mod=1e9+7;
 int a[N+2],par[N+2];
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     long ans=0;
    for(int i=1;i<=n+1;i++)par[i]=i;
    for(int i=1;i<=n;i++)if(a[i]==1)par[i]=i+1;
    while(true)
    {
      if(get(1)>n)break;
      int x=get(1);
       if(x==n)
      {
        ans+=a[n]-1;
        a[n]=1;break;
      }
      if(x+a[x]>n+1)
      {
        ans+=x+a[x]-(n+1);
        a[x]=n+1-x;
      }
      ans++;
      while(x<=n)
      {
        a[x]--;
        if(a[x]==1)par[x]=x+1;
        if(x+a[x]+1>n)break;
        x=get(x+a[x]+1);
      }
    }
    cout<<ans<<endl;
  }
    return 0;
}