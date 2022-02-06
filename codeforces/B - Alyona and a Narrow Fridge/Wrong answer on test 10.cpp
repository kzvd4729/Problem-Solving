/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2019 22:48                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1119/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,h;cin>>n>>h;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int lo=1,hi=n+1,md,ans;
  while(lo<hi)
  {
    md=(lo+hi)/2;vector<int>v;
    for(int i=1;i<=md;i++)
      v.push_back(aa[i]);
    sort(v.begin(),v.end(),greater<int>());
    int ad=0;
    for(int i=0;i<v.size();i+=2)
      ad+=v[i];
    if(ad<=h)ans=md,lo=md+1;
    else hi=md;
  }
  cout<<ans<<endl;
  return 0;
}