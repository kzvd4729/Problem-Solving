/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2020 10:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 6300 KB                              
*  problem: https://codeforces.com/contest/557/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int xx[N+2],yy[N+2];
vector<int>v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;multiset<int>st;int tt=0;
  for(int i=1;i<=n;i++)cin>>xx[i];
  for(int i=1;i<=n;i++)
  {
    cin>>yy[i];
    v[xx[i]].push_back(yy[i]);st.insert(yy[i]);
    tt+=yy[i];
  }
  int ans=2e9;
  for(int i=N;i>=1;i--)
  {
    if(v[i].size()==0)continue;
     int now=0;
    for(auto x:v[i])st.erase(st.find(x)),now+=x;
    vector<int>buf;
    for(int j=1;j<v[i].size();j++)
    {
      if(st.size()==0)break;
      int ls=*st.rbegin();now+=ls;
      buf.push_back(ls);st.erase(st.find(ls));
    }
    ans=min(ans,tt-now);
    for(auto x:buf)st.insert(x);
  }
  cout<<ans<<endl;
  return 0;
}