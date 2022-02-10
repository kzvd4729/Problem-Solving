/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-18 19:10:26                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2187
****************************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5e4;
struct point
{
  int x,y;
  point(int _x=0,int _y=0){x=_x,y=_y;}
  point operator+(const point &p){return {x+p.x,y+p.y};}
  point operator-(const point &p){return {x-p.x,y-p.y};}
  int operator^(const point &p){return x*p.y-y*p.x;}
  bool operator<(const point &p){return x<p.x?true:y<p.y;}
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
int rotateCalipers(vector<point>&p)
{
  int n=p.size();
  int ans=-1e9,j=1;
  for(int i=0;i<n;i++)
  {
    while(abs((p[i+1]-p[j+1])^(p[i]-p[j+1]))>abs((p[i+1]-p[j])^(p[i]-p[j])))
      j=(j+1)%n;
    ans=max(ans,p[j].distSqure(p[i]));
    ans=max(ans,p[j].distSqure(p[(i+1)%n]));
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<point>v(n);
  for(int i=0;i<n;i++)
    cin>>v[i].x>>v[i].y;
  vector<point>h;convexHull(v,h);
  cout<<rotateCalipers(h);
  return 0;
}