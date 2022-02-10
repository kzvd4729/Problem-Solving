/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-18 19:31:21                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 47                                         memory_used (MB): 0.7                             
*  problem: https://vjudge.net/problem/POJ-1113
****************************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e3;
const double pi=acos(-1.0);
struct point
{
  int x,y;
  point(int _x=0,int _y=0){x=_x,y=_y;}
  point operator+(const point &p){return {x+p.x,y+p.y};}
  point operator-(const point &p){return {x-p.x,y-p.y};}
  int operator^(const point &p){return x*p.y-y*p.x;}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  int distSqure(const point &p){return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);}
};
void convexHull(vector<point>p,vector<point>&h)
{
  sort(p.begin(),p.end());
  int m=0,n=p.size();h.resize(n+n+2);
  for(int i=0;i<n;i++)
  {
    while(m>1&&((h[m-1]-h[m-2])^(p[i]-h[m-2]))<=0)m--;
    h[m++]=p[i];
  }
  int k=m;
  for(int i=n-2;i>=0;i--)
  {
    while(m>k&&((h[m-1]-h[m-2])^(p[i]-h[m-2]))<=0)m--;
    h[m++]=p[i];
  }
  if(n>1)m--;
  while(h.size()>m)h.pop_back();
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,l;cin>>n>>l;vector<point>v(n);
  for(int i=0;i<n;i++)
    cin>>v[i].x>>v[i].y;
  vector<point>h;convexHull(v,h);
  n=h.size();double ans=0;
  for(int i=0;i<n;i++)
    ans+=sqrt(h[i].distSqure(h[(i+1)%n])*1.0);
  ans+=(2.0*pi*l);
  int prnt=round(ans);
  cout<<prnt<<endl;
  return 0;
}