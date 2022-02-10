/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-05 21:40:51                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1203
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const double pi=acos(-1.0);
int n,tc;
const double dd=1e18;
struct point
{
  int x,y;
}p[N+2];
stack<point>st;
bool cmp(point A,point B)
{
  if(A.x!=B.x)return A.x<B.x;
  else return A.y<B.y;
}
int cross(point a,point b,point c)
{
  b.x-=a.x;b.y-=a.y;
  c.x-=a.x;c.y-=a.y;
  long long tmp=(b.x*1LL)*c.y-(c.x*1LL)*b.y;
  if(tmp>0)return 1;
  else if(tmp<0)return -1;
  else return 0;
}
void balance(void)
{
  while(st.size()>=3)
  {
    point c=st.top();st.pop();
    point b=st.top();st.pop();
    point a=st.top();
    if(cross(a,b,c)<=0)st.push(c);
    else
    {
      st.push(b);st.push(c);
      break;
    }
  }
}
double angle(point a,point c,point b)
{
  //cout<<a.x<<" "<<a.y<<" "<<c.x<<" "<<c.y<<" "<<b.x<<" "<<b.y<<endl;
  a.x-=c.x;a.y-=c.y;
  b.x-=c.x;b.y-=c.y;
  if((a.x==0&&a.y==0)||(b.x==0&&b.y==0))return 181.0;
  double aa=atan2(a.y*1.0,a.x*1.0)*180.0/pi;
  double bb=atan2(b.y*1.0,b.x*1.0)*180.0/pi;
  if(aa<0&&bb<0)aa*=-1.0,bb*=-1.0;
  if(aa>=0&&bb>=0)return fabs(aa-bb);
  if(aa<0)swap(aa,bb);
  double ret=aa+fabs(bb);
  ret=min(ret,180.0-aa+180.0-fabs(bb));
  return ret;
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
  ios_base::sync_with_stdio(0);cin.tie(0);
  cout<<setprecision(12)<<fixed;

  //cout<<cross({0,0},{1,1},{2,0})<<endl;

  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>p[i].x>>p[i].y;
    sort(p+1,p+n+1,cmp);
    vector<point>hull=make_hull();
//    for(auto xx:hull)
//      cout<<xx.x<<" "<<xx.y<<endl;
    hull.pop_back();double ans=181.0;
    for(int i=0,j=hull.size();i<j;i++)
      ans=min(ans,angle(hull[i],hull[(i-1+j)%j],hull[(i+1)%j]));
    if(ans>180.0)ans=0.0;
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}