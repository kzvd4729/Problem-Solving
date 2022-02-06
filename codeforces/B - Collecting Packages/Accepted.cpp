/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/22/2020 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 9800 KB                              
*  problem: https://codeforces.com/contest/1294/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>pp[i].first>>pp[i].second;
    sort(pp+1,pp+n+1);string ans;int f=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=pp[i-1].first;j<pp[i].first;j++)
        ans.push_back('R');
      for(int j=pp[i-1].second;j<pp[i].second;j++)
        ans.push_back('U');
      if(pp[i].second<pp[i-1].second)f=1;
    }
    if(f)cout<<"NO\n";
    else
    {
      cout<<"YES\n";cout<<ans<<"\n";
    }
  }
  return 0;
}