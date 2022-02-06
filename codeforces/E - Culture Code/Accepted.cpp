/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2019 11:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1197/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
const int mod=1e9+7;
int mnm[N+2],way[N+2];
int bit[N+2],sum[N+2];
void upd(int id,int mn,int sm)
{
  for( ;id<=N;id+=id&-id)
  {
    if(mn<bit[id])
      bit[id]=mn,sum[id]=sm;
    else if(bit[id]==mn)
    {
      sum[id]=(sum[id]+sm);
      if(sum[id]>=mod)sum[id]-=mod;
    }
  }
}
pair<int,int>get(int id)
{
  int mn=mod+mod,sm=0;
  for( ;id>0;id-=id&-id)
  {
    if(bit[id]<mn)mn=bit[id],sm=sum[id];
    else if(bit[id]==mn)
    {
      sm=(sm+sum[id]);
      if(sm>=mod)sm-=mod;
    }
  }
  return {mn,sm};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<pair<int,int> >pp(n);
  for(int i=0;i<n;i++)
    cin>>pp[i].first>>pp[i].second;
  sort(pp.begin(),pp.end());
  for(int i=0;i<=N;i++)bit[i]=mod+mod;
  for(int i=0;i<pp.size();i++)
  {
    int id=upper_bound(pp.begin(),pp.end(),make_pair(pp[i].second+1,-1))-pp.begin();
    id--;
    if(id<0)
      mnm[i]=pp[i].second,way[i]=1;
    else
    {
      pair<int,int>p=get(id+1);
      mnm[i]=p.first+pp[i].second;
      way[i]=p.second;
    }
    upd(i+1,mnm[i]-pp[i].first,way[i]);
  }
  int pt=0;int mn=mod+mod;
  for(int i=n-1;i>=pt;i--)
  {
    mn=min(mn,mnm[i]);
    int id=upper_bound(pp.begin(),pp.end(),make_pair(pp[i].second+1,-1))-pp.begin();
    pt=max(pt,id);
  }
  int sm=0;
  for(int i=n-1;i>=pt;i--)
  {
    if(mnm[i]==mn)
    {
      sm=(sm+way[i]);
      if(sm>=mod)sm-=mod;
    }
  }
  cout<<sm<<endl;
  return 0;
}