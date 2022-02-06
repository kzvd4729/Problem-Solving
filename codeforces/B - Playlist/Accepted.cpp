/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2021 23:37                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 140 ms                                          memory_used: 14000 KB                             
*  problem: https://codeforces.com/contest/1483/problem/B
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
 int a[N+2],lt[N+2],rt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     set<int>av;
    for(int i=1;i<=n;i++)av.insert(i);
     set<pair<int,int> >st;
    for(int i=1;i<n;i++)
    {
      if(__gcd(a[i],a[i+1])==1)st.insert({i,i+1});
    }
    if(__gcd(a[n],a[1])==1)st.insert({n,1});
     int bg=1;vector<int>ans;
    while(true)
    {
      auto it=st.upper_bound({bg,-1});
       if(it==st.end())it=st.upper_bound({1,-1});
       if(it==st.end())break;
       pair<int,int>p=*it;st.erase(p);
       //cout<<p.first<<" "<<p.second<<endl;
            ans.push_back(p.second);av.erase(p.second);
      if((int)av.size()==0)break;
       auto nx=av.upper_bound(p.second);
      if(nx==av.end())nx=av.lower_bound(1);
             if(st.find({p.second,*nx})!=st.end())st.erase({p.second,*nx});
       if(__gcd(a[p.first],a[*nx])==1)st.insert({p.first,*nx});
       bg=p.second;
    }
    cout<<ans.size()<<' ';
    for(auto x:ans)cout<<x<<" ";cout<<'\n';
  }
  return 0;
}