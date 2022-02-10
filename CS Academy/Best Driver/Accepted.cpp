/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 17 ms                                           memory_used: 700 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    double a,b,c1,c2;cin>>a>>b>>c1>>c2;
    c1/=100.0;c2/=100.0;
    //cout<<a*c1<<" "<<(a+b)*c2<<endl;
    double lo=0,hi=1e9,md;int loop=100;
    while(loop--)
    {
      md=(lo+hi)/2.0;
      if(a*c1+md*b>c2*(a+b))hi=md;
      else lo=md;
    }
    md*=100;
    cout<<setprecision(9)<<fixed;
    cout<<md<<endl;
  }
  return 0;
}