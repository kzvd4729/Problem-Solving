/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-14 17:15:28                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1018
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=(1<<17);
int mt[20][20],dp[N+2],n;
struct point
{
  int x,y;
  point(){}
  point(int _x,int _y){x=_x,y=_y;}
  point operator+(point p){return {x+p.x,y+p.y};}
  point operator-(point p){return {x-p.x,y-p.y};}
  int operator*(point p){return {x*p.x+y*p.y};}
  int operator^(point p){return {x*p.y-y*p.x};}
};
struct line
{
  point v;int c;
  line(){}
  line(point _v,int _c){v=_v,c=_c;}
  line(point p1,point p2){v=p2-p1;c=v^p1;}
  int pointlinedistmul(point p){return (int)(v^p)-c;}
};
vector<point>pp;
int dfs(int msk)
{
  if(dp[msk]!=-1)return dp[msk];
  int f=0,now=1e9;
  for(int i=0;i<n;i++)
  {
    if(msk&(1<<i))continue;
    f=1;now=min(now,1+dfs(msk|(1<<i)));
    for(int j=i+1;j<n;j++)
      now=min(now,1+dfs(msk|mt[i][j]));
  }
  if(!f)now=0;
  return dp[msk]=now;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n;vector<pair<int,int> >v(n);
    for(int i=0;i<n;i++)
      cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    pp.clear();n=v.size();
    for(int i=0;i<v.size();i++)
    {
      point p;p.x=v[i].first,p.y=v[i].second;
      pp.push_back(p);
    }
    memset(mt,0,sizeof(mt));
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        line ln(pp[i],pp[j]);
        int msk=0;msk|=(1<<i);msk|=(1<<j);
        for(int k=j+1;k<n;k++)
        {
          if(!ln.pointlinedistmul(pp[k]))
            msk|=(1<<k);
        }
        mt[i][j]=msk;
      }
    }
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<++tc<<": "<<dfs(0)<<"\n";
  }
  return 0;
}