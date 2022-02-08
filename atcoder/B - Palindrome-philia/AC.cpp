/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-08 18:03:30                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc147/tasks/abc147_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();
   int ans=0;
  for(int i=0;i<n/2;i++)
   if(s[i]!=s[n-1-i])ans++;
  cout<<ans<<endl;
    return 0;
}