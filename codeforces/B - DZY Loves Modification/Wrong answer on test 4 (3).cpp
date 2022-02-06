/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/05/2020 16:58                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 7900 KB                              
*  problem: https://codeforces.com/contest/446/problem/B
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
const int N=1e3;
long aa[N+2][N+2],a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,k,p;cin>>n>>m>>k>>p;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)cin>>aa[i][j];
  }
  priority_queue<long>pq;
  for(int i=1;i<=n;i++)
  {
    long sm=0;
    for(int j=1;j<=m;j++)
      sm+=aa[i][j];
    pq.push(sm);
  }
  for(int i=1;i<=k;i++)
  {
    long tp=pq.top();pq.pop();
    a[i]=a[i-1]+tp;pq.push(tp-p*m);
  }
  while(pq.size())pq.pop();
  for(int j=1;j<=m;j++)
  {
    long sm=0;
    for(int i=1;i<=n;i++)
      sm+=aa[i][j];
    pq.push(sm);
  }
  for(int i=1;i<=k;i++)
  {
    long tp=pq.top();pq.pop();
    b[i]=b[i-1]+tp;pq.push(tp-p*n);
  }
  long ans=-1e18;
  for(int i=0;i<=k;i++)
    ans=max(ans,a[i]+b[k-i]-1LL*i*(k-i)*p);
  cout<<ans<<endl;
  return 0;
}