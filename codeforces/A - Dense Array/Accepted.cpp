/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/16/2021 20:38                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1490/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int a[N+2];
int cal(int x,int y)
{
  int cnt=0;
  while(true)
  {
    if(x*2>=y)return cnt;
    x*=2;cnt++;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
      ans+=cal(min(a[i],a[i+1]),max(a[i],a[i+1]));
    }
    cout<<ans<<endl;
  }
     return 0;
}