/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/25/2021 21:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 6400 KB                              
*  problem: https://codeforces.com/contest/1506/problem/D
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=998244353;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      mp[x]++;
    }
    multiset<int>st;
    for(auto x:mp)st.insert(x.second);
     while((int)st.size()>1)
    {
      int b=*st.begin(),e=*st.rbegin();
       st.erase(st.find(b));st.erase(st.find(e));
       b--,e--;
      if(b)st.insert(b);
      if(e)st.insert(e);
    }
    int ans=0;
    if((int)st.size())ans=*st.begin();
    cout<<ans<<endl;
  }
  return 0;
}