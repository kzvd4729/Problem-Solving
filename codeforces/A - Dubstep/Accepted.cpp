/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2018 17:59                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/208/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  s.push_back('a');
  s.push_back('a');
  s.push_back('a');
  for(int i=0;i<s.size()-3;i++)
  {
    if(s.substr(i,3)=="WUB")
    {
      s.erase(s.begin()+i,s.begin()+i+2);
      if(ans.size()==0)continue;
      if(ans.back()==' ')continue;
      ans.push_back(' ');
      //i--;
    }
    else
      ans.push_back(s[i]);
  }
  cout<<ans<<endl;
  return 0;
}