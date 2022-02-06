/****************************************************************************************
*  @author: * kzvd4729                                       created: May/07/2021 22:28                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 280 ms                                          memory_used: 37800 KB                             
*  problem: https://codeforces.com/contest/1521/problem/D
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
 vector<int>ad[N+2];
 vector<vector<int> >ans;
 vector<int>dfs(int nd,int pr)
{
  vector<vector<int> >bk;
  vector<vector<int> >st;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    vector<int>v=dfs(x,nd);
     if(v.back()==-1)st.push_back(v);
    else bk.push_back(v);
  }
   vector<int>ret={nd,nd,-1};
  if((int)st.size()>=2)
  {
    ret[1]=st[0][1];
    ret[2]=st[1][1];
     for(int i=2;i<(int)st.size();i++)
    {
      ans.push_back({nd,st[i][0],ret[1],st[i][0]});
      ret[1]=st[i][1];
    }
     for(int i=0;i<(int)bk.size();i++)
    {
      ans.push_back({nd,bk[i][0],ret[1],bk[i][2]});
      ret[1]=bk[i][1];
    }
  }
  else
  {
    if((int)st.size())ret[1]=st[0][1];
     for(int i=0;i<(int)bk.size();i++)
    {
      ans.push_back({nd,bk[i][0],ret[1],bk[i][2]});
      ret[1]=bk[i][1];
    }
  }
   return ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
     for(int i=1;i<=n;i++)ad[i].clear();ans.clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
     vector<int>v=dfs(1,-1);
     //for(auto x:v)cout<<x<<" ";cout<<endl;
     cout<<(int)ans.size()<<'\n';
    for(auto x:ans)
    {
      for(auto z:x)cout<<z<<" ";
        cout<<'\n';
    }
  }
  return 0;
}