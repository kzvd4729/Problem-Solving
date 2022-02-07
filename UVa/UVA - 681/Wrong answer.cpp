/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-25 00:37:31                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-681
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  int x,y;
  bool operator<(const point &p)const{return y<p.y||(y==p.y&&x<p.x);}
  point operator-(const point &p)const{return {x-p.x,y-p.y};}
  int operator^(const point &p)const{return x*p.y-y*p.x;}
};
point stck[N+2];int top=0;
void balance(void)
{
  while(top>=3)
  {
    //>=0 to omit straight line point;
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;cout<<t<<"\n";
  for(int tc=1;tc<=t;tc++)
  {
    int n,tmp;cin>>n;vector<point>v(n);
    for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
    v.pop_back();if(tc<t)cin>>tmp;
    v=monotoneChain(v);
    cout<<v.size()<<"\n";
    for(auto x:v)
      cout<<x.x<<" "<<x.y<<"\n";
    if(tc<t)cout<<-1<<"\n";
  }
  return 0;
}