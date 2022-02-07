/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-18 16:17:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11152
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double pi=acos(-1.0);
double Triangle_Area_From_Three_Sides(double a,double b,double c)
{
  double s=(a+b+c)/2.0;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}
double Circum_Radius_of_Triangle_From_Three_Sides(double a,double b,double c)
{
  double dn=Triangle_Area_From_Three_Sides(a,b,c);
  return (a*b*c)/(4*dn);
}
double Incircle_Radius_of_Triangle_From_Three_Sides(double a,double b,double c)
{
  double ar=Triangle_Area_From_Three_Sides(a,b,c);
  return (2*ar)/(a+b+c);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  double a,b,c;
  while(cin>>a>>b>>c)
  {
    double rr=Circum_Radius_of_Triangle_From_Three_Sides(a,b,c);

    double bigcir=pi*rr*rr;

    double tri=Triangle_Area_From_Three_Sides(a,b,c);

    double r=Incircle_Radius_of_Triangle_From_Three_Sides(a,b,c);

    double smlcir=pi*r*r;

    cout<<setprecision(4)<<fixed<<bigcir-tri<<" "<<tri-smlcir<<" "<<smlcir<<endl;

  }
  return 0;
}