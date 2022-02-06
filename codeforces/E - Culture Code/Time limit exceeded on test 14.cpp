/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2019 11:13                        
*  solution_verdict: Time limit exceeded on test 14          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 32900 KB                             
*  problem: https://codeforces.com/contest/1197/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long C=1e9,mod=1e9+7;
long mnm[N+2],way[N+2];
long bit[N+2],sum[N+2];
void upd(int id,long mn,long sm)
{
  //cout<<id<<" "<<mn<<" "<<sm<<endl;
  for( ;id<=N;id+=id&-id)
  {
    if(mn<bit[id])
      bit[id]=mn,sum[id]=sm;
    else if(bit[id]==mn)
      sum[id]=(sum[id]+sm)%mod;
  }
}
pair<long,long>get(int id)
{
  long mn=LLONG_MAX,sm=0;
  for( ;id>0;id-=id&-id)
  {
    //cout<<"*"<<sum[id]<<" ";
    if(bit[id]<mn)mn=bit[id],sm=sum[id];
    else if(bit[id]==mn)sm=(sm+sum[id])%mod;
  }
  //cout<<"*"<<sm<<endl;
  //cout<<endl;
  return {mn,sm};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<pair<int,int> >pp(n);
  for(int i=0;i<n;i++)
    cin>>pp[i].first>>pp[i].second;
  sort(pp.begin(),pp.end());
  for(auto x:pp)
    //cout<<x.first<<" "<<x.second<<endl;
  //cout<<endl;
  for(int i=0;i<=N;i++)bit[i]=mod+mod;
  for(int i=0;i<pp.size();i++)
  {
    int id=upper_bound(pp.begin(),pp.end(),make_pair(pp[i].second+1,-1))-pp.begin();
    id--;
    //cout<<id<<endl;
     if(id<0)
    {
      mnm[i]=pp[i].second,way[i]=1;
    }
    else
    {
      pair<long,long>p=get(id+1);
      mnm[i]=p.first+pp[i].second;
      way[i]=p.second;
    }
    /*long mn=LLONG_MAX;
    for(int j=0;j<=id;j++)
      mn=min(mn,mnm[j]+pp[i].second-pp[j].first);//bit
    long sm=0;
    for(int j=0;j<=id;j++)
      if(mn==mnm[j]+pp[i].second-pp[j].first)
        sm=(sm+way[j])%mod;
    mnm[i]=mn;way[i]=sm;*/
      upd(i+1,mnm[i]-pp[i].first,way[i]);
    //cout<<i<<" --> "<<mnm[i]-pp[i].first<<" "<<way[i]<<endl;
  }
  int pt=0;long mn=LLONG_MAX;
  for(int i=n-1;i>=pt;i--)
  {
    mn=min(mn,mnm[i]);
    int id=upper_bound(pp.begin(),pp.end(),make_pair(pp[i].second+1,-1))-pp.begin();
    pt=max(pt,id);
  }
  long sm=0;
  for(int i=n-1;i>=pt;i--)
    if(mnm[i]==mn)sm=(sm+way[i])%mod;
  //cout<<mn<<" "<<sm<<endl;
  cout<<sm<<endl;
  return 0;
}