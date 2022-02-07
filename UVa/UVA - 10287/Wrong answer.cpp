/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-22 21:07:36                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10287
****************************************************************************************/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const double eps=1e-9;
const double pi=acos(-1.0);
double apothem(double s,double n)
{
  return s/(2*tan(pi/n));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cout<<setprecision(10)<<fixed;
  double x;while(cin>>x)
  {
    double ap=apothem(x,6);
    //double cr=sqrt(ap*ap+x*x);
    //cout<<cr<<endl;
    cout<<ap<<" "<<ap*0.0000000464/0.0000000866<<" "<<ap*0.0000000433/0.0000000866<<" "<<ap*0.0000000375/0.0000000866<<endl;
  }
  
  return 0;
}