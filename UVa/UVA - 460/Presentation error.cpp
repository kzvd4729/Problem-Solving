/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-28 00:18:43                      
*  solution_verdict: Presentation error                      language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-460
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  int x,y;
};
bool in_rec(point a,point b,point c)
{
  int mnx=min(b.x,c.x),mxx=max(b.x,c.x);
  int mny=min(b.y,c.y),mxy=max(b.y,c.y);
  return a.x>=mnx&&a.x<=mxx&&a.y>=mny&&a.y<=mxy;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    point a,b,c,d,e,f;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    e.x=max(a.x,c.x);e.y=max(a.y,c.y);
    f.x=min(b.x,d.x);f.y=min(b.y,d.y);

    if(f.x<=e.x||f.y<=e.y)cout<<"No Overlap"<<endl;
    else cout<<e.x<<" "<<e.y<<" "<<f.x<<" "<<f.y<<endl;
  } 
  return 0;
}