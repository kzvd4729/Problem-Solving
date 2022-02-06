/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2020 16:08                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 47100 KB                             
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
    int n,m;cin>>n>>m;map<pair<int,int>,int>mp;vector<pair<int,int> >ed;
    for(int i=1;i<=n;i++)in[i].clear(),out[i].clear();
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;if(mp[{u,v}])continue;
      mp[{u,v}]=1;
      out[u].insert(v);in[v].insert(u);
      ed.push_back({u,v});
    }
    int cnt=(4*n)/7;vector<int>ans;
    if(n<=5)
    {
      for(int msk=0;msk<(1<<n);msk++)
      {
        if(__builtin_popcount(msk)>cnt)continue;
        int f=0;
        for(int i=0;i<ed.size();i++)
        {
          for(int j=0;j<ed.size();j++)
          {
            if(ed[i].second!=ed[j].first)continue;
            if(msk&(1<<(ed[i].first-1)))continue;
            if(msk&(1<<(ed[i].second-1)))continue;
            if(msk&(1<<(ed[j].second-1)))continue;
            f=1;
          }
        }
        if(f==0)
        {
          cout<<__builtin_popcount(msk)<<"\n";
          for(int i=0;i<n;i++)
            if(msk&(1<<i))cout<<i+1<<" ";
          cout<<"\n";break;
        }
      }
    }
    set<vector<int> >st;
    for(int i=1;i<=n;i++)st.insert({in[i].size()+out[i].size(),(in[i].size()>0)&&(out[i].size()>0),i});
     while(cnt--)
    {
      vector<int>p=*st.rbegin();st.erase(p);
      int nd=p[2];ans.push_back(nd);
       for(auto x:out[nd])
      {
        st.erase({in[x].size()+out[x].size(),(in[x].size()>0)&&(out[x].size()>0),x});
        in[x].erase(nd);
        st.insert({in[x].size()+out[x].size(),(in[x].size()>0)&&(out[x].size()>0),x});
      }
      for(auto x:in[nd])
      {
        st.erase({in[x].size()+out[x].size(),(in[x].size()>0)&&(out[x].size()>0),x});
        out[x].erase(nd);
        st.insert({in[x].size()+out[x].size(),(in[x].size()>0)&&(out[x].size()>0),x});
      }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";cout<<endl;
  }
  return 0;
}