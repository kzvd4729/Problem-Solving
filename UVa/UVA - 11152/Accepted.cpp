/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-27 10:17:32                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11152
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;

#define setp(a) cout<<setprecision(a)<<fixed
const double eps=1e-9;
const double pi=acos(-1.0);
double triangleArea(double a,double b,double c)
{
  double s=(a+b+c)/2.0;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}
double circumRadiusofTriangle(double a,double b,double c)
{
  double dn=triangleArea(a,b,c);
  return (a*b*c)/(4*dn);
}
double incircleRadiusofTriangle(double a,double b,double c)
{
  double ar=triangleArea(a,b,c);
  return (2*ar)/(a+b+c);
}
double circleArea(double r)
{
  return pi*r*r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  double a,b,c;
  while(cin>>a)
  {
    cin>>b>>c;
    double bigr=circumRadiusofTriangle(a,b,c);
    double smlr=incircleRadiusofTriangle(a,b,c);
    double rose=circleArea(smlr);
    double vio=triangleArea(a,b,c)-rose;
    double sunf=circleArea(bigr)-vio-rose;
    setp(4);cout<<sunf<<" "<<vio<<" "<<rose<<"\n";
  }
  return 0;
}