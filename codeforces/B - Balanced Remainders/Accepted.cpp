/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/16/2021 20:45                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1490/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    a[0]=0;a[1]=0,a[2]=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      a[x%3]++;
    }
    int tr=n/3,ans=0;
     if(a[0]>tr)
    {
      ans+=a[0]-tr;
      a[1]+=a[0]-tr;
       a[0]=tr;
    }
    if(a[1]>tr)
    {
      ans+=a[1]-tr;
      a[2]+=a[1]-tr;
       a[1]=tr;
    }
    if(a[2]>tr)
    {
      ans+=a[2]-tr;
      a[0]+=a[2]-tr;
       a[2]=tr;
    }
    if(a[0]>tr)
    {
      ans+=a[0]-tr;
      a[1]+=a[0]-tr;
       a[0]=tr;
    }
    if(a[1]>tr)
    {
      ans+=a[1]-tr;
      a[2]+=a[1]-tr;
       a[1]=tr;
    }
    if(a[2]>tr)
    {
      ans+=a[2]-tr;
      a[0]+=a[2]-tr;
       a[2]=tr;
    }
    cout<<ans<<endl;
  }
  return 0;
}