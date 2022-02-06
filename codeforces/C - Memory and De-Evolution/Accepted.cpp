/****************************************************************************************
*  @author: kzvd4729                                         created: May/29/2020 11:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/712/problem/C
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
#define long long long
using namespace std;
const int N=1e6;
int x;
int dfs(int a,int b,int c)
{
  //cout<<a<<" "<<b<<" "<<endl;
  if(a>b)swap(a,b);if(a>c)swap(a,c);if(b>c)swap(b,c);
  if(a>=x)return 0;
   return 1+dfs(b+c-1,b,c);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;cin>>a>>b;x=a;cout<<dfs(b,b,b)<<endl;
  return 0;
}