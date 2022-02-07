/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 18:04:05                      
*  solution_verdict: Compilation error                       language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11020
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,C=1e4;

int sgn(int x){return x>0?1:x<0?-1:0;}
struct point
{
  int x,y;
  point(int _x=0,int _y=0){x=_x,y=_y;}
  point operator-(const point &p){return {x-p.x,y-p.y};}
  point operator+(const point &p){return {x+p.x,y+p.y};}
  int operator*(const point &p){return x*p.x+y*p.y;}
  int operator^(const point &p){return x*p.y-y*p.x;}
}sensor[N+2];
struct segment
{
  point s,e;
  segment(){}
  segment(point _s,point _e){s=_s,e=_e;}
  void input(){cin>>s.x>>s.y>>e.x>>e.y;}
  int segmentIntersect(segment sg)
  {
    int s1,s2,s3,s4;
    int d1=sgn(s1=(e-s)^(sg.s-s));
    int d2=sgn(s2=(e-s)^(sg.e-s));
    int d3=sgn(s3=(sg.e-sg.s)^(s-sg.s));
    int d4=sgn(s4=(sg.e-sg.s)^(e-sg.s));
    if((d1^d2)==-2&&(d3^d4)==-2)return true;
    else if(d1==0&&sgn((s-sg.s)*(e-sg.s))<=0)return true;
    else if(d2==0&&sgn((s-sg.e)*(e-sg.e))<=0)return true;
    else if(d3==0&&sgn((sg.s-s)*(sg.e-s))<=0)return true;
    else if(d4==0&&sgn((sg.s-e)*(sg.e-e))<=0)return true;
    return false;
  }
}wall[N+2];
vector<int>col[C+C+2];
int dis(point a,point b)
{
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
//  segment sg(point(0,0),point(2,0));
//  segment gs(point(0,5),point(0,-5));
//
//  cout<<sg.segmentIntersect(gs)<<endl;

  int t;cin>>t;
  while(t--)
  {
    int sensors,radius,walls,product;cin>>sensors>>radius>>walls>>product;

    for(int i=0;i<=C+C;i++)col[i].clear();
    for(int i=1;i<=sensors;i++)
    {
      int x,y;cin>>x>>y;x+=C,y+=C;
      col[y].push_back(x);
    }
    for(int i=0;i<=C+C;i++)
      sort(col[i].begin(),col[i].end());
    for(int i=1;i<=walls;i++)
      wall[i].input();

    while(product--)
    {
      point p;cin>>p.x>>p.y;
      for(int cl=min(0,p.y-radius);cl<=max(C+C,p.y+radius);cl++)
      {
        int id=lower_bound(col[cl].begin(),col[cl].end(),p.x)-col[cl].begin();
        int i=id;
        while(i<col[cl].size())
        {
          if(dis(p,point(col[cl][i],cl))>radius*radius)break;
          segment sg(p,point(col[cl][i],cl));int f=0;
          for(int w=1;w<=walls;w++)
          {
            if(wall[i].segmentIntersect(sg)){f=1;break;}
          }
          if(!f)ans.push_back({col[cl][i],cl});
          i++;
        }
        i=id-1;
        while(i>=0)
        {
          if(dis(p,point(col[cl][i],cl))>radius*radius)break;
          segment sg(p,point(col[cl][i],cl));int f=0;
          for(int w=1;w<=walls;w++)
          {
            if(wall[i].segmentIntersect(sg)){f=1;break;}
          }
          if(!f)ans.push_back({col[cl][i],cl});
          i--;
        }

      }
    }
  }
  return 0;
}