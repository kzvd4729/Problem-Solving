/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/11/2020 21:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1366/problem/C
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
const int N=1e2;
int cnt[N+2][2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    memset(cnt,0,sizeof cnt);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        int x;cin>>x;cnt[i+j][x]++;
      }
    }
    int j=n+m;int ans=0;
    for(int i=2;i<=n+m;i++)
    {
      if(j<=i)break;
      ans+=min(cnt[i][0]+cnt[j][0],cnt[i][1]+cnt[j][1]);
      j--;
    }
    cout<<ans<<endl;
  }
  return 0;
}