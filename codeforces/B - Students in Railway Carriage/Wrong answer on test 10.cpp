/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2018 20:49                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/962/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,a,b,cnt,print;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b;
  cin>>s;
  if(a<b)swap(a,b);
  for(auto x:s)
  {
    if(x=='*')
    {
      if(a<b)swap(a,b);
      cnt=0;
      continue;
    }
    if(cnt%2==0)
    {
      if(a==0)break;
      a--;
    }
    else
    {
      if(b==0)break;
      b--;
    }
    cnt++;
    print++;
  }
  cout<<print<<endl;
  return 0;
}