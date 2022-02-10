/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 7 ms                                            memory_used: 736 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int d,t,v1,v2,net;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>d>>t>>v1>>v2;
  net=v1-v2;
  for(int i=1;i<=t;i++)
  {
    d-=net;
    if(d<=0)
    {
      cout<<i<<endl;
      return 0;
    }
  }
  for(int i=1; ;i++)
  {
    d-=v1;
    if(d<=0)
    {
      cout<<t+i<<endl;
      return 0;
    }
  }
  return 0;
}