/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/02/2018 22:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/752/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,cnt;
bool l=false,r,u,d;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>s;
  cnt=1;
  for(auto x:s)
  {
    if(x=='L')
    {
      if(r)
      {
        cnt++;
        l=false,r=false,u=false,d=false;
      }
      l=true;
    }
    if(x=='R')
    {
      if(l)
      {
        cnt++;
        l=false,r=false,u=false,d=false;
      }
      r=true;
    }
    if(x=='U')
    {
      if(d)
      {
        cnt++;
        l=false,r=false,u=false,d=false;
      }
      u=true;
    }
    if(x=='D')
    {
      if(u)
      {
        cnt++;
        l=false,r=false,u=false,d=false;
      }
      d=true;
    }
  }
  cout<<cnt<<endl;
  return 0;
}