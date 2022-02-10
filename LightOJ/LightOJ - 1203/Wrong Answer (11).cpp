/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-05 17:34:29                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1203
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const long double pi=acos(-1.0);
int n,tc;
struct point
{
  int x,y;
}p[N+2];
stack<point>st;
long long cross(point a,point b,point c)
{
  b.x-=a.x;b.y-=a.y;
  c.x-=a.x;c.y-=a.y;
  return (b.x*1LL)*c.y-(c.x*1LL)*b.y;
}
bool cmp(point a,point b)
{
  if(a.x!=b.x)return a.x<b.x;
  else return a.y<b.y;
}
void balance(void)
{
  while(st.size()>=3)
  {
    point c=st.top();st.pop();
    point b=st.top();st.pop();
    point a=st.top();
    if(cross(a,b,c)<=0)
      st.push(c);
    else
    {
      st.push(b);st.push(c);
      break;
    }
  }
}
long double angle(point a,point b,point c)
{
  a.x-=b.x;a.y-=b.y;
  c.x-=b.x;c.y-=b.y;
  //cout<<a.x<<" "<<a.y<<" "<<c.x<<" "<<c.y<<endl;
  long double ac=(a.x*1.0)*c.x+(a.y*1.0)*c.y;
  long double aa=sqrt((a.x*1.0)*a.x+(a.y*1.0)*a.y);
  long double cc=sqrt((c.x*1.0)*c.x+(c.y*1.0)*c.y);
  //cout<<ac<<" "<<aa<<" "<<cc<<endl;
  //cout<<((acos(ac/(aa*cc)))/pi)*180.0<<endl;
  return ((acos(ac/(aa*cc)))/pi)*180.0;
}
vector<point>make_hull(void)
{
  vector<point>hull;
  while(st.size())st.pop();
  for(int i=n;i>=1;i--)
  {
    st.push(p[i]);balance();
  }
  while(st.size())
  {
    hull.push_back(st.top());
    st.pop();
  }
  for(int i=1;i<=n;i++)
  {
    st.push(p[i]);balance();
  }
  st.pop();
  while(st.size())
  {
    hull.push_back(st.top());
    st.pop();
  }
  return hull;
}
int main()
{
  //cout<<setprecision(6)<<fixed<<angle({0,0},{1,0},{1,1})<<endl;
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d%d",&p[i].x,&p[i].y);
    sort(p+1,p+n+1,cmp);
    vector<point>hull=make_hull();
    long double ans=123456.0;
    if(n>=3&&hull.size()>=3)
    {
      ans=min(ans,angle(hull[0],hull[1],hull[(int)hull.size()-2]));
      for(int i=1;i<hull.size()-1;i++)
        ans=min(ans,angle(hull[i-1],hull[i],hull[i+1]));
    }
    if(ans>180.0)ans=0.000000;
    cout<<"Case "<<++tc<<": "<<setprecision(10)<<fixed<<ans<<endl;
  }
  return 0;
}