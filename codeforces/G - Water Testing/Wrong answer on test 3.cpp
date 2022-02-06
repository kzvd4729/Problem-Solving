/****************************************************************************************
*  @author: kzvd4729#                                        created: Feb/05/2020 17:11                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101873/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
 struct point
{
  long x,y;
  point(){};point(long _x,long _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(long d){return point(x*d,y*d);}
  point operator/(long d){return point(x/d,y/d);}
  long operator^(point p){return x*p.y-y*p.x;}
};
long polygoanArea(vector<point>&p)
{
  int n=p.size();long area=0,an=0;
  for(int i=1;i<n-1;i++)
  {
    an+=__gcd(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y));
    area+=(p[i]-p[0])^(p[i+1]-p[0]);
  }
  return abs(area)/2-an+p.size()-3;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<point>v(n);
  for(int i=0;i<n;i++)
    cin>>v[i].x>>v[i].y;
  long ans=polygoanArea(v);
  cout<<ans<<endl;
  return 0;
}