/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/22/2020 22:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 11100 KB                             
*  problem: https://codeforces.com/contest/1294/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  vector<vector<int> >aa(n+3);
  for(int i=1;i<=n;i++)
  {
    aa[i].resize(m+3);
    for(int j=1;j<=m;j++)cin>>aa[i][j];
  }
  int ans=0;
  for(int j=1;j<=m;j++)
  {
    for(int i=1;i<=n;i++)
    {
      int x=aa[i][j];if((x-j)%m||(x-j)>(m*(n-1)))continue;
      //cout<<"*"<<x<<endl;
      int p=(x-j)/m+1;
      //cout<<x<<" ** "<<p<<endl;
       int d;
      if(p<=i)d=i-p;else d=i+n-p;
      cnt[d]++;//cout<<"*"<<d<<endl;
       if(d>=n)assert(0);
    }
    int mn=n;
    for(int i=0;i<n;i++)
    {
      mn=min(mn,i+n-cnt[i]);
      cnt[i]=0;
    }
    //cout<<"**"<<mn<<endl;
    ans+=mn; 
  }
  cout<<ans<<endl;
  return 0;
}