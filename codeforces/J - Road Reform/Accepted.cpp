/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/25/2020 21:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 17600 KB                             
*  problem: https://codeforces.com/contest/1468/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],par[N+2];
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;long ans=0;
    vector<vector<int> >fr,cs;
    for(int i=0;i<m;i++)
    {
      int a,b,c;cin>>a>>b>>c;
      if(c<=k)fr.push_back({c,a,b});
      else cs.push_back({c,a,b});
    }
    for(int i=1;i<=n;i++)par[i]=i;
     sort(fr.begin(),fr.end());reverse(fr.begin(),fr.end());
    sort(cs.begin(),cs.end());
    int mx=-inf,cnt=0;
    for(auto x:fr)
    {
      int p1=get(x[1]),p2=get(x[2]);
      if(p1==p2)continue;par[p1]=p2,cnt++;
      mx=max(mx,x[0]);
    }
    if(cnt==n-1)
    {
      if((int)cs.size())cout<<min(k-mx,cs[0][0]-k)<<endl;
      else cout<<k-mx<<endl;
      continue;
    }
    for(auto x:cs)
    {
      int p1=get(x[1]),p2=get(x[2]);
      if(p1==p2)continue;par[p1]=p2,cnt++;
      ans+=x[0]-k;if(cnt==n-1)break;
    }
    cout<<ans<<endl;
  }
  return 0;
}