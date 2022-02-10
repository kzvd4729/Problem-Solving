/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-26 11:55:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 391                                        memory_used (MB): 1.1                             
*  problem: https://vjudge.net/problem/POJ-2187
****************************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  int x,y;
  point(){}
  point(int _x,int _y):x(_x), y(_y){}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  point operator-(const point &p)const{return {x-p.x,y-p.y};}
  int operator^(const point &p)const{return x*p.y-y*p.x;}
  int distSqure(const point &p)const{return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);}
};
point stck[N+2];int top=0;
void balance(void)
{
  while(top>=3)
  {
    //>=0 to omit straight line point;
    //for repetative or straight line point >0;
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
//polygoan is convex and ccw-ordered
//not closed circuit
//return the farthest distance squared;
int rotatingCalipers(vector<point>&p)
{
  int n=p.size(),ans=0;if(n==1)return 0;
  if(n==2)return p[0].distSqure(p[1]);
  p.push_back(p[0]);//to consider all triangle
  for(int i=0,j=1;i<n;i++)
  {
    //triangle compare.
    while(abs((p[i+1]-p[j+1])^(p[i]-p[j+1]))>abs((p[i+1]-p[j])^(p[i]-p[j])))
      j=(j+1)%n;
    ans=max(ans,p[i].distSqure(p[j]));
    ans=max(ans,p[i+1].distSqure(p[j]));
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<point>v(n);
  for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
  v=monotoneChain(v);
  cout<<rotatingCalipers(v)<<endl;
  return 0;
}