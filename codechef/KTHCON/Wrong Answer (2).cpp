/****************************************************************************************
*  @author: kzvd4729                                         created: 25-07-2019 21:21:34                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 22.5M                                
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
};
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
  if(hull.size()==1)hull.push_back(hull[0]);
  return hull;
}
//positive for anti-clockwise
//expected a non closed circuit
long polygoanArea(vector<point>&p)
{
  int n=p.size();long area=0;
  for(int i=1;i<n-1;i++)
    area+=(p[i]-p[0])^(p[i+1]-p[0]);
  return abs(area);//signed;
}
///////////////////////////////////////
//polygoan is convex and ordered
//not closed circuit
//return the farthest distance squared;
long rotatingCalipers(vector<point>&p,vector<point>&q)
{
  long mn=LLONG_MAX;
  int a=p.size(),b=q.size();
  p.push_back(p[0]);q.push_back(q[0]);
  for(int i=0,j=0;i<a;i++)
  {
    //triangle compare.
    while(abs((p[i+1]-q[j+1])^(p[i]-q[j+1]))<abs((p[i+1]-q[j])^(p[i]-q[j])))
      j=(j+1)%b;
    mn=min(mn,abs((p[i+1]-q[j+1])^(p[i]-q[j+1])));
  }
  return mn;
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
    vector<point>vec=v,u;
    v=monotoneChain(v);v.pop_back();
    if(v.size()==n)
    {
      cout<<-1<<"\n";
      continue;
    }
    map<point,int>mp;
    for(auto x:v)mp[x]=1;
    long area=polygoanArea(v);
    for(auto x:vec)
      if(!mp.count(x))u.push_back(x);
    u=monotoneChain(u);u.pop_back();
    cout<<area-rotatingCalipers(v,u)<<"\n";
  }
  return 0;
}