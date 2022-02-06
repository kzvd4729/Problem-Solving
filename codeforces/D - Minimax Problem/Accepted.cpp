/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/18/2020 14:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 717 ms                                          memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1288/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int a,b,mt[300000+2][8+2],n,m,msk[(1<<8)+2];
bool ck(int md)
{
  for(int i=0;i<(1<<m);i++)
    msk[i]=0;
  for(int i=1;i<=n;i++)
  {
    int tmp=0;
    for(int j=1;j<=m;j++)
      tmp|=((mt[i][j]>=md)<<(j-1));
    msk[tmp]=i;
  }
  for(int i=0;i<(1<<m);i++)
  {
    for(int j=0;j<(1<<m);j++)
    {
      if(((i|j)==(1<<m)-1)&&msk[i]&&msk[j])
      {
        a=msk[i],b=msk[j];return true;
      }
    }
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      cin>>mt[i][j];
  }
  int lo=0,hi=1e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ck(md))lo=md;else hi=md;
  }
  for(md=hi;md>=lo;md--)if(ck(md))break;
  assert(a&&b);cout<<a<<" "<<b<<endl;
  return 0;
}