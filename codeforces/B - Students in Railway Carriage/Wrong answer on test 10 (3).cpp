/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2018 22:00                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/962/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,a,b,cnt,print,f;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b;
  cin>>s;
   if(a<b)swap(a,b);
  cnt=0;
  f=1;
  for(auto x:s)
  {
    if(x=='*')
    {
      if(a<b)swap(a,b);
      cnt=0;
      f=1;
      continue;
    }
    if(f==0)continue;
    if(cnt%2==0)
    {
      if(a==0)f=0;
      else print++,a--;
    }
    else
    {
      if(b==0)f=0;
      else print++,b--;
    }
    cnt++;
  }
  cout<<print<<endl;
  return 0;
}