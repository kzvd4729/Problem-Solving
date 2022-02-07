/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-02 14:21:10                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-1111
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;

const double eps=1e-9,pi=acos(-1.0);
int sgn(double d)
{
  if(fabs(d)<eps)return 0;return d<0.0?-1:1;
}
struct point
{
  double x,y;
  point(){};point(double _x,double _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(double d){return point(x*d,y*d);}
  point operator/(double d){return point(x/d,y/d);}
  bool operator==(point p){return x==p.x&&y==p.y;}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  double value(){return sqrt(x*x+y*y);}
  double dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
  point unitVector()
  {
    //invalid if vector is (0,0)
    double v=value();return point(x/v,y/v);
  }
  double operator*(point p)
  {
    return x*p.x+y*p.y;//0 if vectors are perpendicular;
  }
  double operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //signed area of the parallelogram by two vector
    //positive if p is ccw to the vector
  }
  point rotateCCW(double a)//radian
  {
    return point(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
  }
};
double modifiedatan2(point p)//clockwise full angle with positive x axis
{
  double ang=atan2(p.y,p.x);if(ang<0)ang+=pi+pi;//carefull
  return ang;//rad return 
}
struct line
{
  point p,v;//v is vector,going through p;
  line(){}
  line(point _p,point _v):p(_p),v(_v){}
  void makeLine(point p1,point p2){p=p1,v=p2-p1;}
  double pointDist(point p1)
  {
    //area of triangle/base of triangle
    return fabs((v^(p1-p))/v.value());//signed based on cw ans ccw
  }
};
struct polygon
{
  vector<point>p,h;
  polygon(){};
  polygon(vector<point>_p):p(_p){}
  void convexHull()
  {
    sort(p.begin(),p.end());int n=p.size(),top=0;//polygon are changed
    vector<point>stck(n+10);
    for(int i=n-1;i>=0;i--)
    {
      stck[++top]=p[i];//>=0 to omit straight line point;
      while(top>2)
      {
        if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>=0)
          stck[top-1]=stck[top],top--;
        else break;
      }
    }
    while(top>0)h.push_back(stck[top--]);
    for(int i=0;i<n;i++)
    {
      stck[++top]=p[i];//>=0 to omit straight line point;
      while(top>2)
      {
        if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>=0)
          stck[top-1]=stck[top],top--;
        else break;
      } 
    }
    top--;
    while(top>0)h.push_back(stck[top--]);
    if(h.size()>1)h.pop_back();
  }
  double cal()
  {
    h.push_back(h[0]);int n=h.size();double ans=1e9;
    for(int i=0;i<n-1;i++)
    {
      line l;l.makeLine(h[i],h[i+1]);double lmx=0;
      for(int j=0;j<n;j++)
      {
        lmx=max(lmx,l.pointDist(h[j]));
      }
      ans=min(ans,lmx);
    }
    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,tc=0;
  while(cin>>n)
  {
    if(!n)break;polygon p;p.p.resize(n);
    for(int i=0;i<n;i++)cin>>p.p[i].x>>p.p[i].y;
    p.convexHull();

    cout<<"Case "<<++tc<<": "<<setprecision(2)<<fixed<<p.cal()<<endl;
  }
  return 0;
}