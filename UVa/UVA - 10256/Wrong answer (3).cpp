/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-29 12:49:48                      
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
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
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
    while(first<last&&(l[i].v^(p[last-1]-l[i].p))<-eps)last--;//<-eps
    while(first<last&&(l[i].v^(p[first]-l[i].p))<-eps)first++;//<-eps
    q[++last]=l[i];
    if(sgn(q[last].v^q[last-1].v)==0)
    {
      last--;
      if((q[last].v^(l[i].p-q[last].p))>=-eps)q[last]=l[i];//>=-eps
    }
    if(first<last)p[last-1]=q[last-1].intersection(q[last]);
  }
  while(first<last&&(q[first].v^(p[last-1]-q[first].p))<-eps)//<-eps
    last--;
  if(last-first<=1)return poly;
  p[last]=q[last].intersection(q[first]);
  for(int i=first;i<=last;i++)poly.push_back(p[i]);
  return poly;//ccw path
}


int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;
  while(cin>>n>>m)
  {
    if(n==0&&m==0)break;
    vector<point>v(n);
    for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
    vector<point>a=monotoneChain(v);

    v.resize(m);
    for(int i=0;i<m;i++)cin>>v[i].x>>v[i].y;
    vector<point>b=monotoneChain(v);

    vector<line>l;
    for(int i=0;i<n;i++)
      l.push_back(line(a[i],a[(i+1)%n]));
    for(int i=0;i<n;i++)
      l.push_back(line(b[i],b[(i+1)%m]));

    vector<point>poly=halfPlaneIntersection(l);
    if(poly.size())cout<<"No\n";
    else cout<<"Yes\n";
  }
  return 0;
}