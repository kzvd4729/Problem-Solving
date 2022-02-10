/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-02 13:40:25                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 2498                                       memory_used (MB): 9.9                             
*  problem: https://vjudge.net/problem/LightOJ-1292
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  int x,y;
  point(){};point(int _x,int _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(int d){return point(x*d,y*d);}
  point operator/(int d){return point(x/d,y/d);}
}pp[N+2];
map<pair<int,int>,int>mp;
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);

  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>pp[i].x>>pp[i].y;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      mp.clear();
      for(int j=1;j<=n;j++)
      {
        if(i==j)continue;point p=pp[j]-pp[i];
        if(p.x==0)p.y=abs(p.y);
        if(p.x<0)p=p*(-1);
        p=p/(__gcd(abs(p.x),abs(p.y)));
        mp[{p.x,p.y}]++;
      }
      for(auto x:mp)ans=max(ans,x.second);
    }
  cout<<"Case "<<++tc<<": "<<ans+1<<endl;
  }
  return 0;
}