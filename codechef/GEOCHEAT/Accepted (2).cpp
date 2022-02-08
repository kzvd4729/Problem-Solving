/****************************************************************************************
*  @author: kzvd4729                                         created: 25-07-2019 23:31:11                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.52 sec                                        memory_used: 52.1M                                
*  problem: https://www.codechef.com/problems/GEOCHEAT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  int x,y,id;
  point(){};
  point(int _x,int _y){x=_x,y=_y;}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  point operator-(const point &p)const{return {x-p.x,y-p.y};}
  long operator^(const point &p)const{return 1LL*x*p.y-1LL*y*p.x;}
  long distSqure(const point &p)const{return 1LL*(x-p.x)*(x-p.x)+1LL*(y-p.y)*(y
      -p.y);}
};
point stck[N+2];int top=0;
void balance(void)
{
  while(top>=3)
  {
    //>=0 to omit straight line point;
    if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>=0)
      stck[top-1]=stck[top],top--;
    else break;
  }
}
//returns counter-clock-wise;
//first=last;
//is it ok for repetative point?
//may be handle 1 case differently
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
  return hull;
}
int a,b;long pr[N+2];
long rotatingCalipers(vector<point>&p)
{
  int n=p.size();long ans=0;a=-1,b=-1;
  p.push_back(p[0]);
  for(int i=0,j=1;i<n;i++)
  {
    while(abs((p[i+1]-p[j+1])^(p[i]-p[j+1]))>abs((p[i+1]-p[j])^(p[i]-p[j])))
      j=(j+1)%n;
    long aa=p[j].distSqure(p[i]);
    long bb=p[j].distSqure(p[(i+1)%n]);
    if(aa>ans)ans=aa,a=p[i].id,b=p[j].id;
    if(bb>ans)ans=bb,a=p[(i+1)%n].id,b=p[j].id;
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<point>v(n);
  for(int i=0;i<n;i++)
    cin>>v[i].x>>v[i].y,v[i].id=i;
  vector<point>u=v;
  int nn=n;
  int f=0;n--;
  while(n>=0)
  {
    if(!f)
    {
      v=monotoneChain(v);v.pop_back();
      pr[n]=rotatingCalipers(v);
      f=1;
    }
    else pr[n]=pr[n+1];
    if(n==a||n==b)
    {
      v.clear();
      for(int i=0;i<n;i++)
        v.push_back(u[i]);
      f=0;
    }
    n--;
  }
  for(int i=0;i<nn;i++)
    cout<<pr[i]<<"\n";
  return 0;
}