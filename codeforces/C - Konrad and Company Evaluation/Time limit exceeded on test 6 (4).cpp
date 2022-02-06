/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/26/2020 15:33                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++14                               
*  run_time: 4000 ms                                         memory_used: 15400 KB                             
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
set<int>out[N+2];
vector<int>in[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int a,b;cin>>a>>b;
    if(a>b)swap(a,b);
    out[b].insert(a);in[a].push_back(b);
  }
  long ans=0;
  for(int i=1;i<=n;i++)ans+=1LL*in[i].size()*out[i].size();
   cout<<ans<<'\n';int q;cin>>q;
  while(q--)
  {
    int a;cin>>a;
    ans-=1LL*in[a].size()*out[a].size();
    for(auto x:in[a])ans-=1LL*in[x].size()*out[x].size();
     for(auto bg:in[a])
    {
      out[a].insert(bg);
       out[bg].erase(a);in[bg].push_back(a);
      ans+=1LL*in[bg].size()*out[bg].size();
    }
    in[a].clear();cout<<ans<<'\n';
  }
  return 0;
}