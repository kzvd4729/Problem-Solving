/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/21/2019 13:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1216/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>pp[i].first,pp[i].second=i;
  sort(pp+1,pp+n+1);
  long ans=0,cnt=0;
  for(int i=n;i>=1;i--)
  {
    ans+=cnt*pp[i].first+1;
    cnt++;
  }
  cout<<ans<<endl;
  for(int i=n;i>=1;i--)
    cout<<pp[i].second<<" ";
  cout<<endl;
  return 0;
}