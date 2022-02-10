/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-09 14:01:39                      
*  solution_verdict: Terminated due to timeout               language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-tower-breakers-revisited-1
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
set<int>st[N+2];int g[N+2];
void cal()
{
  for(int i=1;i<=N;i++)
  {
    int x;
    for(x=0; ;x++)if(st[i].find(x)==st[i].end())break;
    g[i]=x;
    for(int j=i+i;j<=N;j+=i)
      st[j].insert(x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  
  cal();int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int xx=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;xx^=x;
    }
    if(xx)cout<<1<<'\n';
    else cout<<2<<'\n';
  }
  return 0;
}