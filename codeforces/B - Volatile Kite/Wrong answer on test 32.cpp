/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2020 11:55                        
*  solution_verdict: Wrong answer on test 32                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1700 KB                              
*  problem: https://codeforces.com/contest/800/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define long long long
using namespace std;
const int N=1e5;
struct point
{
  double x,y;
  point(){};point(double _x,double _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(double d){return point(x*d,y*d);}
  point operator/(double d){return point(x/d,y/d);}
  double dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
  double operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //signed area of the parallelogram by two vector
    //positive if p is ccw to the vector
  }
}aa[N+2];
double area(point a,point b,point c)
{
  return fabs(0.5*((b-a)^(c-a)));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n;i++)cin>>aa[i].x>>aa[i].y;
  aa[n]=aa[0];
  double ans=1e9; 
  for(int i=1;i<n;i++)
  {
    double ar=area(aa[i],aa[i-1],aa[i+1]);
    double b=ar/aa[i-1].dist(aa[i+1]);
    ans=min(ans,b);
  }
  cout<<setprecision(6)<<fixed<<ans<<endl;
  return 0;
}