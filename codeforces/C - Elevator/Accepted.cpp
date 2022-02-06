/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2020 14:08                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1247 ms                                         memory_used: 188700 KB                            
*  problem: https://codeforces.com/contest/983/problem/C
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long 
using namespace std;
const int N=2e3;
int n,a[N+2],b[N+2],d[N+2][1000+2][10+2][2],sh[N+2];
void bfs()
{
  for(int i=0;i<N+2;i++)
  {
    for(int j=0;j<1000+2;j++)
      for(int k=0;k<10+2;k++)
        for(int l=0;l<2;l++)d[i][j][k][l]=1e9;
  }
  queue<vector<int> >q;d[0][0][1][0]=0;q.push({0,0,1,0});
  while(q.size())
  {
    vector<int>v=q.front();q.pop();
    int id=v[0],ms=v[1],fl=v[2],f=v[3];
     if(fl<9)
    {
      if(d[id][ms][fl][f]+1<d[id][ms][fl+1][f])
      {
        d[id][ms][fl+1][f]=d[id][ms][fl][f]+1;
        q.push({id,ms,fl+1,f});
      }
    }
    if(fl>1)
    {
      if(d[id][ms][fl][f]+1<d[id][ms][fl-1][f])
      {
        d[id][ms][fl-1][f]=d[id][ms][fl][f]+1;
        q.push({id,ms,fl-1,f});
      }
    }
    if(f&&b[id]==fl)
    {
      if(d[id][ms][fl][f]+1<d[id][ms][fl][0])
      {
        d[id][ms][fl][0]=d[id][ms][fl][f]+1;
        q.push({id,ms,fl,0});
      }
    }
    else if(ms%10==fl)
    {
      int tms=ms-fl;tms=sh[tms];
      if(d[id][ms][fl][f]+1<d[id][tms][fl][f])
      {
        d[id][tms][fl][f]=d[id][ms][fl][f]+1;
        q.push({id,tms,fl,f});
      }
    }
    else if((ms%100)/10==fl)
    {
      int tms=ms-fl*10;tms=sh[tms];
      if(d[id][ms][fl][f]+1<d[id][tms][fl][f])
      {
        d[id][tms][fl][f]=d[id][ms][fl][f]+1;
        q.push({id,tms,fl,f});
      }
    }
    else if((ms%1000)/100==fl)
    {
      int tms=ms-fl*100;tms=sh[tms];
      if(d[id][ms][fl][f]+1<d[id][tms][fl][f])
      {
        d[id][tms][fl][f]=d[id][ms][fl][f]+1;
        q.push({id,tms,fl,f});
      }
    }
    if(id<n&&a[id+1]==fl)
    {
      if(f==0)
      {
        if(d[id][ms][fl][f]+1<d[id+1][ms][fl][1])
        {
          d[id+1][ms][fl][1]=d[id][ms][fl][f]+1;
          q.push({id+1,ms,fl,1});
        }
      }
      else if(ms%10==0)
      {
        int tms=ms+b[id];tms=sh[tms];
         if(d[id][ms][fl][f]+1<d[id+1][tms][fl][f])
        {
          d[id+1][tms][fl][f]=d[id][ms][fl][f]+1;
          q.push({id+1,tms,fl,f});
        }
      }
    }
  }
  int ans=1e9;
  for(int fl=1;fl<=9;fl++)ans=min(ans,d[n][0][fl][0]);
  cout<<ans<<endl;
}
int re(int x)
{
  vector<int>v;
  v.push_back(x%10);x/=10;
  v.push_back(x%10);x/=10;
  v.push_back(x%10);x/=10;
   sort(v.begin(),v.end());
  int ret=0;
   ret=ret*10+v.back();v.pop_back();
  ret=ret*10+v.back();v.pop_back();
  ret=ret*10+v.back();v.pop_back();
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<=999;i++)sh[i]=re(i);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
   bfs();
    return 0;
}