/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/24/2020 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1454/problem/B
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
int a[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];fr[a[i]]++;
    }
    int mn=N,id=-1;
    for(int i=1;i<=n;i++)
    {
      if(fr[a[i]]==1&&a[i]<mn)mn=a[i],id=i;
    }
    cout<<id<<'\n';
    for(int i=1;i<=n;i++)fr[a[i]]--;
  }
  return 0;
}