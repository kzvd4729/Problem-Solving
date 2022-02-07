/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-23 21:46:05                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11343
****************************************************************************************/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const double eps=1e-9;
const double pi=acos(-1.0);
int sgn(const int &d)
{
  return d==0?0:d<0?-1:1;
}
struct point
{
  int x,y;
  point(int _x=0,int _y=0){x=_x,y=_y;}
  void input(){cin>>x>>y;}
  void output(){cout<<x<<" -- "<<y<<endl;}
  point operator+(const point &p)const{return {x+p.x,y+p.y};}
  point operator-(const point &p)const{return {x-p.x,y-p.y};}
  int operator*(const point &p){return x*p.x+y*p.y;}
  int operator^(const point &p)const{return x*p.y-y*p.x;}
  int valSquerd()const{return x*x+y*y;}
  int distSqure(const point &p)const{return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);}
};
struct segment
{
  point s,e;
  segment(){}
  segment(point _s,point _e){s=_s,e=_e;}
  void input(){s.input(),e.input();}
  void output(){s.output();cout<<" ---> ";e.output();}
  int segmentIntersect(segment sg)
  {
    int s1,s2,s3,s4;
    int d1=sgn(s1=(e-s)^(sg.s-s));
    int d2=sgn(s2=(e-s)^(sg.e-s));
    int d3=sgn(s3=(sg.e-sg.s)^(s-sg.s));
    int d4=sgn(s4=(sg.e-sg.s)^(e-sg.s));
    if((d1^d2)==-2&&(d3^d4)==-2)return 1;
    else if(d1==0&&sgn((s-sg.s)*(e-sg.s))<=0)return 2;
    else if(d2==0&&sgn((s-sg.e)*(e-sg.e))<=0)return 2;
    else if(d3==0&&sgn((sg.s-s)*(sg.e-s))<=0)return 2;
    else if(d4==0&&sgn((sg.s-e)*(sg.e-e))<=0)return 2;
    return 0;
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<segment>sg(n);
    for(int i=0;i<n;i++)
      sg[i].input();
    int iso=0;
    for(int i=0;i<n;i++)
    {
      int f=0;
      for(int j=0;j<n;j++)
      {
        if(i==j)continue;
        if(sg[i].segmentIntersect(sg[j]))f=1;
      }
      iso+=(!f);
    }
    cout<<iso<<"\n";
  }
  return 0;
}