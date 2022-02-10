/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 8 ms                                            memory_used: 656 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,ln,now,id,w,ck;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>w;
  id=1;
  for(int i=1;i<=n;i++)
  {
    cin>>ck>>ln;
    if(ck)
    {
      now+=ln;
      if(now>=w)cout<<id<<endl,exit(0);
    }
    else
    {
      now=0;
      id=i+1;
    }
  }
  cout<<-1<<endl;
  return 0;
}