/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/03/2020 15:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 12700 KB                             
*  problem: https://codeforces.com/contest/1428/problem/E
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
const int N=1e6;
const long inf=1e18;
long a[N+2];
long sq(int x)
{
  return 1LL*x*x;
}
long divide(int x,int d)
{
  if(d>x)return inf;
  return sq(x/d)*(d-x%d)+sq(x/d+1)*(x%d);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
   long ans=0;priority_queue<vector<long> >pq;
  for(int i=1;i<=n;i++)
  {
    long now=divide(a[i],1);
    long nx=divide(a[i],2);
    ans+=now;pq.push({now-nx,a[i],1});
  }
  for(int i=n+1;i<=k;i++)
  {
    vector<long>v=pq.top();pq.pop();
    ans-=divide(v[1],v[2]);
     long now=divide(v[1],v[2]+1);
    long nx=divide(v[1],v[2]+2);
    ans+=now;pq.push({now-nx,v[1],v[2]+1});
  }
  cout<<ans<<endl;
  return 0;
}