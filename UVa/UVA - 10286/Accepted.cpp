/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-28 10:28:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10286
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double pi=acos(-1.0);
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  double a;
  while(cin>>a)
  {
    double A=(pi*3.0)/5.0,tmp=(pi*2.0)/4.0;
    double C=(A-tmp)/2.0;
    double B=pi-A-C;
    //cout<<B<<" "<<C<<endl;
    double ans=a*sin(A)/sin(B);
    cout<<setprecision(10)<<fixed<<ans<<endl;
  }
  return 0;
}