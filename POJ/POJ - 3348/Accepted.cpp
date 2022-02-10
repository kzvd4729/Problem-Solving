/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-09 17:56:28                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 94                                         memory_used (MB): 0.7                             
*  problem: https://vjudge.net/problem/POJ-3348
****************************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;


#define setp(a) cout<<setprecision(a)<<fixed
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
  point rotateCCW90(){return point(-y,x);}
  point rotateCCW180(){return point(-x,-y);}
  point rotateCCW270(){return point(y,-x);}
};
struct line
{
  point p,v;//v is vector,going through p;
  line(){}
  line(point _p,point _v):p(_p),v(_v){}
  void makeLine(point p1,point p2){p=p1,v=p2-p1;}
  bool onLine(point p1)
  {
    if(sgn(v^(p1-p))!=0)return false;//area of triangle has to be 0
    return true;
  }
  double pointDist(point p1)
  {
    //area of triangle/base of triangle
    return abs((v^(p1-p))/v.value());//signed based on cw ans ccw
  }
  line perpendicular(point p1){return line(p1,v.rotateCCW90());}
  point intersection(line l)
  {
    //no solution for parallel line.
    return p+v*((l.v^(p-l.p))/(v^l.v));
  }
};
struct segment
{
  point a,b;
  segment(){};
  segment(point _a,point _b):a(_a),b(_b){}
  //onLine and onSegment
  bool onLine(point p)
  {
    line l;l.makeLine(a,b);
    if(!l.onLine(p))return false;
    if(p.x>=min(a.x,b.x)&&p.x<=max(a.x,b.x)&&p.y>=min(a.y,b.y)&&p.y<=max(a.y,b.y))
      return true;//precision 
    return false;
  }
  //this is a very bad way to do this
  double segmentToPointDist(point p)
  {
    line l,r;l.makeLine(a,b);r=l.perpendicular(p);
    double ret=min(a.dist(p),b.dist(p));
    if(onLine(l.intersection(r)))ret=l.pointDist(p);
    return ret;
  }
};
struct circle
{
  double x,y,r;
  circle(){};circle(double _x,double _y,double _r):x(_x),y(_y),r(_r){}
};
struct polygoan
{
  vector<point>p;
  polygoan(){};
  polygoan(vector<point>_p):p(_p){}
  /*
  in a N*N grid a convexhull can have maximum N^(2/3) vertices of lattice point 
  after omitting straight line point. for random input it is N^(1/3);
  returns counter-clock-wise, a path, not closed circuit
  */
  vector<point>convexHull()
  {
    sort(p.begin(),p.end());int n=p.size(),top=0;//polygoan are changed
    vector<point>hull,stck(n+10);
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
    while(top>0)hull.push_back(stck[top--]);
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
    while(top>0)hull.push_back(stck[top--]);
    if(hull.size()>1)hull.pop_back();
    return hull;
  }
  double hullArea()
  {
    vector<point>h=convexHull();double ret=0;
    int n=h.size();
    for(int i=1;i<n;i++)ret+=(h[i]-h[0])^(h[(i+1)%n]-h[0]);
    return abs(ret/2.0);//signed, positive for cw
  }
};

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  vector<point>p(n);
  for(int i=0;i<n;i++)
    cin>>p[i].x>>p[i].y;
  polygoan pl(p);
  long x=floor(pl.hullArea()+eps);
  cout<<x/50<<endl;


  return 0;
}