/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/29/2020 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1295/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;string ans;
    if(n%2==0)
    {
      for(int i=1;i<=n/2;i++)ans.push_back('1');
    }
    else
    {
      ans.push_back('7');n-=3;
      for(int i=1;i<=n/2;i++)ans.push_back('1');
    }
    cout<<ans<<"\n";
  }
  return 0;
}