/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/10/2020 23:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 670 ms                                          memory_used: 38200 KB                             
*  problem: https://codeforces.com/contest/757/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int fr[N+2],fac[N+2];
vector<pair<int,int> >pp[N+2];
map<vector<pair<int,int> >,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;vector<int>v(x);
    for(int j=0;j<x;j++)
    {
      cin>>v[j];fr[v[j]]++;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
     for(auto x:v)
    {
      pp[x].push_back({i,fr[x]});
      fr[x]=0;
    }
  }
  for(int i=1;i<=m;i++)
  {
    //if(pp[i].size()==0)continue;
    sort(pp[i].begin(),pp[i].end());
    mp[pp[i]]++;
  }
  fac[0]=1;
  for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
  int ans=1;
  for(auto x:mp)
  {
    //cout<<x.second<<endl;
    ans=(1LL*ans*fac[x.second])%mod;
  }
  cout<<ans<<endl;
  return 0;
}