/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2018 21:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1009/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int one,zero,two;
string s,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='1')one++;
    if(s[i]=='2')two++;
  }
  if(two==0)
  {
    sort(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
  }
  int f=0;
  for(int i=0;i<s.size();i++)
  {
    if(f==0)if(s[i]=='0')zero++;
    if(s[i]=='2'&&f==0)
    {
      while(zero--)
        ans.push_back('0');
      while(one--)
        ans.push_back('1');
      f=1;
    }
    if(f&&s[i]!='1')
      ans.push_back(s[i]);
  }
  cout<<ans<<endl;
  return 0;
}