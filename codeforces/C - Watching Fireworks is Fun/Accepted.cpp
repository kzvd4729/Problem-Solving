/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/24/2020 00:32                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 498 ms                                          memory_used: 12500 KB                             
*  problem: https://codeforces.com/contest/372/problem/C
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=150000;
int po[N+2],pl[N+2],ti[N+2];
long a[N+2],b[N+2];
pair<long,int>dq[N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,d;cin>>n>>m>>d;
  for(int i=1;i<=m;i++)cin>>po[i]>>pl[i]>>ti[i];

  ti[0]=-1e9;
  for(int j=1;j<=m;j++)
  {
    long wn=1LL*(ti[j]-ti[j-1])*d;
    if(wn>n)wn=n;

    int l=N,r=N-1;
    for(int i=1;i<=n;i++)
    {
      while(l<=r)
      {
        if(dq[l].first>b[i])break;
        else l++;
      }
      dq[--l]={b[i],i};
      if(dq[r].second<i-wn)r--;

      a[i]=dq[r].first+pl[j]-abs(i-po[j]);
    }
    l=N,r=N-1;
    for(int i=n;i>=1;i--)
    {
      while(l<=r)
      {
        if(dq[l].first>b[i])break;
        else l++;
      }
      dq[--l]={b[i],i};
      if(dq[r].second>i+wn)r--;

      a[i]=max(a[i],dq[r].first+pl[j]-abs(i-po[j]));
    }
    for(int i=1;i<=n;i++)b[i]=a[i];

    //for(int i=1;i<=n;i++)cout<<setw(3)<<a[i]<<" ";cout<<endl;

  }
  long mn=-1e18;
  for(int i=1;i<=n;i++)mn=max(mn,a[i]);
  cout<<mn<<endl;
  return 0;
}