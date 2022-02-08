/****************************************************************************************
*  @author: kzvd4729                                         created: 26-07-2019 11:55:54                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.18 sec                                        memory_used: 31.8M                                
*  problem: https://www.codechef.com/problems/KTHCON
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
struct polong
{
  long x,y;
  polong(){}
  polong(long _x,long _y):x(_x), y(_y){}
  bool operator<(const polong &p)const{return x<p.x||(x==p.x&&y<p.y);}
  polong operator-(const polong &p)const{return {x-p.x,y-p.y};}
  long operator^(const polong &p)const{return 1LL*x*p.y-1LL*y*p.x;}
  long distSqure(const polong &p)const{return 1LL*(x-p.x)*(x-p.x)+1LL*(y-p.y)*(y
      -p.y);}
};
polong stck[N+2];long top=0;
void balance(void)
{
  while(top>=3)
  {
    //>=0 to omit straight line polong;
    //for repetative or straight line polong >0;
    if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>=0)
      stck[top-1]=stck[top],top--;
    else break;
  }
}
//returns counter-clock-wise;
//a path, not closed circuit
vector<polong>monotoneChain(vector<polong>&v)
{
  sort(v.begin(),v.end());
  vector<polong>hull;long n=v.size();
  for(long i=n-1;i>=0;i--)
    stck[++top]=v[i],balance();
  while(top>0)
    hull.push_back(stck[top--]);
  for(long i=0;i<n;i++)
    stck[++top]=v[i],balance();
  top--;
  while(top>0)
    hull.push_back(stck[top--]);
  if(hull.size()>1)hull.pop_back();
  return hull;
}
long brut(vector<polong>u,vector<polong>&v)
{
  u.push_back(u[0]);long mn=LLONG_MAX;
  for(auto x:v)
  {
    for(long i=1;i<u.size();i++)
      mn=min(mn,abs((u[i]-x)^(u[i-1]-x)));
  }
  return mn;
}
long rotatingCalipers(vector<polong>&p,vector<polong>&q)
{
  long a=p.size(),b=q.size();long mn=LLONG_MAX;
  p.push_back(p[0]);q.push_back(q[0]);//to consider all triangle
  for(long i=0,j=1;i<a;i++)
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
long polygoanArea(vector<polong>&p)
{
  long n=p.size();long area=0;
  for(long i=1;i<n-1;i++)
    area+=(p[i]-p[0])^(p[i+1]-p[0]);
  return abs(area);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;vector<polong>v(n);
    for(long i=0;i<n;i++)
      cin>>v[i].x>>v[i].y;
    vector<polong>up=monotoneChain(v);
    if(up.size()==n)
    {
      cout<<-1<<"\n";continue;
    }
    long area=polygoanArea(up);
    map<polong,long>mp;
    for(auto x:up)mp[x]=1;
    vector<polong>lw;
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