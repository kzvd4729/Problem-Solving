/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2021 19:31                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 77 ms                                           memory_used: 32900 KB                             
*  problem: https://codeforces.com/contest/1483/problem/A
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 vector<int>v[N+2];
int ans[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)v[i].clear();
    for(int i=1;i<=m;i++)
    {
      int k;cin>>k;
      while(k--)
      {
        int x;cin>>x;
        v[i].push_back(x);
      }
    }
    for(int i=1;i<=n;i++)cnt[i]=0;
    for(int i=1;i<=m;i++)ans[i]=v[i][0],cnt[v[i][0]]++;
     int mx=-1,fr;
    for(int i=1;i<=n;i++)if(cnt[i]>mx)mx=cnt[i],fr=i;
     if(mx>(m+1)/2)
    {
      for(int i=1;i<=m;i++)
      {
        if(mx<=(m+1)/2)break;
        if(ans[i]!=fr)continue;
        if((int)v[i].size()>1)
        {
          mx--;ans[i]=v[i][1];
        }
      }
    }
    if(mx>(m+1)/2)cout<<"NO\n";
    else 
    {
      cout<<"YES\n";
      for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
  }
  return 0;
}