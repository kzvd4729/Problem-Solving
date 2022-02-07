/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-29 14:17:56                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10256
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;

#define setp(a) cout<<setprecision(a)<<fixed
const double eps=1e-9;
const double pi=acos(-1.0);

int sgn(const double d)
{
  if(fabs(d)<=eps)return 0;
  return d<0.0?-1:1;
}
struct point
{
  double x,y;
  point(){};
  point(double _x,double _y):x(_x),y(_y){}
  point operator+(point p){return {x+p.x,y+p.y};}
  point operator-(point p){return {x-p.x,y-p.y};}
  point operator*(double d){return {x*d,y*d};}
  point operator/(double d){return {x/d,y/d};}
  double operator*(point p)
  {
    return x*p.x+y*p.y;
    //0 if vectors are perpendicular;
  }
  double operator^(point p)
  {
    return x*p.y-y*p.x;
    //area of the parallelogram by two vector
    //0 if two vectors are same
    //positive if p ccw to the point
  }
  bool operator<(const point &p)const{return x<p.x||(sgn(x-p.x)==0&&y<p.y);}
  double dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
};
point stck[N+2];int top=0;
void balance(void)
{
  while(top>=3)
  {
    //>=0 to omit straight line point;
    if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>=0)
      stck[top-1]=stck[top],top--;
    else break;
  }
}
//returns counter-clock-wise;
//a path, not closed circuit
vector<point>monotoneChain(vector<point>&v)
{
  sort(v.begin(),v.end());
  vector<point>hull;int n=v.size();
  for(int i=n-1;i>=0;i--)
    stck[++top]=v[i],balance();
  while(top>0)
    hull.push_back(stck[top--]);
  for(int i=0;i<n;i++)
    stck[++top]=v[i],balance();
  top--;
  while(top>0)
    hull.push_back(stck[top--]);
  if(hull.size()>1)hull.pop_back();
  return hull;
}
int n;point p0;vector<point>seq;
//inside or on the triangle
bool pointInTriangle(point a,point b,point c,point p)
{
  int s1=abs((b-a)^(c-a));
  int s2=abs((a-p)^(b-p))+abs((b-p)^(c-p))+abs((c-p)^(a-p));
  return s1==s2;
}
void prepare(vector<point>&poly)
{
  n=poly.size();int pos=0;
  for(int i=1;i<n;i++)
    if(poly[i]<poly[pos])pos=i;
  rotate(poly.begin(),poly.begin()+pos,poly.end());
  n--;seq.resize(n);p0=poly[0];
  for(int i=0;i<n;i++)
    seq[i]=poly[i+1]-poly[0];
}
//point is inside or on
bool pointInConvexPolygoan(point p)
{
  p=p-p0;
  if((seq[0]^p)!=0&&sgn(seq[0]^p)!=sgn(seq[0]^seq[n-1]))
    return false;
  if((seq[n-1]^p)!=0&&sgn(seq[n-1]^p)!=sgn(seq[n-1]^seq[0]))
    return false;
  if((seq[0]^p)==0)
    return (seq[0]*seq[0])>=(p*p);
  int l=0,r=n-1,md;
  while(r-l>1)
  {
    md=(l+r)/2;
    if((seq[md]^p)>=0)l=md;
    else r=md;
  }
  return pointInTriangle(seq[l],seq[l+1],point(0,0),p);
}
int orientation(point a,point b,point c)
{
  return sgn((b-a)^(c-a));
  //0 for straight line 1 for ccw -1 for cw
}
bool inRec(point s,point e,point p)
{
  double mxx=max(s.x,e.x),mnx=min(s.x,e.x);
  double mxy=max(s.y,e.y),mny=min(s.y,e.y);
  return p.x<=mxx+eps&&p.x>=mnx-eps&&p.y<=mxy+eps&&p.y>=mny-eps;
  //point p is inside(or on) the rectangle formed by the segment.
}
struct line
{
  point p,v;//v is vector,going through p;
  line(){}
  line(point p1,point p2){p=p1,v=p2-p1;}
  line perpendicular(point p)
  {
    line l;l.v=point(-v.y,v.x);
    l.p=p;return l;
    //rotating the vector 90 degree
    //the line going through point p
  }
  bool isParallel(line l)
  {
    return sgn(v^l.v)==0;
    //have to be same vector,so area 0;
  }
  int whichSide(point p1)
  {
    return sgn(v^(p1-p));
    //0 if point belongs to the line
    //can return positive or negative
    //compare a known points sign to 
    //determine left or right
  }
  double pointDist(point p1){return (v^p1)-(v^p);}
  point intersection(line l)
  {
    //check for parallel;
    double t=(l.v^(p-l.p))/(v^l.v);
    return p+v*t;
  }
};


int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;
  while(cin>>n>>m)
  {
    if(!n&&!m)break;

    vector<point>u(n);
    for(int i=0;i<n;i++)
      cin>>u[i].x>>u[i].y;
    vector<point>a=monotoneChain(u);

    vector<point>v(m);
    for(int i=0;i<m;i++)
      cin>>v[i].x>>v[i].y;
    vector<point>b=monotoneChain(v);

    int f=0;prepare(b);
    for(auto x:u)
      f|=pointInConvexPolygoan(x);
    prepare(a);
    for(auto x:v)
      f|=pointInConvexPolygoan(x);

    for(int i=0;i<a.size();i++)
    {
      line u(a[i],a[(i+1)%((int)a.size())]);
      for(int j=0;j<b.size();j++)
      {
        line v(b[j],b[(j+1)%((int)b.size())]);
        if(u.isParallel(v))continue;
        point p=u.intersection(v);
        if(inRec(a[i],a[(i+1)%((int)a.size())],p)&&inRec(b[i],b[(i+1)%((int)b.size())],p))
          f=1;
      }
    }
    if(f)cout<<"No\n";
    else cout<<"Yes\n";  
  }

  return 0;
}