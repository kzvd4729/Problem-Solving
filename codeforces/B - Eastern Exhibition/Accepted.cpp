/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/18/2021 20:58                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1486/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
      cin>>a[i]>>b[i];
        sort(a+1,a+n+1);sort(b+1,b+n+1);
     long mn=1LL*inf*inf;
    vector<int>aa;
    for(int i=1;i<=n;i++)
    {
      long now=0;
      for(int j=1;j<=n;j++)now+=abs(a[i]-a[j]);
       if(now==mn)aa.push_back(a[i]);
      else if(now<mn)
      {
        mn=now;aa.clear();
        aa.push_back(a[i]);
      }
    }
    int u=aa.back()-aa[0]+1;
      mn=1LL*inf*inf;
    vector<int>bb;
    for(int i=1;i<=n;i++)
    {
      long now=0;
      for(int j=1;j<=n;j++)now+=abs(b[i]-b[j]);
       if(now==mn)bb.push_back(b[i]);
      else if(now<mn)
      {
        mn=now;bb.clear();
        bb.push_back(b[i]);
      }
    }
    int v=bb.back()-bb[0]+1;
     cout<<1LL*u*v<<endl;
   }
  return 0;
}