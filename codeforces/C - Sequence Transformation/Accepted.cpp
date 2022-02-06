/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2018 18:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1059/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int pw=1;
  while(n)
  {
    if(n==1)
    {
      cout<<pw<<" ";
      n--;
    }
    else if(n==3)
    {
      cout<<pw<<" "<<pw<<" "<<pw*3<<" ";
      n-=3;
    }
    else
    {
      int rm=n-n/2;n-=rm;
      while(rm--)
        cout<<pw<<" ";
    }
    pw*=2;
  }
  cout<<endl;
  return 0;
}