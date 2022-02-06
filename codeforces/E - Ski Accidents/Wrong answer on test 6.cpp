/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2020 15:42                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++17                               
*  run_time: 1216 ms                                         memory_used: 47100 KB                             
*  problem: https://codeforces.com/contest/1368/problem/E
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
set<int>in[N+2],out[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;map<pair<int,int>,int>mp;
    for(int i=1;i<=n;i++)in[i].clear(),out[i].clear();
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;if(mp[{u,v}])continue;
      mp[{u,v}]=1;
      out[u].insert(v);in[v].insert(u);
    }
    set<pair<int,int> >st;
    for(int i=1;i<=n;i++)st.insert({in[i].size()+out[i].size(),i});
     int cnt=(4*n)/7;vector<int>ans;
    while(cnt--)
    {
      pair<int,int>p=*st.rbegin();st.erase(p);
      int nd=p.second;ans.push_back(nd);
       for(auto x:out[nd])
      {
        st.erase({in[x].size()+out[x].size(),x});
        in[x].erase(nd);
        st.insert({in[x].size()+out[x].size(),x});
      }
      for(auto x:in[nd])
      {
        st.erase({in[x].size()+out[x].size(),x});
        out[x].erase(nd);
        st.insert({in[x].size()+out[x].size(),x});
      }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";cout<<endl;
  }
  return 0;
}