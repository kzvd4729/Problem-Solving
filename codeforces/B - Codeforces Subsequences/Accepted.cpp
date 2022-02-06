/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/18/2020 20:56                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1368/problem/B
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
long a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    string s="codeforces";long k;cin>>k;
  while(true)
  {
    int mn=1e9,id;
    for(int i=0;i<10;i++)
      if(a[i]<mn)mn=a[i],id=i;
    a[id]++;
     long now=1;
    for(int i=0;i<10;i++)now*=a[i];
    if(now>=k)break;
  }
  for(int i=0;i<10;i++)
    for(int j=0;j<a[i];j++)cout<<s[i];
  cout<<endl;
  return 0;
}