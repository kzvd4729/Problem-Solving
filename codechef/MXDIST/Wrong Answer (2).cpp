/****************************************************************************************
*  @author: kzvd4729                                         created: 25-07-2019 16:42:44                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/problems/MXDIST
****************************************************************************************/
#include<bits/stdc++.h>
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
  long operator^(const point &p)const{return 1LL*x*p.y-1LL*y*p.x;}
  long distSqure(const point &p){return 1LL*(x-p.x)*(x-p.x)+1LL*(y-p.y)*(y-p.y
      );}
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
}seg[4*N+2];
//polygoan is convex and ordered
//not closed circuit
//return the farthest distance squared;
long rotatingCalipers(vector<point>p)
{
  int n=p.size()-1;long ans=0;
  for(int i=0,j=1;i<n;i++)
  {
    while(abs((p[i+1]-p[j+1])^(p[i]-p[j+1]))>abs((p[i+1]-p[j])^(p[i]-p[j])))
      j=(j+1)%n;
    ans=max(ans,p[j].distSqure(p[i]));
    ans=max(ans,p[j].distSqure(p[i+1]));
  }
  return ans;
}
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node].dw.push_back(pp[lo]);
    seg[node].up.push_back(pp[lo]);
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=seg[node*2];seg[node].mergeConvex(seg[node*2+1]);
}
convexHull ret;
void get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt){ret.mergeConvex(seg[node]);return ;}
  int md=(lo+hi)/2;
  get(node*2,lo,md,lt,rt);get(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>pp[i].x>>pp[i].y;
  build(1,1,n);
  int q;cin>>q;
  while(q--)
  {
    int lt,rt;cin>>lt>>rt;
    ret.up.clear();ret.dw.clear();
    get(1,1,n,lt,rt);
    cout<<rotatingCalipers(ret.getHull())<<"\n";
  }
  return 0;
}