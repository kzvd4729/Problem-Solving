/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/21/2019 14:16                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 46 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1254/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
//..............................................................................
#define setp(a) cout<<setprecision(a)<<fixed
struct point
{
  long x,y;
  point(){};point(long _x,long _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(long d){return point(x*d,y*d);}
  point operator/(long d){return point(x/d,y/d);}
  long value(){return sqrt(x*x+y*y);}
  long operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //sigbed area of the parallelogram by two vector
    //positive if p is ccw to the point
  }
};
struct line
{
  point p,v;//v is vector,going through p;
  line(){}
  line(point _p,point _v):p(_p),v(_v){}
  void makeLine(point p1,point p2){p=p1,v=p2-p1;}
  long pointDist(point p1)
  {
    //area of triangle/base of triangle
    return abs((v^(p1-p)));
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;long cr=2;
  for(int i=3;i<=n;i++)
  {
    cout<<2<<" "<<1<<" "<<cr<<" "<<i<<endl;
    long f;cin>>f;
    if(f==-1)cr=i;
  }
  line l;l.makeLine(point(0,0),point(5,0));
  vector<pair<long,long> >v,lft,rgt;
  for(int i=2;i<=n;i++)
  {
    if(i==cr)continue;
    cout<<1<<" "<<1<<" "<<cr<<" "<<i<<endl;
    long d;cin>>d;v.push_back({d,i});
  }
  sort(v.begin(),v.end());
   int m=v.back().second;
   for(auto x:v)
  {
    if(x.second==m)continue;
    cout<<2<<" "<<1<<" "<<m<<" "<<x.second<<endl;
    int f;cin>>f;
    if(f==-1)lft.push_back(x);
    else rgt.push_back(x);
  }
  sort(lft.begin(),lft.end());
  sort(rgt.begin(),rgt.end());
   cout<<0<<" "<<1<<" "<<cr;
  for(auto x:lft)cout<<" "<<x.second;
  cout<<" "<<m;
  reverse(rgt.begin(),rgt.end());
  for(auto x:rgt)cout<<" "<<x.second;
  cout<<endl;
  return 0;
}