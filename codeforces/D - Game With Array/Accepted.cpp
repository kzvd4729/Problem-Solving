/****************************************************************************************
*  @author: * kzvd4729                                       created: May/16/2020 18:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1355/problem/D
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
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,s;cin>>n>>s;
  if(s>=n+n)
  {
    cout<<"YES\n";
    for(int i=1;i<n;i++)cout<<2<<" ";
      cout<<s-n*2+2<<endl;
    cout<<1<<endl;
  }
  else cout<<"NO\n";
   return 0;
}