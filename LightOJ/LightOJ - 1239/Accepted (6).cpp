/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-17 22:41:45                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 414                                        memory_used (MB): 4.5                             
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
}arr[N+2];
stack<point>st;
vector<point>hull;
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
void lower(void)
{
  for(int i=n;i>=1;i--)
  {
    st.push(arr[i]);
    balance();
  }
  while(st.size())
  {
    hull.push_back(st.top());
    st.pop();
  }
}
void upper(void)
{
  for(int i=1;i<=n;i++)
  {
    st.push(arr[i]);
    balance();
  }
  st.pop();
  while(st.size())
  {
    hull.push_back(st.top());
    st.pop();
  }
}
int main()
{
  cin>>t;
  while(t--)
  {
    cin>>n>>r;
    for(int i=1;i<=n;i++)
      cin>>arr[i].x>>arr[i].y;
    sort(arr+1,arr+n+1,cmp);
    hull.clear();
    lower();
    upper();
    ans=0.0;
    for(int i=1;i<hull.size();i++)
      ans+=dis(hull[i],hull[i-1]);
    ans+=(2*pi*r);
    cout<<setprecision(10)<<fixed;
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}