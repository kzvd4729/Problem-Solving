/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/19/2021 21:02                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 1372 ms                                         memory_used: 13000 KB                             
*  problem: https://codeforces.com/contest/1514/problem/D
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
const int N=3e5,inf=1e9,mod=1e9+7;
 int a[N+2];
vector<int>v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    v[a[i]].push_back(i);
  }
   int th=40;
  while(q--)
  {
    int l,r;cin>>l>>r;
     vector<int>can;
    for(int i=1;i<=th;i++)can.push_back(a[l+rng()%(r-l+1)]);
     sort(can.begin(),can.end());
    can.erase(unique(can.begin(),can.end()),can.end());
     int tt=r-l+1,fr=-1;
    for(auto x:can)
    {
      int now=upper_bound(v[x].begin(),v[x].end(),r)-lower_bound(v[x].begin(),v[x].end(),l);
      if(now>tt-now){fr=now;break;}
    }
    if(fr==-1)cout<<1<<'\n';
    else cout<<fr-(tt-fr)<<'\n';
  }
    return 0;
}