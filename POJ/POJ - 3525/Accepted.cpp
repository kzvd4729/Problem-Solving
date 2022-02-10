/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-29 11:45:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 110                                        memory_used (MB): 0.8                             
*  problem: https://vjudge.net/problem/POJ-3525
****************************************************************************************/
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
#define long long long
using namespace std;
const int N=1e6;

#define setp(a) cout<<setprecision(a)<<fixed
const double eps=1e-9;
int sgn(double x)
{
  if(fabs(x)<=eps)return 0;
  return x>0?1:-1;
}
struct point
{
  double x,y;
  point(){}
  point(double _x,double _y):x(_x),y(_y){}
  point operator-(const point &p){return {x-p.x,y-p.y};}
  point operator+(const point &p){return {x+p.x,y+p.y};}
  point operator*(double d){return {x*d,y*d};}
  double operator^(const point &p){return x*p.y-y*p.x;}
};
struct line
{
  point p,v;double ang;
  line(){}
  line(point p1,point p2){p=p1,v=p2-p1;ang=atan2(v.y,v.x);}
  bool operator<(const line &l)const{return ang<l.ang;}
  point intersection(line l)
  {
    //care for parallel lines???
    double t=(l.v^(p-l.p))/(v^l.v);
    return p+v*t;
  }
};
/*
Lines are extended to infinity. There is a halfplane
in counter-clock side of every line.
Finds the common polygoan of those halfplane.
If lines are not bounded, infinity rectangle 
can be added. To include the point that doesn't 
generate area(intersection is a straight line) replace
eps with -eps.
*/
vector<point>halfPlaneIntersection(vector<line>&l)
{
  //lines are anti-clockwise
  int n=l.size();sort(l.begin(),l.end());
  int first=0,last=0;vector<point>poly;
  vector<point>p(n);vector<line>q(n);
  q[first]=l[0];
  for(int i=1;i<n;i++)
  {
    while(first<last&&(l[i].v^(p[last-1]-l[i].p))<=eps)last--;//<-eps
    while(first<last&&(l[i].v^(p[first]-l[i].p))<=eps)first++;//<-eps
    q[++last]=l[i];
    if(sgn(q[last].v^q[last-1].v)==0)
    {
      last--;
      if((q[last].v^(l[i].p-q[last].p))>eps)q[last]=l[i];//>=-eps
    }
    if(first<last)p[last-1]=q[last-1].intersection(q[last]);
  }
  while(first<last&&(q[first].v^(p[last-1]-q[first].p))<=eps)//<-eps
    last--;
  if(last-first<=1)return poly;
  p[last]=q[last].intersection(q[first]);
  for(int i=first;i<=last;i++)poly.push_back(p[i]);
  return poly;
}

//positive for anti-clockwise
//expected a non closed circuit
double polygoanArea(vector<point>&p)
{
  int n=p.size();double area=0;
  for(int i=1;i<n-1;i++)
    area+=(p[i]-p[0])^(p[i+1]-p[0]);
  return fabs(area/2.0);//signed
}


int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,tc=0;
  while(cin>>n)
  {
    if(!n)break;vector<point>v(n);
    for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
    //reverse(v.begin(),v.end());

    vector<line>l,tmp;
    for(int i=0;i<n;i++)
      l.push_back(line(v[i],v[(i+1)%n]));

    double lo=0,hi=1e9,md;
    while(hi-lo>eps)
    {
      md=(lo+hi)/2.0;tmp.clear();
      //cout<<md<<endl;
      for(int i=0;i<n;i++)
      {
        point v=point(-l[i].v.y,l[i].v.x);
        double d=sqrt(v.x*v.x+v.y*v.y);
        v.x/=d;v.y/=d;v=v*md;//
        line in=l[i];in.p=in.p+v;
        //cout<<in.p.x<<" "<<in.p.y<<endl;
        tmp.push_back(in);
      }
      //return 0;
      vector<point>poly=halfPlaneIntersection(tmp);
      //cout<<poly.size()<<endl;
      if(poly.size())lo=md;else hi=md;
    }
    setp(6);cout<<lo<<"\n";
  }
  return 0;
}