/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/13/2020 22:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1438/problem/E
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
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    long sm=0;
    for(int j=i+1;j<n;j++)
    {
      sm+=a[j];if(sm>=a[i]+a[i])break;
      if(sm==(a[i]^a[j+1]))st.insert({i,j+1});
    }
  }
  for(int i=n;i>=1;i--)
  {
    long sm=0;
    for(int j=i-1;j>1;j--)
    {
      sm+=a[j];if(sm>=a[i]+a[i])break;
      if(sm==(a[i]^a[j-1]))st.insert({j-1,i});
    }
  }
  cout<<(int)st.size()<<endl;
  return 0;
}