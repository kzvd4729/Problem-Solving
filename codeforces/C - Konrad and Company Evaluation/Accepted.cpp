/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/26/2020 15:37                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 421 ms                                          memory_used: 9300 KB                              
*  problem: https://codeforces.com/contest/1229/problem/C
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
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=2e5;
int out[N+2];
vector<int>in[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int a,b;cin>>a>>b;
    if(a>b)swap(a,b);
    out[b]++;in[a].push_back(b);
  }
  long ans=0;
  for(int i=1;i<=n;i++)ans+=1LL*in[i].size()*out[i];
   cout<<ans<<'\n';int q;cin>>q;
  while(q--)
  {
    int a;cin>>a;
    ans-=1LL*in[a].size()*out[a];
    for(auto x:in[a])ans-=1LL*in[x].size()*out[x];
     for(auto bg:in[a])
    {
      out[a]++;
       out[bg]--;in[bg].push_back(a);
      ans+=1LL*in[bg].size()*out[bg];
    }
    in[a].clear();cout<<ans<<'\n';
  }
  return 0;
}