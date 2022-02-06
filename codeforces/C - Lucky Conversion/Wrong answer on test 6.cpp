/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2018 15:44                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/146/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s,x;
int cnt;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s>>x;
  s.push_back('1');
  x.push_back('1');
  for(int i=0;i<s.size()-1;i++)
  {
    if(s[i]==x[i])continue;
    if(s[i+1]==x[i+1])cnt++;
    else
    {
      cnt++;
      s[i+1]=s[i];
    }
  }
  cout<<cnt<<endl;
  return 0;
}