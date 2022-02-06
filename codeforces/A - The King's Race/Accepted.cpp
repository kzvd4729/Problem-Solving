/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2018 00:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
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
   long wh=max(x,y);
  long bl=max(n-x,n-y);
   //cout<<wh<<" "<<bl<<endl;
   bl++;
  if(wh>bl)cout<<"Black"<<endl;
  else cout<<"White"<<endl;
   return 0;
}