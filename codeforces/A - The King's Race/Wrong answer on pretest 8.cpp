/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2018 00:21                        
*  solution_verdict: Wrong answer on pretest 8               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1075/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,x,y;cin>>n>>x>>y;
   if(x==n&&y==n)
  {
    cout<<"Black"<<endl;exit(0);
  }
  long wh=max(x-1,y-1);
  long bl=max(n-x,n-y);
  bl++;
  if(wh>bl)cout<<"Black"<<endl;
  else cout<<"White"<<endl;
   return 0;
}