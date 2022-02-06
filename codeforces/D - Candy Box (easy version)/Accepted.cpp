/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2019 20:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 10100 KB                             
*  problem: https://codeforces.com/contest/1183/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>q;
  while(q--)
  {
    int n;cin>>n;vector<int>fr(n,0),cnt(n,0);
    for(int i=0;i<n;i++)
    {
      int x,y;cin>>x;x--;y=1;
      fr[x]++;cnt[x]+=y;
    }
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++)
      if(fr[i])v.push_back({cnt[i],fr[i]});
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());set<int>st;
    for(int i=0;i<=n;i++)st.insert(i);
    int a=0,b=0;
    for(auto x:v)
    {
      auto it=st.upper_bound(x.second);it--;
      int vl=*it;if(vl==0)continue;
      a+=vl;b+=min(vl,x.first);
      st.erase(vl);
    }
    cout<<a<<"\n";
  }
  return 0;
}