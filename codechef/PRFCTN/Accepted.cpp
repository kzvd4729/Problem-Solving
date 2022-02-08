/****************************************************************************************
*  @author: kzvd4729                                         created: 30-11-2019 19:59:18                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.32 sec                                        memory_used: 55.7M                                
*  problem: https://www.codechef.com/LTIME78A/problems/PRFCTN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bit[N+2];
vector<int>po[N+2];
void upd(int id,int n)
{
  for( ;id<=n;id+=id&-id)
    bit[id]++;
}
int get(int id)
{
  int ret=0;
  for( ;id>0;id-=id&-id)
    ret+=bit[id];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<int>v;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];v.push_back(aa[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    map<int,int>mp;
    for(int i=0;i<v.size();i++)
      mp[v[i]]=i+1;
    for(int i=1;i<=n;i++)aa[i]=mp[aa[i]];
    for(int i=1;i<=n;i++)po[i].clear();
    for(int i=1;i<=n;i++)po[aa[i]].push_back(i);
    for(int i=1;i<=n;i++)bit[i]=0;
    int ans=0;
    for(int i=n;i>1;i--)
    {
      if(po[i].size()==0)continue;
      v.clear();
      for(auto x:po[i])
        v.push_back(x-get(x));
      ans++;
      for(int j=1;j<v.size();j++)
        if(v[j]!=v[j-1]+1)ans++;
      for(auto x:po[i])
        upd(x,n);
    }
    cout<<ans<<"\n";
  }
  return 0;
}