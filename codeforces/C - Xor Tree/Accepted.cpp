/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/15/2020 22:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 50900 KB                             
*  problem: https://codeforces.com/contest/1446/problem/C
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
const int N=2e5;
int sz;
struct trie
{
  int nx[2];
}tr[N*32+2];
void insrt(int x)
{
  int now=0;
  for(int i=30-1;i>=0;i--)
  {
    bool c=(x&(1<<i));
    if(tr[now].nx[c]==0)tr[now].nx[c]=++sz;
    now=tr[now].nx[c];
  }
}
int dfs(int now)
{
  if(tr[now].nx[0]&&tr[now].nx[1])
  {
    int a=dfs(tr[now].nx[0]);
    int b=dfs(tr[now].nx[1]);
    return max(a+1,b+1);
  }
  else if(tr[now].nx[0])return dfs(tr[now].nx[0]);
  else if(tr[now].nx[1])return dfs(tr[now].nx[1]);
  else return 1;
}
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],insrt(a[i]);
   cout<<n-dfs(0)<<endl;
   return 0;
}