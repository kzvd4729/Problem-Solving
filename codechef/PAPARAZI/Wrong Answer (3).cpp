/****************************************************************************************
*  @author: kzvd4729                                         created: 09-03-2021 22:06:40                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/MARCH21A/problems/PAPARAZI
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
struct point
{
  int x,y;
  point():x(0),y(0) {};
  point(int _x,int _y):x(_x),y(_y) {}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
    long operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //signed area of the parallelogram by two vector
    //positive if p is ccw to the vector
  }
};
vector<point> convexHull(vector<point>p)
{
  sort(p.begin(),p.end());int n=p.size(),top=0;//polygon are changed
  vector<point>stck(n+10),h;
  for(int i=n-1;i>=0;i--)
  {
    stck[++top]=p[i];
    while(top>2)
    {
      //>=0 to omit straight line point;
      if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>=0)
        stck[top-1]=stck[top],top--;
      else break;
    }
  }
  while(top>0)h.push_back(stck[top--]);
  for(int i=0;i<n;i++)
  {
    stck[++top]=p[i];
    while(top>2)
    {
      //>=0 to omit straight line point;
      if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>=0)
        stck[top-1]=stck[top],top--;
      else break;
    } 
  }
  top--;
  while(top>0)h.push_back(stck[top--]);
  if(h.size()>1)h.pop_back();
  return h;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<point>p(n);
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;i++)
    {
      int x;cin>>x;
      p[i]=point(i+1,x);
      mp[{i+1,x}]=i+1;
    }
    p.push_back(point(1,0));
    p.push_back(point(n,0));
    p=convexHull(p);
    if((int)p.size()==0)assert(0);
    n=p.size();int ans=0;
    for(int i=0;i<n;i++)
    {
      int j=(i+1)%n;
      if(mp.count({p[i].x,p[i].y})==0)continue;
      if(mp.count({p[j].x,p[j].y})==0)continue;
      ans=max(ans,abs(mp[{p[i].x,p[i].y}]-mp[{p[j].x,p[j].y}]));
    }
    //if(ans==0)assert(0);
    cout<<ans<<'\n';
  }
  return 0;
}