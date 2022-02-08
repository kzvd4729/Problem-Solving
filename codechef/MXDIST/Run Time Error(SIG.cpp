/****************************************************************************************
*  @author: kzvd4729                                         created: 25-07-2019 17:49:33                      
*  solution_verdict: Run Time Error(SIGSEGV)                 language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/problems/MXDIST
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,bk=3001;
struct point
{
  int x,y;
  point(){}
  point(int _x,int _y):x(_x), y(_y){}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  point operator-(const point &p)const{return {x-p.x,y-p.y};}
  long operator^(const point &p)const{return 1LL*x*p.y-1LL*y*p.x;}
  long dist(const point &p){return 1LL*(x-p.x)*(x-p.x)+1LL*(y-p.y)*(y-p.y);}
}pp[N+2];
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
struct convexHull
{
  vector<point>up,dw;
  //counter-clockwise;
  void lowerConvex(void)
  {
    //points need to be sorted;
    int n=dw.size();
    for(int i=n-1;i>=0;i--)
      stck[++top]=dw[i],balance();
    dw.clear();
    while(top>0)
      dw.push_back(stck[top--]);
  }
  //clockwise
  void upperConvex(void)
  {
    //points need to be sorted;
    int n=up.size();
    for(int i=0;i<n;i++)
      stck[++top]=up[i],balance();
    up.clear();
    while(top>0)
      up.push_back(stck[top--]);
    reverse(up.begin(),up.end());
  }
  void build(vector<point>&v)
  {
    sort(v.begin(),v.end());
    up=v;dw=v;
    lowerConvex();upperConvex();
  }
  void mergeConvex(const convexHull &c)
  {
    vector<point>tmp;
    tmp.resize(dw.size()+c.dw.size());
    merge(dw.begin(),dw.end(),c.dw.begin(),c.dw.end(),tmp.begin());
    dw=tmp;lowerConvex();
    tmp.resize(up.size()+c.up.size());
    merge(up.begin(),up.end(),c.up.begin(),c.up.end(),tmp.begin());
    up=tmp;upperConvex();
  }
  vector<point>getHull(void)
  {
    vector<point>ret=dw;
    for(int i=up.size()-2;i>0;i--)
      ret.push_back(up[i]);
    return ret;
  }
}seg[N+2][22];
//polygoan is convex and ordered
//not closed circuit
//return the farthest distance squared;
long rotatingCalipers(vector<point>p)
{
  int n=p.size();long ans=0;
  p.push_back(p[0]);
  for(int i=0,j=1;i<n;i++)
  {
    while(abs((p[i+1]-p[j+1])^(p[i]-p[j+1]))>abs((p[i+1]-p[j])^(p[i]-p[j])))
      j=(j+1)%n;
    ans=max(ans,p[j].dist(p[i]));
    ans=max(ans,p[j].dist(p[(i+1)%n]));
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n;i++)
    cin>>pp[i].x>>pp[i].y;
  int id=0,st=0,ed=-1;
  while(ed<n)
  {
    st=ed+1,ed=min(st+bk-1,n-1);vector<point>v;
    for(int i=st;i<=ed;i++)
      v.push_back(pp[i]);
    seg[++id][0].build(v);
  }
  for(int j=1;j<16;j++)
  {
    for(int i=1;i<=id;i++)
    {
      seg[i][j]=seg[i][j-1];
      if(i+(1<<(j-1))<=id)
        seg[i][j].mergeConvex(seg[i+(1<<(j-1))][j-1]);
    }
  }
  int q;cin>>q;
  while(q--)
  {
    int lt,rt;cin>>lt>>rt;lt--,rt--;
    vector<point>p;
    while(lt<=rt)
    {
      if(lt%bk==0)break;
      p.push_back(pp[lt++]);
    }
    while(lt<=rt)
    {
      if(rt%bk==bk-1)break;
      p.push_back(pp[rt--]);
    }
    convexHull ch;ch.build(p);
    if(lt<=rt)
    {
      lt/=bk,rt/=bk;lt++,rt++;
      for(int j=15;j>=0;j--)
      {
        int tmp=lt+(1<<j)-1;
        if(tmp<=rt)
        {
          ch.mergeConvex(seg[lt][j]);
          lt+=(1<<j);
        }
      }
    }
    cout<<rotatingCalipers(ch.getHull())<<"\n";
  }
  return 0;
}