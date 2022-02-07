/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-27 10:18:27                      
*  solution_verdict: Compilation error                       language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11152
****************************************************************************************/
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