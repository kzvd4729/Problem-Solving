/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2019 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1167/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;string s;cin>>s;
    reverse(s.begin(),s.end());
    while(true)
    {
      if(s.size()==0)break;
      if(s.back()!='8')s.pop_back();
      else break;
    }
    if(s.size()>=11)cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}