/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2020 19:26                        
*  solution_verdict: Wrong answer on test 20                 language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/993/problem/A
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  int x,y;
  point(){};point(int _x,int _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(int d){return point(x*d,y*d);}
  point operator/(int d){return point(x/d,y/d);}
  bool operator==(point p){return x==p.x&&y==p.y;}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  int value(){return sqrt(x*x+y*y);}
  int dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
  int operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //signed area of the parallelogram by two vector
    //positive if p is ccw to the vector
  }
};
int area(point a,point b,point c)
{
  return abs((b-a)^(c-a));
}
bool inTri(point a,point b,point c,point d)
{
  int area1=area(a,b,c);
  int area2=area(a,b,d)+area(a,c,d)+area(b,c,d);
  return area1==area2;
}
bool inRec(point a,point b,point c,point d,point e)
{
  return inTri(a,b,c,e)|inTri(b,c,d,e);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  point a,b,c,d,e,f,g,h;
  cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
  cin>>e.x>>e.y>>f.x>>f.y>>g.x>>g.y>>h.x>>h.y;
   for(int i=-1000;i<=1000;i++)
  {
    for(int j=-1000;j<=1000;j++)
      if(inRec(a,b,c,d,point(i,j))&inRec(e,f,g,h,point(i,j)))
        cout<<"YES\n",exit(0);
  }
  cout<<"NO\n";
  return 0;
}