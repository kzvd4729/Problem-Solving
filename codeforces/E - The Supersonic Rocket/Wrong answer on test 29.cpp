/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/09/2018 12:57                        
*  solution_verdict: Wrong answer on test 29                 language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 2900 KB                              
*  problem: https://codeforces.com/contest/1017/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,m,kmp[N+N+N+2];
struct point
{
  int x,y;
}pt[N+2],tp[N+2];
stack<point>st;
vector<long>mt;
bool cmp(point a,point b)
{
  if(a.x!=b.x)return a.x<b.x;
  else return a.y<b.y;
}
long cross(point a,point b,point c)
{
  b.x-=a.x;b.y-=a.y;
  c.x-=a.x;c.y-=a.y;
  return b.x*1LL*c.y-c.x*1LL*b.y;
}
long dis(point a,point b)
{
  long t1=(a.x-b.x)*(a.x-b.x);
  long t2=(a.y-b.y)*(a.y-b.y);
  return t1+t2;
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
vector<point>Convex_Hull(point arr[],int sz)
{
  vector<point>hull;
  for(int i=sz;i>=1;i--)
  {
    st.push(arr[i]);
    balance();
  }
  while(st.size())
  {
    hull.push_back(st.top());
    st.pop();
  }
  for(int i=1;i<=sz;i++)
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
  return hull;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>pt[i].x>>pt[i].y;
  for(int i=1;i<=m;i++)
    cin>>tp[i].x>>tp[i].y;
   sort(pt+1,pt+n+1,cmp);
  sort(tp+1,tp+m+1,cmp);
   vector<point>a=Convex_Hull(pt,n);
  vector<point>b=Convex_Hull(tp,m);
    if(a.size()!=b.size())cout<<"NO"<<endl,exit(0);
   n=a.size();
  for(int i=0;i<n-1;i++)
    mt.push_back(dis(a[i],a[(i+1)%n]));
  int id=0;
  for(int i=0;i<n-1;i++)
  {
    long p=dis(b[i],b[(i+1)%n]);
    int now=kmp[id++];
    while(true)
    {
      if(p==mt[now])
      {
        kmp[id]=now+1;
        break;
      }
      if(!now)break;
      now=kmp[now-1];
    }
    if(kmp[id]==n-1)cout<<"YES"<<endl,exit(0);
  }
  for(int i=0;i<n-1;i++)
  {
    long p=dis(b[i],b[(i+1)%m]);
    int now=kmp[id++];
    while(true)
    {
      if(p==mt[now])
      {
        kmp[id]=now+1;
        break;
      }
      if(!now)break;
      now=kmp[now-1];
    }
    if(kmp[id]==n-1)cout<<"YES"<<endl,exit(0);
  }
  cout<<"NO"<<endl;
  return 0;
}