/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2020 13:54                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/540/problem/E
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
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],bb[N+2];map<long,long>bit;
void upd(long x,long vl)
{
  for( ;x>0;x-=x&-x)bit[x]+=vl;
}
long get(long x)
{
  long ret=0;
  for( ;x<=N;x+=x&-x)ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;vector<pair<long,long> >v;vector<long>a;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i]>>bb[i];
    a.push_back(aa[i]),a.push_back(bb[i]);
    v.push_back({aa[i],1});
    v.push_back({bb[i],1});
  }
  sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end());
  for(long i=1;i<a.size();i++)
  {
    if(a[i]-a[i-1]-1>0)v.push_back({a[i]-1,a[i]-a[i-1]-1});
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  map<long,long>mp;
  for(long i=0;i<v.size();i++)mp[v[i].first]=i;
  for(long i=1;i<=n;i++)swap(v[mp[aa[i]]],v[mp[bb[i]]]);
  //for(auto x:v)cout<<x.first<<" ";cout<<endl;
  long ans=0;
  for(auto x:v)
  {
    //cout<<x.first<<" "<<x.second<<endl;
    ans+=1LL*get(x.first)*x.second;
    upd(x.first,x.second);
  }
  cout<<ans<<endl;
  return 0;
}