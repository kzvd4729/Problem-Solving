/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/25/2020 21:14                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1468/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
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
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;int ans=2e9;
    for(int i=1;i<=m;i++)
    {
      int a,b,c;cin>>a>>b>>c;
      ans=min(ans,abs(c-k));
    }
    cout<<ans<<endl;
  }
  return 0;
}