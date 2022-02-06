/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2020 16:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/229/problem/D
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
const int N=5000,inf=1e9;
int a[N+2],b[N+2],d[N+2],bit[N+2],n;
void upd(int id,int x)
{
  for( ;id<=n;id+=id&-id)bit[id]=max(bit[id],x);
}
int get(int id)
{
  int ret=0;
  for( ;id>0;id-=id&-id)ret=max(ret,bit[id]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]+a[i];
  for(int i=1;i<=n;i++)d[i]=b[i];
   int ans=1;
  for(int j=2; ;j++)
  {
    for(int i=1;i<=n;i++)bit[i]=0;
    for(int i=2;i<=n;i++)
    {
      if(b[n]-b[i-1]<d[i-1])continue;
      int lo=i,hi=n,md;
      while(lo<hi)
      {
        md=(lo+hi)/2;
        if(b[md]-b[i-1]>=d[i-1])hi=md;
        else lo=md+1;
      }
      upd(lo,i);
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
      int g=get(i);
      if(g==0)d[i]=inf;
      else ans=j,d[i]=b[i]-b[g-1],f=1;
    }
    if(f==0)break;
  }
  cout<<n-ans<<endl;
  return 0;
}