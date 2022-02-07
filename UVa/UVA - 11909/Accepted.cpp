/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-18 17:05:13                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11909
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/*************** Basic Geometry **************/
const double pi=acos(-1.0);
double DegreetoRadian(double x)
{
  return x*(pi/180.0);
}
double RadiantoDegree(double x)
{
  return x*(180.0/pi);
}
////////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  double l,w,h,th;
  while(cin>>l>>w>>h>>th)
  {
    double al=l*tan(DegreetoRadian(th)),ans;
    ans=l*h*w-0.5*l*al*w;
    if(al>h)ans+=0.5*(al-h)*tan(DegreetoRadian(90-th))*(al-h)*w;
    cout<<setprecision(3)<<fixed<<ans<<" mL"<<endl;
  }
  return 0;
}