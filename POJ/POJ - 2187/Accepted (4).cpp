/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-06 15:03:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 344                                        memory_used (MB): 1.1                             
*  problem: https://vjudge.net/problem/POJ-2187
****************************************************************************************/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5e4;
int n;
struct point
{
  int x,y;
}pt[N+2];
stack<point>st;
vector<point>hull;
bool cmp(point a,point b)
{
  if(a.x!=b.x)return a.x<b.x;
  else return a.y<b.y;
}
int area(point a,point b,point c)
{
  b.x-=a.x;b.y-=a.y;
  c.x-=a.x;c.y-=a.y;
  return b.x*c.y-c.x*b.y;
}
void balance(void)
{
  while(st.size()>=3)
  {
    point c=st.top();st.pop();
    point b=st.top();st.pop();
    point a=st.top();
    if(area(a,b,c)<=0)st.push(c);
    else
    {
      st.push(b);st.push(c);
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
    hull.push_back(st.top()),st.pop();
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
    hull.push_back(st.top()),st.pop();
  hull.pop_back();
}
long long dist(point a,point b)
{
  long long t1=(a.x-b.x)*1LL*(a.x-b.x)*1LL;
  long long t2=(a.y-b.y)*1LL*(a.y-b.y)*1LL;
  return t1+t2;
}
long long rotating_calipars(void)
{
  long long ret=0LL;
  int m=hull.size();
  int k=1;
  while(abs(area(hull[m-1],hull[0],hull[(k+1)%m]))>abs(area(hull[m-1],hull[0],hull[k])))
    k++;
  for(int i=0,j=k;i<m&&j<m;i++)
  {
    ret=max(ret,dist(hull[i],hull[j]));
    while(j<m&&abs(area(hull[i],hull[(i+1)%m],hull[(j+1)%m]))>abs(area(hull[i],hull[(i+1)%m],hull[j])))
    {
      ret=max(ret,dist(hull[i],hull[(j+1)%m]));
      j++;
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>pt[i].x>>pt[i].y;
  sort(pt+1,pt+n+1,cmp);
  upper();lower();
//  for(int i=0;i<hull.size();i++)
//    cout<<hull[i].x<<" "<<hull[i].y<<endl;

  cout<<rotating_calipars()<<endl;


  return 0;
}