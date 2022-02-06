/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/20/2020 21:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1370/problem/C
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
const int N=1e6;
int dfs(int x)
{
  if(x==1)return 0;
  set<int>st;
  if(x%2)st.insert(0);
  else
  {
    st.insert(dfs(x-1));
    int sq=sqrt(x+1);
    for(int i=2;i<=sq;i++)
    {
      if(x%i)continue;
      if(i%2)st.insert(dfs(x/i));
      if((x/i)%2)st.insert(dfs(i));
    }
  }
  for(int i=0; ;i++)
    if(st.find(i)==st.end())return i;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int x;cin>>x;
    if(dfs(x))cout<<"Ashishgup\n";
    else cout<<"FastestFinger\n";
  }
  return 0;
}