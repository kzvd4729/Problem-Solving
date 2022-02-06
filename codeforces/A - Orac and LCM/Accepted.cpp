/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2020 10:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 12800 KB                             
*  problem: https://codeforces.com/contest/1349/problem/A
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
#define long long long
using namespace std;
const int N=2e5;
int vs[N+2];
vector<int>pr[N+2];
void seive()
{
  for(int i=2;i<=N;i++)
  {
    if(vs[i])continue;
    for(int j=i;j<=N;j+=i)pr[j].push_back(i),vs[j]=1;
  }
}
int cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();int n;cin>>n;long ans=1;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    for(auto p:pr[x])
    {
      int now=1,z=x;
      while(z%p==0)
      { 
        z/=p,now*=p;
        cnt[now]++;
      }
    }
  }
  memset(vs,0,sizeof(vs));
  for(int i=2;i<=N;i++)
  {
    if(vs[i])continue;long p=1,ml=1;
    while(true)
    {
      p*=i;if(p>N)break;
      if(cnt[p]>=n-1)ml=p;
    }
    ans*=ml;
    for(int j=i;j<=N;j+=i)vs[j]=1;
  }
  cout<<ans<<endl;
  return 0;
}