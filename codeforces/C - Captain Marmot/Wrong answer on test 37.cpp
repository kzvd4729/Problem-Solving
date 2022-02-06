/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/21/2018 18:41                        
*  solution_verdict: Wrong answer on test 37                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/474/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
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
bool cmp_x(point a,point b)
{
  return a.x<b.x;
}
bool cmp_y(point a,point b)
{
  return a.y<b.y;
}
bool ok(void)
{
  for(int i=1;i<=4;i++)aa[i]=tmp[i];
  sort(aa+1,aa+5,cmp_x);
  if(aa[1].x!=aa[2].x)return false;
  if(aa[3].x!=aa[4].x)return false;
  if(aa[2].x==aa[3].x)return false;
  if(abs(aa[1].y-aa[2].y)!=abs(aa[3].y-aa[4].y))
    return false;
  sort(aa+1,aa+5,cmp_y);
  if(aa[1].y!=aa[2].y)return false;
  if(aa[3].y!=aa[4].y)return false;
  if(aa[2].y==aa[3].y)return false;
  if(abs(aa[1].x-aa[2].x)!=abs(aa[3].x-aa[4].x))
    return false;
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