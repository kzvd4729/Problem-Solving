/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/08/2021 20:56                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 389 ms                                          memory_used: 39200 KB                             
*  problem: https://codeforces.com/gym/102966/problem/L
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
const int N=1e7,inf=1e9,mod=1e9+7;
 int pr[N+2];
void factorize()
{
  for(int i=2;i<=N;i++)
  {
    if(pr[i])continue;
    for(int j=i;j<=N;j+=i)pr[j]=i;
  }
}
vector<int>v;
void abc(int x)
{
  while(x>1)
  {
    v.push_back(pr[x]);
    x/=pr[x];
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  factorize();
   int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;
    v.clear();abc(a);abc(b);
        sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    cout<<v.size()<<'\n';
  }
    return 0;
}