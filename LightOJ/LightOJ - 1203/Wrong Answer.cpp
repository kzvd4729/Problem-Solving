/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-17 23:49:03                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1203
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const double con=180.0/acos(-1);
int t,tc,n,nn,u,v;
map<pair<int,int>,int>vis;
struct point
{
    long x,y;
}arr[N+2];
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

double find_ang(point a,point b,point c)
{
    b.x-=a.x;
    b.y-=a.y;
    c.x-=a.x;
    c.y-=a.y;
    double mg=b.x*1.0*c.x+b.y*1.0*c.y;
    double ma=sqrt(b.x*1.0*b.x+b.y*1.0*b.y);
    double mb=sqrt(c.x*1.0*c.x+c.y*1.0*c.y);
    return fabs(acos(mg/(ma*mb)));
}

int main()
{
    cin>>t;
    while(t--)
    {
        n=0;
        vis.clear();vector<point>vv;
        cin>>nn;
        for(int i=1; i<=nn; i++)
        {
            cin>>u>>v;
            if(vis[make_pair(u,v)])
                continue;
            vis[make_pair(u,v)]=1;
            ++n;point p;
            p.x=u,p.y=v;vv.push_back(p);
            arr[n].x=u;
            arr[n].y=v;
        }
        //sort(arr+1,arr+n+1,cmp);
        vector<point>hull=MonotoneChain(vv);
        double ang=1e8;
        for(int i=0,l=hull.size(); i<l; i++)
            hull.push_back(hull[i]);
        for(int i=1; i<hull.size()-1; i++)
            ang=min(ang,find_ang(hull[i],hull[i-1],hull[i+1]));
        /*for(int i=0;i<hull.size();i++)
                cout<<hull[i].x<<" "<<hull[i].y<<endl;*/
        cout<<setprecision(6)<<fixed;
        ang*=con;
        if(n<3)
            ang=0.0;
        cout<<"Case "<<++tc<<": "<<ang<<endl;

    }
    return 0;
}