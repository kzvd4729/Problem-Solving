/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-10 16:09:58                      
*  solution_verdict: Runtime error                           language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10221
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double pi=acos(-1.0);
const double eps=1e-9;
double degToRad(double x)
{
  return (pi/180.0)*x;
}
double minToDeg(double x)
{
  return x/60.0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cout<<setprecision(6)<<fixed;
  double a,b;string c;
  while(cin>>a>>b>>c)
  {
    if(c=="min")b=minToDeg(b);

    if(b>180.0)assert(0);
    double r=6440.0+a;
    double arc=b/360.0*2*pi*r;
    
    double chord=sqrt(r*r+r*r-2*r*r*cos(degToRad(b)));

    cout<<arc+eps<<" "<<chord+eps<<endl;
  }
  return 0;
}