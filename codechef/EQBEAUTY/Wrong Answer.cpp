/****************************************************************************************
*  @author: kzvd4729                                         created: 22-10-2021 14:40:49                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.05 sec                                        memory_used: 5.4M                                 
*  problem: https://www.codechef.com/SNCK1A21/problems/EQBEAUTY
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
const int N=1e6+10,inf=1e9;
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=a[n]-a[2];set<int>st;
    for(int i=2;i<n;i++)
    {
      int l=a[i]-a[1];
      ans=min(ans,abs(l-(a[n]-a[i+1])));
      auto it=st.lower_bound(l);
      if(it!=st.end())ans=min(ans,abs(l-(a[n]-*it)));
      if(it!=st.begin())
      {
        it--;
        ans=min(ans,abs(l-(a[n]-*it)));
      }
      st.insert(a[i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}