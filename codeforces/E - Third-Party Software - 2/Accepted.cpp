/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/11/2019 17:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 10100 KB                             
*  problem: https://codeforces.com/gym/102215/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
void no(void)
{
  cout<<"NO\n",exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
   map<int,pair<int,int> >mp;
  for(int i=1;i<=n;i++)
  {
    int u,v;cin>>u>>v;
    if(v>mp[u].first)mp[u]={v,i};
  }
  auto it=mp.begin(),pr=mp.begin();
  it++;
  while(it!=mp.end())
  {
    if(pr->second.first>it->second.first)
      mp[it->first]=mp[pr->first];
    it++,pr++;
  }
  int pt=1;vector<int>ans;
  while(pt<=m)
  {
    auto it=mp.upper_bound(pt);if(it==mp.begin())no();
    it--;
     if(it->second.first<pt)no();
     ans.push_back(it->second.second);pt=it->second.first+1;
  }
  if(pt<=m)no();
  cout<<"YES\n";cout<<ans.size()<<"\n";
  for(auto x:ans)cout<<x<<" ";
  cout<<"\n";
  return 0;
}