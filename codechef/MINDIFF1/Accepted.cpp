/****************************************************************************************
*  @author: kzvd4729                                         created: 19-10-2021 13:27:57                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.61 sec                                        memory_used: 93.9M                                
*  problem: https://www.codechef.com/SNCKQL21/problems/MINDIFF1
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
set<int>ad[N+2];int nm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].insert(v);ad[v].insert(u);
    }
    set<pair<int,int> >st;
    for(int i=1;i<=n;i++)st.insert({ad[i].size(),i});
    int mx=0,now=n;
    while((int)st.size())
    {
      pair<int,int>p=*st.begin();st.erase(p);
      mx=max(mx,p.first);
      nm[p.second]=now--;
      for(auto x:ad[p.second])
      {
        st.erase({ad[x].size(),x});
        ad[x].erase(p.second);
        st.insert({ad[x].size(),x});
      }
    }
    cout<<mx<<endl;
    for(int i=1;i<=n;i++)cout<<nm[i]<<" ";cout<<endl;
  }
    return 0;
}