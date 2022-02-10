/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-24 23:47:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 420                                        memory_used (MB): 11.3                            
*  problem: https://vjudge.net/problem/SPOJ-BSHEEP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  int x,y,id;
  bool operator<(const point &p)const{return y<p.y||(y==p.y&&x<p.x);}
  point operator-(const point &p)const{return {x-p.x,y-p.y};}
  int operator^(const point &p)const{return x*p.y-y*p.x;}
  double dis(const point &p)const{return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
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

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<point>v;
    map<point,int>mp;//highest complexity
    for(int i=0;i<n;i++)
    {
      point p;
      cin>>p.x>>p.y;p.id=i;
      if(mp.count(p))continue;
      mp[p]=1;v.push_back(p);
    }
    v=monotoneChain(v);
    double ans=0;
    for(int i=1;i<v.size();i++)
      ans+=v[i].dis(v[i-1]);
    cout<<setprecision(2)<<fixed<<ans<<"\n";
    if(v.size()==1)v.push_back(v.back());
    for(int i=0;i<v.size()-1;i++)
    {
      if(i)cout<<" ";
      cout<<v[i].id+1;
    }
    cout<<"\n"<<"\n";
  }
  return 0;
}