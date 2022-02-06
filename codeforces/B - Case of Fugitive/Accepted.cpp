/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/10/2018 23:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 405 ms                                          memory_used: 17500 KB                             
*  problem: https://codeforces.com/contest/555/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,m,l[N+2],r[N+2],ans[N+2];
pair<long,pair<long,long> >p[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(long i=1;i<=n;i++)
    cin>>l[i]>>r[i];
  for(long i=1;i<n;i++)
  {
    p[i].first=r[i+1]-l[i];
    p[i].second.first=l[i+1]-r[i];
    p[i].second.second=i;
  }
  sort(p+1,p+n);set<pair<long,long> >st;
  for(long i=1;i<=m;i++)
  {
    long x;cin>>x;
    st.insert({x,i});
  }
  for(long i=1;i<n;i++)
  {
    set<pair<long,long> >::iterator it;
    it=st.lower_bound({p[i].second.first,0});
    if(it==st.end()||it->first>p[i].first)
      cout<<"No"<<endl,exit(0);
    ans[p[i].second.second]=it->second;
    st.erase(*it);
  }
  cout<<"Yes"<<endl;
  for(long i=1;i<n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}