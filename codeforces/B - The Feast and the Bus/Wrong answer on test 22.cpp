/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/27/2019 18:13                        
*  solution_verdict: Wrong answer on test 22                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1250/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int cnt[N+2],k;
int ck(int md)
{
  multiset<int>st;
  for(int i=1;i<=k;i++)st.insert(cnt[i]);
  int ret=0;
  while(true)
  {
    int lr=*st.rbegin();st.erase(st.find(lr));ret++;
    if(st.size()==0)return ret;
    auto it=st.upper_bound(md-lr);
    if(it==st.begin())continue;
    it--;st.erase(st.find(*it));
    if(st.size()==0)return ret;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>k;int lo=0,hi=n,md1,md2;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;cnt[x]++;
    lo=max(lo,cnt[x]);
  }
  while(hi-lo>2)
  {
    md1=(lo+lo+hi)/3;
    md2=(lo+hi+hi)/3;
    //cout<<md1<<" "<<md2<<endl;
    if(1LL*md1*ck(md1)<=1LL*md2*ck(md2))hi=md2;
    else lo=md2;
  }
  long ans=1e18;
  for(int md=lo;md<=hi;md++)
    ans=min(ans,1LL*md*ck(md));
  cout<<ans<<endl;
  return 0;
}