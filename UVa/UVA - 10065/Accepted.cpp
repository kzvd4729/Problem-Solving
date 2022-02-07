/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-25 00:20:49                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10065
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
//positive for anti-clockwise
//negative for clockwise
//expected a non closed circuit
double polygoanArea(vector<point>&p)
{
  int n=p.size();double area=0;
  for(int i=1;i<n-1;i++)
    area+=(p[i]-p[0])^(p[i+1]-p[0]);
  return area/2.0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,tc=0;
  while(cin>>n)
  {
    if(!n)break;vector<point>v(n);
    for(int i=0;i<n;i++)
      cin>>v[i].x>>v[i].y;
    double a=abs(polygoanArea(v));
    v=monotoneChain(v);v.pop_back();
    double b=polygoanArea(v);
    cout<<"Tile #"<<++tc<<"\n";
    double w=((b-a)*100.0)/b;
    cout<<setprecision(2)<<fixed<<"Wasted Space = "<<w<<" %\n\n";
  }
  return 0;
}