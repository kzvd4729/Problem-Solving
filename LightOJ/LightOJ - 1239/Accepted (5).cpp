/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-17 22:53:57                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 390                                        memory_used (MB): 5.6                             
*  problem: https://vjudge.net/problem/LightOJ-1239
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
const long double pi=acos(-1.0);
int t,tc,n;
long double r,ans;
struct point
{
  int x,y;
};
stack<point>st;
bool cmp(point A,point B)
{
  if(A.x!=B.x)return A.x<B.x;
  return A.y<B.y;
}
long long area(point a,point b,point c)
{
  b.x-=a.x;b.y-=a.y;
  c.x-=a.x;c.y-=a.y;
  return b.x*1LL*c.y-c.x*1LL*b.y;
}
long double dis(point a,point b)
{
  return sqrt((a.x-b.x)*1LL*(a.x-b.x)+(a.y-b.y)*1LL*(a.y-b.y));
}
void balance(void)
{
  while(st.size()>=3)
  {
    point c=st.top();st.pop();
    point b=st.top();st.pop();
    point a=st.top();
    if(area(a,b,c)>0)st.push(c);
    else
    {
      st.push(b);st.push(c);
      break;
    }
  }
}
vector<point>MonotoneChain(vector<point>v)
{
  sort(v.begin(),v.end(),cmp);
  vector<point>hull;
  for(int i=n-1;i>=0;i--)
  {
    st.push(v[i]);
    balance();
  }
  while(st.size())
  {
    hull.push_back(st.top());
    st.pop();
  }
  for(int i=0;i<n;i++)
  {
    st.push(v[i]);
    balance();
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
  cin>>t;
  while(t--)
  {
    cin>>n>>r;
    vector<point>v;
    for(int i=1;i<=n;i++)
    {
      point p;cin>>p.x>>p.y;
      v.push_back(p);
    }
    vector<point>hull=MonotoneChain(v);
    ans=0.0;
    for(int i=1;i<hull.size();i++)
      ans+=dis(hull[i],hull[i-1]);
    ans+=(2*pi*r);
    cout<<setprecision(10)<<fixed;
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}