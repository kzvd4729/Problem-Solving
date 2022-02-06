/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/25/2020 19:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1468/problem/E
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    vector<int>v(4);
    for(int i=0;i<4;i++)cin>>v[i];
    int ans=0;
    do
    {
      ans=max(ans,min(v[0],v[1])*min(v[2],v[3]));
    }while(next_permutation(v.begin(),v.end()));
    cout<<ans<<endl;
  }
  return 0;
}