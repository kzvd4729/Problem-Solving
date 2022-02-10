/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-24 21:41:45                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-4558
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
  int operator^(const point &p)const{return x*p.y-y*p.x;}
  bool operator==(const point &p)const{return x==p.x&&y==p.y;}
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
//returns cpunter-clock-wise;
//first=last;
//does it handle for repetative point?
vector<point>monotoneChain(vector<point>&v)
{
  sort(v.begin(),v.end());int n=v.size();

  vector<point>hull;
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
    int tc,n;cin>>tc>>n;//cout<<"top "<<top<<endl;
    vector<point>v(n);
    for(int i=0;i<n;i++)
      cin>>v[i].x>>v[i].y;
    v=monotoneChain(v);
    v.pop_back();int id=0;
    for(int i=1;i<v.size();i++)
    {
      if(v[i].y>v[id].y)id=i;
      if(v[i].y==v[id].y&&v[i].x<v[id].x)id=i;
    }
    cout<<tc<<" "<<v.size()<<"\n";
    for(int i=id;i>=0;i--)
      cout<<v[i].x<<" "<<v[i].y<<"\n";
    for(int i=v.size()-1;i>id;i--)
      cout<<v[i].x<<" "<<v[i].y<<"\n";
  }
  return 0;
}