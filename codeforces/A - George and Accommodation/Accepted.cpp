/****************************************************************************************
*  @author: kzvd4729#                                        created: May/29/2020 16:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/467/problem/A
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,ans=0;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int a,b;cin>>a>>b;ans+=(b>=(a+2));
  }
  cout<<ans<<endl;
    return 0;
}