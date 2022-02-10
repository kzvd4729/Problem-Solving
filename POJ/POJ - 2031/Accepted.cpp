/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-05 22:30:19                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 188                                        memory_used (MB): 1                               
*  problem: https://vjudge.net/problem/POJ-2031
****************************************************************************************/
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<stack>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=1e2;
int n,vis[N+2];
struct point
{
  double x,y,z,r;
}pt[N+2];
double dis(point a,point b)
{
  double t1=(a.x-b.x)*(a.x-b.x);
  double t2=(a.y-b.y)*(a.y-b.y);
  double t3=(a.z-b.z)*(a.z-b.z);
  return sqrt(t1+t2+t3);
}
double whore(void)
{
  priority_queue<pair<double,int> >pq;
  pq.push(make_pair(0,1));
  memset(vis,0,sizeof(vis));
  double ret=0;
  while(pq.size())
  {
    pair<double,int>p=pq.top();
    pq.pop();
    if(vis[p.second])continue;
    vis[p.second]=1;
    ret-=p.first;
    for(int i=1;i<=n;i++)
    {
      if(vis[i]||i==p.second)continue;
      double ds=dis(pt[p.second],pt[i]);
      ds=ds-pt[p.second].r-pt[i].r;
      if(ds<0)
        ds=0;
      pq.push(make_pair(-ds,i));
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>n)
  {
    if(!n)break;
    for(int i=1;i<=n;i++)
      cin>>pt[i].x>>pt[i].y>>pt[i].z>>pt[i].r;
    cout<<setprecision(3)<<fixed<<whore()<<endl;
  }
  return 0;
}