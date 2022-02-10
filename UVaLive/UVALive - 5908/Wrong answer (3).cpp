/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 19:03:05                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-5908
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,C=1e4;

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
  void input()
  {
    cin>>s.x>>s.y>>e.x>>e.y;
    s.x+=C,s.y+=C,e.x+=C,e.y+=C;
  }
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
  ios_base::sync_with_stdio(0);cin.tie(0);
//  segment sg(point(11,5),point(11,2));
//  segment gs(point(11,4),point(11,3));
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
//    for(int i=1;i<=walls;i++)
//      cout<<wall[i].s.x<<" *** "<<wall[i].e.x<<endl;
    vector<pair<int,int> >ans;
    while(product--)
    {
      point p;cin>>p.x>>p.y;p.x+=C,p.y+=C;
      for(int cl=max(0,p.y-2*radius);cl<=min(C+C,p.y+2*radius);cl++)
      {
        int id=lower_bound(col[cl].begin(),col[cl].end(),p.x)-col[cl].begin();id=0;
        int i=id;
        while(i<col[cl].size())
        {
          int d=dis(p,point(col[cl][i],cl));
          if(d>radius*radius)break;
          segment sg(p,point(col[cl][i],cl));int f=0;
          for(int w=1;w<=walls;w++)
            if(wall[w].segmentIntersect(sg))f++;
          if(f>radius)f=radius;
          if(d<=(radius-f)*(radius-f))
            ans.push_back({col[cl][i],cl});
          i++;
        }
        i=id-1;
        while(i>=0)
        {
          int d=dis(p,point(col[cl][i],cl));
          if(d>radius*radius)break;
          segment sg(p,point(col[cl][i],cl));int f=0;
          for(int w=1;w<=walls;w++)
            if(wall[w].segmentIntersect(sg))f++;
          if(f>radius)f=radius;
          if(d<=(radius-f)*(radius-f))
            ans.push_back({col[cl][i],cl});
          i--;
        }
      }
      sort(ans.begin(),ans.end());
      cout<<ans.size();
      for(auto x:ans)
        cout<<" ("<<x.first-C<<","<<x.second-C<<")";
      cout<<"\n";
      ans.clear();
    }
  }
  return 0;
}