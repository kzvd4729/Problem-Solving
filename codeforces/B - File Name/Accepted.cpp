/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2018 12:29                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/978/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,cnt,ans;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  cin>>s;
  s.push_back('q');
  for(int i=0;i<=n;i++)
  {
    if(s[i]=='x')cnt++;
    else
    {
      ans+=max(0,cnt-2);
      cnt=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}