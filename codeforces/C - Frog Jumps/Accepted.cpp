/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/12/2020 19:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 16200 KB                             
*  problem: https://codeforces.com/contest/1324/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
vector<int>po[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;int ans=0;
    int cnt=0;
    for(auto x:s)
    {
      if(x=='L')cnt++;else cnt=0;
      ans=max(ans,cnt);
    }
    cout<<ans+1<<"\n";
  }
  return 0;
}