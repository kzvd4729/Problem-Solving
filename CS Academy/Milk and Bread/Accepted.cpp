/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 7 ms                                            memory_used: 676 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int a,b,c,d,e;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>b>>c;
  int d=abs(c-a)+abs(a-b);
  int e=abs(c-b)+abs(b-a);
  cout<<min(d,e)<<endl;
  return 0;
}