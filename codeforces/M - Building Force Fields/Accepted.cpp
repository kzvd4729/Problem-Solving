/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2019 20:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 717 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/gym/100814/problem/M
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
 #define setp(a) cout<<setprecision(a)<<fixed
const double eps=1e-9,pi=acos(-1.0);
 struct point
{
  long x,y;
  point(){};point(long _x,long _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(long d){return point(x*d,y*d);}
  point operator/(long d){return point(x/d,y/d);}
  double dist(point p){return sqrt((1.0*(x-p.x))*(x-p.x)+(1.0*(y-p.y))*(y-p.y));}
  long operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //sigbed area of the parallelogram by two vector
    //positive if p is ccw to the point
  }
}p[N+2];
bool del(point a,point b,point c)
{
  long sgn=(b-a)^(c-a);
  return sgn<=0?true:false;
}
double dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    for(long i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
     dp[1]=1e15;stack<long>st;
    for(long i=2;i<=n;i++)
    {
      double d=p[i].dist(p[i-1]);
      dp[i]=d+dp[i-2];while(st.size())st.pop();
      st.push(i);st.push(i-1);
       for(long j=i-2;j>=1;j--)
      {
        while(st.size()>=2)
        {
          long b=st.top();st.pop();
          long a=st.top();
           if(del(p[a],p[b],p[j]))d-=p[a].dist(p[b]);
          else{st.push(b);break;}
        }
        d+=p[j].dist(p[st.top()]);st.push(j);
        dp[i]=min(dp[i],d+dp[j-1]);
      }
    }
    setp(6);cout<<dp[n]<<"\n";
  }
  return 0;
}