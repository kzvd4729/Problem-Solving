/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2019 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1221/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int m,c,x;
bool isOk(int md)
{
  return (c-md+m-md+x)>=md;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>m>>c>>x;
    int lo=0,hi=min(m,c),md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(isOk(md))lo=md;
      else hi=md;
    }
    for(md=hi;md>=lo;md--)
    {
      if(isOk(md)){cout<<md<<"\n";break;}
    }
  }
  return 0;
}