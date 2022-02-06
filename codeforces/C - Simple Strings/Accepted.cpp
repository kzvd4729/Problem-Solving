/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/16/2019 16:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/665/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;s.push_back(';');
  for(int i=1;i<s.size()-1;i++)
  {
    if(s[i]!=s[i-1])continue;
    for(char j='a';j<='z';j++)
    {
      if(j!=s[i-1]&&j!=s[i+1])
      {
        s[i]=j;break;
      }
    }
  }
  s.pop_back();cout<<s<<endl;
  return 0;
}