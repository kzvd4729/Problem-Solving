/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-10 18:11:57                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 20 ms                                           memory_used: 5248 KB                              
*  problem: https://atcoder.jp/contests/abc150/tasks/abc150_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
   vector<int>v;
  for(int i=1;i<=n;i++)
    v.push_back(i);
  map<vector<int>,int>mp;
  int cnt=0;
  do
  {
    mp[v]=++cnt;
  }while(next_permutation(v.begin(),v.end()));
  vector<int>a(n),b(n);
  for(int i=1;i<=n;i++)cin>>a[i-1];
  for(int i=1;i<=n;i++)cin>>b[i-1];
   cout<<abs(mp[a]-mp[b])<<endl;
   return 0;
}