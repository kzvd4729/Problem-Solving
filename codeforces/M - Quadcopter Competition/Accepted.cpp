/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/26/2018 20:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/883/problem/M
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
   int ans=1e8;
   int x=x2-1,y=y2;
  ans=min(ans,abs(x-x1)+abs(y-y1)+4);
   x=x2+1,y=y2;
  ans=min(ans,abs(x-x1)+abs(y-y1)+4);
   x=x2,y=y2-1;
  ans=min(ans,abs(x-x1)+abs(y-y1)+4);
   x=x2,y=y2+1;
  ans=min(ans,abs(x-x1)+abs(y-y1)+4);
   x=x2-1,y=y2-1;
  ans=min(ans,abs(x-x1)+abs(y-y1)+4);
   x=x2-1,y=y2+1;
  ans=min(ans,abs(x-x1)+abs(y-y1)+4);
   x=x2+1,y=y2+1;
  ans=min(ans,abs(x-x1)+abs(y-y1)+4);
   x=x2+1,y=y2-1;
  ans=min(ans,abs(x-x1)+abs(y-y1)+4);
   cout<<ans*2<<endl;
   return 0;
}