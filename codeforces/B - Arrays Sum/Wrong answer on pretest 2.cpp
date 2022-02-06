/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2020 21:21                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1408/problem/B
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
int a[N+2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;set<int>st;
    for(int i=1;i<=n;i++)cin>>a[i],st.insert(a[i]);
     int sz=st.size();
    if(k==1)
    {
      if(sz==1)cout<<1<<'\n';
      else cout<<-1<<'\n';
      continue;
    }
    cout<<(sz+k-1)/k<<'\n';
  }
  return 0;
}