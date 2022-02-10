/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-02 18:28:50                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1285
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4,inf=1e9;

struct point
{
  long x,y,id;
  point(){};point(long _x,long _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(long d){return point(x*d,y*d);}
  point operator/(long d){return point(x/d,y/d);}
  bool operator==(point p){return x==p.x&&y==p.y;}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  long operator*(point p)
  {
    return x*p.x+y*p.y;//0 if vectors are perpendicular;
  }
  long operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //signed area of the parallelogram by two vector
    //positive if p is ccw to the vector
  }
}p[N+2];
int vis[N+2],ans[N+2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y,p[i].id=i-1;
    sort(p+1,p+n+1);

    for(int i=0;i<n;i++)vis[i]=0;

    int top=0;
    vector<point>stck(n+10);
    for(int i=n;i>=1;i--)
    {
      stck[++top]=p[i];//>=0 to omit straight line point;
      while(top>2)
      {
        if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>0)
          stck[top-1]=stck[top],top--;
        else break;
      }
    }
    int ind=0;
    for(int i=1;i<=top;i++)
    {
      int id=stck[i].id;vis[id]=1;
      ans[ind++]=id;
      //cout<<stck[i].x<<" "<<stck[i].y<<endl;
    }
    for(int i=1;i<=n;i++)
    {
      int id=p[i].id;if(vis[id])continue;
      ans[ind++]=id;
    }
    cout<<"Case "<<++tc<<":\n";
    cout<<ans[n-1];if(ind!=n)assert(0);
    for(int i=n-2;i>=0;i--)cout<<" "<<ans[i];
    cout<<"\n";
    //while(top>0)h.push_back(stck[top--]);
  }
  return 0;
}