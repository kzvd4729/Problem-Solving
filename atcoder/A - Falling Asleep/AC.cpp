/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-11 17:02:22                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 5 ms                                            memory_used: 9984 KB                              
*  problem: https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s[N+2];int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;map<string,int>mp;
  for(int i=1;i<=n;i++)
  {
    cin>>s[i]>>aa[i];
    mp[s[i]]=i;
  }
  string ss;cin>>ss;int sm=0;
  for(int i=mp[ss]+1;i<=n;i++)
    sm+=aa[i];
  cout<<sm<<endl;
    return 0;
}