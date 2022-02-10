/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-17 23:38:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 378                                        memory_used (MB): 5.6                             
*  problem: https://vjudge.net/problem/LightOJ-1239
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e4;
const double pi=acos(-1.0);
int t,tc,n;
double r,ans;

struct point
{
  int x,y;
};
double dis(point a,point b)
{
  return sqrt((a.x-b.x)*1LL*(a.x-b.x)+(a.y-b.y)*1LL*(a.y-b.y));
}

/*************** Convex Hull *******************/
stack<point>Stack;
bool HullCmp(point A,point B)
{
  if(A.x!=B.x)return A.x<B.x;
  return A.y<B.y;
}
long Chk(point a,point b,point c)
{
  b.x-=a.x;b.y-=a.y;c.x-=a.x;c.y-=a.y;
  return b.x*1LL*c.y-c.x*1LL*b.y;
}
void HullBalance(void)
{
  while(Stack.size()>=3)
  {
    point c=Stack.top();Stack.pop();
    point b=Stack.top();Stack.pop();
    point a=Stack.top();
    if(Chk(a,b,c)>0)Stack.push(c);
    else
    {
      Stack.push(b);Stack.push(c);
      break;
    }
  }
}
vector<point>MonotoneChain(vector<point>v)
{
  sort(v.begin(),v.end(),HullCmp);vector<point>hull;
  for(int i=n-1;i>=0;i--)
    Stack.push(v[i]),HullBalance();
  while(Stack.size())
    hull.push_back(Stack.top()),Stack.pop();
  for(int i=0;i<n;i++)
    Stack.push(v[i]),HullBalance();
  Stack.pop();
  while(Stack.size())
    hull.push_back(Stack.top()),Stack.pop();
  return hull;
}
/////////////////////////////////////////////////


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