/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/03/2019 16:40                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 546 ms                                          memory_used: 13400 KB                             
*  problem: https://codeforces.com/contest/367/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],bb[N+2],ds;
map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,p;cin>>n>>m>>p;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=m;i++)
  {
    cin>>bb[i];mp[bb[i]]++;
    if(mp[bb[i]]==1)ds++;
  }
  vector<int>ans;
  for(int i=1;i<=p;i++)
  {
    int un=ds;map<int,int>pm;
    for(int j=i;j<=n;j+=p)
    {
      if(pm[aa[j]]==mp[aa[j]])un++;
      if(pm[aa[j]]+1==mp[aa[j]])un--;
      pm[aa[j]]++;
       if(((j-i)/p+1)>m)
      {
        int ls=j-p*m;
        if(pm[aa[ls]]==mp[aa[ls]])un++;
        if(pm[aa[ls]]-1==mp[aa[ls]])un--;
        pm[aa[ls]]--;
      }
      if(un==0)ans.push_back(j-p*(m-1));
    }
  }
  cout<<ans.size()<<endl;
  sort(ans.begin(),ans.end());
  for(auto x:ans)cout<<x<<" ";
  cout<<endl;
  return 0;
}