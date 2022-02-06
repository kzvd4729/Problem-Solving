/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/23/2018 13:47                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/697/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s,a,b,d;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  int i;
  for(i=0;i<s.size();i++)
  {
    if(s[i]=='.')break;
    a.push_back(s[i]);
  }
  for(++i;i<s.size();i++)
  {
    if(s[i]=='e')break;
    b.push_back(s[i]);
  }
  for(++i;i<s.size();i++)
  {
    d.push_back(s[i]);
  }
  stringstream ss;
  ss<<d;
  int dd;
  ss>>dd;
   if(a[0]=='0')a.pop_back();
   reverse(b.begin(),b.end());
  while(dd--)
  {
    if(b.size()==0)
      a.push_back('0');
    else
    {
      a.push_back(b.back());
      b.pop_back();
    }
  }
  reverse(b.begin(),b.end());
  while(b.size())
  {
    if(b.back()=='0')b.pop_back();
    else break;
  }
  if(a.size()==0&&b.size()==0)cout<<0<<endl;
  else if(b.size()==0)cout<<a<<endl;
  else if(a.size()==0)cout<<"0."<<b<<endl;
  else cout<<a<<"."<<b<<endl;
  return 0;
}