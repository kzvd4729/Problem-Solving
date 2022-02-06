/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/21/2018 19:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/474/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const double eps=0.000001;
struct point
{
  int x,y;
}aa[5],tmp[5];
point rotate(point a,point o)
{
  point p;p.x=a.x-o.x;p.y=a.y-o.y;
  point ret;
  ret.x=-p.y;ret.y=p.x;
  ret.x+=o.x;ret.y+=o.y;
  return ret;
}
double dis(point a,point b)
{
  return sqrt(((a.x-b.x)*1.0*(a.x-b.x)+(a.y-b.y)*1.0*(a.y-b.y))*1.0);
}
bool ok(void)
{
  for(int i=1;i<=4;i++)aa[i]=tmp[i];
  set<pair<int,int> >st;
  for(int i=1;i<=4;i++)st.insert({aa[i].x,aa[i].y});
  if(st.size()<4)return false;
   vector<double>v,b;
  for(int i=2;i<=4;i++)
    v.push_back(dis(aa[1],aa[i]));
  sort(v.begin(),v.end());
   double xx=sqrt(2.0)*v[0];
  if(fabs(xx-v[2])>eps)return false;
   xx=sqrt(2.0)*v[1];
  if(fabs(xx-v[2])>eps)return false;
   for(int i=2;i<=4;i++)
  {
    b.clear();
    for(int j=1;j<=4;j++)
    {
      if(i==j)continue;
      b.push_back(dis(aa[i],aa[j]));
    }
    sort(b.begin(),b.end());
    for(int j=0;j<v.size();j++)
    {
      if(fabs(v[j]-b[j])>eps)return false;
    }
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  while(n--)
  {
    point pp[5],oo[5];int ii[5];
    for(int i=1;i<=4;i++)
      cin>>pp[i].x>>pp[i].y>>oo[i].x>>oo[i].y;
    int ans=1e9;
    for(ii[1]=0;ii[1]<4;ii[1]++)
    {
      if(ii[1]==0)tmp[1]=pp[1];
      else tmp[1]=rotate(tmp[1],oo[1]);
      for(ii[2]=0;ii[2]<4;ii[2]++)
      {
        if(ii[2]==0)tmp[2]=pp[2];
        else tmp[2]=rotate(tmp[2],oo[2]);
        for(ii[3]=0;ii[3]<4;ii[3]++)
        {
          if(ii[3]==0)tmp[3]=pp[3];
          else tmp[3]=rotate(tmp[3],oo[3]);
          for(ii[4]=0;ii[4]<4;ii[4]++)
          {
            if(ii[4]==0)tmp[4]=pp[4];
            else tmp[4]=rotate(tmp[4],oo[4]);
            if(ok())ans=min(ans,ii[1]+ii[2]+ii[3]+ii[4]);
          }
        }
      }
    }
    if(ans>100)ans=-1;
    cout<<ans<<"\n";
  }
  return 0;
}