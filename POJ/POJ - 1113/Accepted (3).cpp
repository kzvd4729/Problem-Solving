/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-05 17:32:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 188                                        memory_used (MB): 0.3                             
*  problem: https://vjudge.net/problem/POJ-1113
****************************************************************************************/
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int N=1e3;
const double pi=acos(-1.0);
int n,l;
struct point
{
  int x,y;
}pt[N+2];
stack<point>st;
vector<point>up,lw,hull;
bool cmp(point a,point b)
{
  if(a.x!=b.x)return a.x<b.x;
  else return a.y<b.y;
}
int cross(point a,point b,point c)
{
  b.x-=a.x;
  b.y-=a.y;
  c.x-=a.x;
  c.y-=a.y;
  return -(b.x*c.y-c.x*b.y);
}
void balance(void)
{
  while(st.size()>=3)
  {
    point c=st.top();st.pop();
    point b=st.top();st.pop();
    point a=st.top();
    if(cross(a,b,c)>=0)st.push(c);
    else
    {
      st.push(b);
      st.push(c);
      break;
    }
  }
}
void upper(void)
{
  for(int i=n;i>=1;i--)
  {
    st.push(pt[i]);
    balance();
  }
  while(st.size())
  {
    hull.push_back(st.top());
    st.pop();
  }
}
void lower(void)
{
  for(int i=1;i<=n;i++)
  {
    st.push(pt[i]);
    balance();
  }
  st.pop();
  while(st.size())
  {
    hull.push_back(st.top());
    st.pop();
  }
}
double dis(point a,point b)
{
  double d1=(a.x-b.x)*(a.x-b.x);
  double d2=(a.y-b.y)*(a.y-b.y);
  return sqrt(d1+d2);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>l;
  for(int i=1;i<=n;i++)
    cin>>pt[i].x>>pt[i].y;
  sort(pt+1,pt+n+1,cmp);

  upper();
  lower();

  double sum=2*pi*l;
  for(int i=0;i<hull.size()-1;i++)
    sum+=dis(hull[i],hull[i+1]);
  cout<<setprecision(0)<<fixed<<sum<<endl;
  return 0;
}