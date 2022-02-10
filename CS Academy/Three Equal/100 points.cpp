/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 100 points                              language: C++                                     
*  run_time: 8 ms                                            memory_used: 676 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int s0,s1,s2,x,n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    s0+=(3-x)%3;
    s1+=(4-x)%3;
    s2+=(5-x)%3;
  }
  cout<<min(s0,min(s1,s2))<<endl;
  return 0;
}