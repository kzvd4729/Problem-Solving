/****************************************************************************************
*  @author: kzvd4729                                         created: 25-07-2019 19:56:38                      
*  solution_verdict: Time Limit Exceeded                     language: C++14                                   
*  run_time: 2.01 sec                                        memory_used: 28.6M                                
*  problem: https://www.codechef.com/problems/KTHCON
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  int x,y;
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
    if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>0)
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
//positive for anti-clockwise
//expected a non closed circuit
long polygoanArea(vector<point>&p)
{
  int n=p.size();long area=0;
  for(int i=1;i<n-1;i++)
    area+=(p[i]-p[0])^(p[i+1]-p[0]);
  return abs(area);//signed;
}
long triangleArea(point a,point b,point c)
{
  return abs((b-a)^(c-a));
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
    vector<point>u=v;
    v=monotoneChain(v);v.pop_back();
    if(v.size()==n)
    {
      cout<<-1<<"\n";
      continue;
    }
    map<point,int>mp;
    for(auto x:v)mp[x]=1;
    long area=polygoanArea(v);
    v.push_back(v[0]);long mn=LLONG_MAX;
    for(auto x:u)
    {
      if(mp[x])continue;
      for(int i=1;i<v.size();i++)
        mn=min(mn,triangleArea(x,v[i],v[i-1]));
    }
    cout<<area-mn<<"\n";
  }
  return 0;
}