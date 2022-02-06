/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 13:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1184/problem/A1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long r;cin>>r;
   for(long x=1; ;x++)
  {
    long up=r-x*x-x-1;
    if(up<=0)break;
    if(up%(2*x)==0)
    {
      cout<<x<<" "<<up/(2*x)<<endl,exit(0);
    }
  }
  cout<<"NO"<<endl;
  return 0;
}