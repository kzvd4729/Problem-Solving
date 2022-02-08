/****************************************************************************************
*  @author: kzvd4729                                         created: 26-07-2019 11:50:32                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.16 sec                                        memory_used: 25.6M                                
*  problem: https://www.codechef.com/problems/KTHCON
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
  long distSqure(const point &p)const{return 1LL*(x-p.x)*(x-p.x)+1LL*(y-p.y)*(y
      -p.y);}
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
long brut(vector<point>u,vector<point>&v)
{
  u.push_back(u[0]);long mn=LLONG_MAX;
  for(auto x:v)
  {
    for(int i=1;i<u.size();i++)
      mn=min(mn,abs((u[i]-x)^(u[i-1]-x)));
  }
  return mn;
}
int rotatingCalipers(vector<point>&p,vector<point>&q)
{
  int a=p.size(),b=q.size();long mn=LLONG_MAX;
  p.push_back(p[0]);q.push_back(q[0]);//to consider all triangle
  for(int i=0,j=1;i<a;i++)
  {
    //triangle compare.
    while(abs((p[i+1]-q[j+1])^(p[i]-q[j+1]))<abs((p[i+1]-q[j])^(p[i]-q[j])))
      j=(j+1)%b;
    mn=min(mn,abs((p[i+1]-q[j])^(p[i]-q[j])));
  }
  return mn;
}
//positive for anti-clockwise
//expected a non closed circuit
long polygoanArea(vector<point>&p)
{
  int n=p.size();long area=0;
  for(int i=1;i<n-1;i++)
    area+=(p[i]-p[0])^(p[i+1]-p[0]);
  return abs(area);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<point>v(n);
    for(int i=0;i<n;i++)
      cin>>v[i].x>>v[i].y;
    vector<point>up=monotoneChain(v);
    if(up.size()==n)
    {
      cout<<-1<<"\n";continue;
    }
    long area=polygoanArea(up);
    map<point,int>mp;
    for(auto x:up)mp[x]=1;
    vector<point>lw;
    for(auto x:v)
    {
      if(!mp.count(x))
        lw.push_back(x);
    }
    lw=monotoneChain(lw);
    if(up.size()<500||lw.size()<500)
      cout<<area-brut(up,lw)<<"\n";
    else cout<<area-rotatingCalipers(up,lw)<<"\n";
  }
  return 0;
}