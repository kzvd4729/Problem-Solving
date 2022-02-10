/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 8 ms                                            memory_used: 660 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int a,h,l,nl,nh;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>l>>h;
  for(int i=1;i<=a;i++)
  {
    if((a-i+1)*4==l&&(a-i+1)==h)
    {
      cout<<a-i+1<<endl;
      return 0;
    }
    nl=(a-i+1)*4;
    if(nl>l)l-=2;
    else
    {
      l-=4;
      h-=2;
    }
  }
  cout<<0<<endl;
  return 0;
}