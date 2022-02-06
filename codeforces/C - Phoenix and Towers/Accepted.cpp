/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2021 21:00                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 93 ms                                           memory_used: 6300 KB                              
*  problem: https://codeforces.com/contest/1515/problem/C
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
const int N=1e6,inf=1e9,mod=1e9+7;
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m,x;cin>>n>>m>>x;set<pair<long,int> >st;
     for(int i=1;i<=m;i++)st.insert({0,i});
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      pair<long,int>p=*st.begin();st.erase(p);
       cout<<p.second<<" ";
      p.first+=x;st.insert(p);
    }
    cout<<'\n';
   }
    return 0;
}