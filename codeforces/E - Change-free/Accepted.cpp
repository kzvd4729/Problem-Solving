/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/09/2020 21:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 17200 KB                             
*  problem: https://codeforces.com/contest/767/problem/E
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
int c[N+2],w[N+2],a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>c[i];
  for(int i=1;i<=n;i++)cin>>w[i];
   priority_queue<pair<int,int> >pq;long ans=0;
  for(int i=1;i<=n;i++)
  {
    a[i]=c[i]/100;b[i]=c[i]%100;
    if(b[i]==0)continue;m-=b[i];
    pq.push({-w[i]*(100-b[i]),i});
     if(m<0)
    {
      pair<int,int>p=pq.top();pq.pop();
      ans-=p.first;a[p.second]++;b[p.second]=0;
      m+=100;
    }
  }
  cout<<ans<<endl;
  for(int i=1;i<=n;i++)cout<<a[i]<<" "<<b[i]<<endl;
  return 0;
}