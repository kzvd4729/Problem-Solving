/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/03/2018 21:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1003/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int a,b,x;
string s;
void case1(int aa,int bb)
{
  if(x==1)
  {
    while(aa>0)
      s.push_back('0'),aa--;
  }
  else
  {
    s.push_back('0');
    aa--;
  }
  while(x)
  {
    if(x==1)
    {
      if(s.back()=='1')
        while(aa>0)
          s.push_back('0'),aa--;
      else
        while(bb>0)
          s.push_back('1'),bb--;
      x--;
    }
    else if(x==2)
    {
      if(s.back()=='0')
        while(bb>0)
          s.push_back('1'),bb--;
      else
        while(aa>0)
          s.push_back('0'),aa--;
      x--;
    }
    else
    {
      if(s.back()=='0')
      {
        s.push_back('1');
        bb--;
      }
      else
      {
        s.push_back('0');
        aa--;
      }
      x--;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>x;
   if(a>=b)
  {
    case1(a,b);
    cout<<s<<endl;
  }
   else
  {
    swap(a,b);
    case1(a,b);
    for(auto xx:s)
    {
      if(xx=='0')cout<<'1';
      else cout<<'0';
    }
    cout<<endl;
  }
    return 0;
}