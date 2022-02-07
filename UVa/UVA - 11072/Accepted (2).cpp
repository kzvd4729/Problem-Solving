/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-25 13:13:21                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 130                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11072
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  int x,y,id;
  point(){}
  point(int _x,int _y):x(_x), y(_y){}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  point operator-(const point &p)const{return {x-p.x,y-p.y};}
  int operator*(const point &p){return x*p.x+y*p.y;}
  int operator^(const point &p)const{return x*p.y-y*p.x;}

};
int sgn(int val){return val>0?1:(val==0?0:-1);}
int n;point p0;
vector<point>seq;
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
  //cout<<"herer"<<endl;
  if((seq[0]^p)==0)
    return (seq[0]*seq[0])>=(p*p);
  int l=0,r=n-1;
  while(r-l>1)
  {
    int mid=(l+r)/2;int pos=mid;
    if((seq[pos]^p)>=0)l=mid;
    else r=mid;
  }
  int pos=l;
  return pointInTriangle(seq[pos],seq[pos+1],point(0,0),p);
}
point stck[N+2];int top=0;
void balance(void)
{
  while(top>=3)
  {
    //>=0 to omit straight line point;
    //for repetative point have to be >=0;
    if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>=0)
      stck[top-1]=stck[top],top--;
    else break;
  }
}
//returns counter-clock-wise;
//first=last;
//is it ok for repetative point?
//may be handle 1 case differently
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
  return hull;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  while(cin>>n)
  {
    vector<point>v(n);seq.clear();
    for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
    v=monotoneChain(v);v.pop_back();
    prepare(v);
    int m;cin>>m;
    while(m--)
    {
      point p;cin>>p.x>>p.y;
      if(pointInConvexPolygoan(p))cout<<"inside\n";
      else cout<<"outside\n";
    }
  }
  return 0;
}