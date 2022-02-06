/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 23:21                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/41/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int R=1e9;
const int N=2e3;
string s,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  ans.push_back(s[0]);
  int f=0;
  for(int i=1;i<s.size();i++)
  {
    if(i+3<s.size())
    {
      if(s.substr(i,3)=="dot")
      {
        ans.push_back('.');
        i+=2;
        continue;
      }
    }
    if(i+1<s.size()&&f==0)
    {
      if(s.substr(i,2)=="at")
      {
        ans.push_back('@');
        f=1;
        i++;
        continue;
      }
    }
    ans.push_back(s[i]);
  }
  cout<<ans<<endl;
  return 0;
}