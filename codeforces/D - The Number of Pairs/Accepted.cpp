/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2021 19:36                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 1232 ms                                         memory_used: 78400 KB                             
*  problem: https://codeforces.com/contest/1499/problem/D
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
const int N=2e7,inf=1e9,mod=1e9+7;
const long INF=1LL*inf*inf;
 int pr[N+2];
void seive()
{
  for(int i=2;i<=N;i++)
  {
    if(pr[i])continue;
    for(int j=i;j<=N;j+=i)pr[j]++;
  }
}
vector<int>divisors(int x)
{
  int sq=sqrt(x+1);vector<int>ret;
  for(int i=1;i<=sq;i++)
  {
    if((x%i)==0)ret.push_back(i),ret.push_back(x/i);
  }
  sort(ret.begin(),ret.end());
  ret.erase(unique(ret.begin(),ret.end()),ret.end());
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();
   int t;cin>>t;
  while(t--)
  {
    int c,d,x;cin>>c>>d>>x;
     vector<int>v=divisors(x);
    long ans=0;
    for(auto gc:v)
    {
      long now=0;
      if((1LL*d*gc+x)%c)continue;
      long lc=(1LL*d*gc+x)/c;
      if(lc%gc)continue; lc/=gc;
       //cout<<gc<<" "<<lc<<endl;
      if(lc>N)assert(0);
       ans+=(1<<pr[lc]);
    }
    cout<<ans<<'\n';
  }  
  return 0;
}