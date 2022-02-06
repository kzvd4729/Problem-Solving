/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2019 20:16                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 265 ms                                          memory_used: 15700 KB                             
*  problem: https://codeforces.com/gym/100814/problem/M
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
 #define setp(a) cout<<setprecision(a)<<fixed
const double eps=1e-9,pi=acos(-1.0);
 struct point
{
  int x,y;
  point(){};point(int _x,int _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(int d){return point(x*d,y*d);}
  point operator/(int d){return point(x/d,y/d);}
  double dist(point p){return sqrt((1.0*(x-p.x))*(x-p.x)+(1.0*(y-p.y))*(y-p.y));}
  int operator^(point p)
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
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
     dp[1]=1e15;stack<int>st;
    for(int i=2;i<=n;i++)
    {
      double d=p[i].dist(p[i-1]);
      dp[i]=d+dp[i-2];while(st.size())st.pop();
      st.push(i);st.push(i-1);
       for(int j=i-2;j>=1;j--)
      {
        while(st.size()>=2)
        {
          int b=st.top();st.pop();
          int a=st.top();
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