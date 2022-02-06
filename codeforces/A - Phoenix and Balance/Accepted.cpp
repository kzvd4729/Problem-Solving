/****************************************************************************************
*  @author: * kzvd4729                                       created: May/01/2020 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1348/problem/A
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;long a=0,b=0;
    for(int i=1;i<n/2;i++)
      a+=(1<<i);
    for(int i=n/2;i<n;i++)
      b+=(1<<i);
    a+=(1<<n);cout<<abs(a-b)<<"\n";
  }
  return 0;
}