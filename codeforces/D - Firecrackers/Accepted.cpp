/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/25/2020 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1468/problem/D
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
    int n,m,a,b;cin>>n>>m>>a>>b;
    for(int i=1;i<=m;i++)cin>>aa[i];
     sort(aa+1,aa+m+1);m=min(m,abs(a-b)-1);
    int mx;
    if(a<b)mx=b-1;else mx=n-b;
    int cnt=0,id=1;
    for(int i=m;i>=1;i--)
    {
      if(id+aa[i]<=mx)cnt++,id++;
    }
    cout<<cnt<<endl;
  }
  return 0;
}