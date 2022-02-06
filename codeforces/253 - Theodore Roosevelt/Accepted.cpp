/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2020 19:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/problemsets/acmsguru/problem/99999/253
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
 #define setp(a) cout<<setprecision(a)<<fixed
const long eps=1e-9,pi=acos(-1.0);
 int sgn(long d)
{
  if(d==0)return 0;
  if(d<0)return -1;return 1;
  //if(abs(d)<eps)return 0;return d<0.0?-1:1;
}
struct point
{
  long x,y;
  point(){};point(long _x,long _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(long d){return point(x*d,y*d);}
  point operator/(long d){return point(x/d,y/d);}
  bool operator==(point p){return x==p.x&&y==p.y;}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  long value(){return sqrt(x*x+y*y);}
  long dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
  point unitVector()
  {
    //invalid if vector is (0,0)
    long v=value();return point(x/v,y/v);
  }
  long operator*(point p)
  {
    return x*p.x+y*p.y;//0 if vectors are perpendicular;
  }
  long operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //signed area of the parallelogram by two vector
    //positive if p is ccw to the vector
  }
  point rotateCCW(long a)//radian
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
  long pointDist(point p1)
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
  segment(){}
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
  long segmentToPointDist(point p)
  {
    line l,r;l.makeLine(a,b);r=l.perpendicular(p);
    long ret=min(a.dist(p),b.dist(p));
    if(onLine(l.intersection(r)))ret=l.pointDist(p);
    return ret;
  }
};
struct circle
{
  long x,y,r;
  circle(){};circle(long _x,long _y,long _r):x(_x),y(_y),r(_r){}
};
struct triangle
{
  point a,b,c;
  triangle(){}
  triangle(point _a,point _b,point _c):a(_a),b(_b),c(_c){}
  bool inTriangle(point p)
  {
    int s1=abs((b-a)^(c-a));
    int s2=abs((a-p)^(b-p))+abs((b-p)^(c-p))+abs((c-p)^(a-p));
    //cout<<s1<<" "<<s2<<endl;
    return sgn(s1-s2)==0;
  }
};
struct polygon
{
  vector<point>p,h;
  polygon(){};
  polygon(vector<point>_p):p(_p){}
  /*
  in a N*N grid a convexHull can have maximum N^(2/3) vertices of lattice point 
  after omitting straight line point. for random input it is N^(1/3);
  returns counter-clock-wise, a path, not closed circuit
  */
  vector<point>convexHull()
  {
    sort(p.begin(),p.end());int n=p.size(),top=0;//polygon are changed
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
  long hullArea(){
    vector<point>h=convexHull();long ret=0;
    int n=h.size();
    for(int i=1;i<n;i++)ret+=(h[i]-h[0])^(h[(i+1)%n]-h[0]);
    return abs(ret/2.0);//signed, positive for cw
  }
  //return 1 for inside, 0 for on and -1 for outside
  //point is ccw oriented with no three collinear point
  int inConvex(point p)
  {
    int n=h.size();assert(n>=3);////////////
    int lo=1,hi=n-1;
    while(hi-lo>1)
    {
      int md=(lo+hi)/2;
      if(sgn((h[md]-h[0])^(p-h[0]))==1)lo=md;
      else hi=md;
    }
    //cout<<0<<" "<<lo<<" "<<hi<<endl;
    bool in=triangle(h[0],h[lo],h[hi]).inTriangle(p);
    //cout<<in<<endl;
    if(!in)return -1;
     if(sgn((h[lo]-h[lo-1])^(p-h[lo-1]))==0)return 0;
    if(sgn((h[hi]-h[lo])^(p-h[lo]))==0)return 0;
    if(sgn((h[hi]-h[(hi+1)%n])^(p-h[(hi+1)%n]))==0)return 0;
    return 1;
  }
};
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;polygon p;p.p.resize(n);
  for(int i=0;i<n;i++)cin>>p.p[i].x>>p.p[i].y;
  p.h=p.convexHull();
   while(m--)
  {
    point pt;cin>>pt.x>>pt.y;
    if(p.inConvex(pt)>=0)k--;
  }
  if(k>0)cout<<"NO\n";else cout<<"YES\n";
  return 0;
}