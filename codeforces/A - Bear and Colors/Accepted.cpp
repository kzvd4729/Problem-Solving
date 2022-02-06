/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/27/2020 10:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/674/problem/A
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#define long long long
using namespace std;
const int N=5e3;
int cnt[N+2],aa[N+2],ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<=n;i++)
  {
    memset(cnt,0,sizeof cnt);
    int mx=-1,id;
    for(int j=i;j<=n;j++)
    {
      cnt[aa[j]]++;
      if(cnt[aa[j]]>mx)mx=cnt[aa[j]],id=aa[j];
      else if(cnt[aa[j]]==mx)id=min(id,aa[j]);
      ans[id]++;
    }
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}