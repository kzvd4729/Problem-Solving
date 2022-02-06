/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2019 21:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1139/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;string s;cin>>n>>s;long ans=0;
  for(int i=0;i<n;i++)
  {
    int x=s[i]-'0';
    if(x%2==0)ans+=(i+1)*1LL;
  }
  cout<<ans<<endl;
  return 0;
}