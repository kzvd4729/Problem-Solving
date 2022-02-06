/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/13/2019 20:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 32500 KB                             
*  problem: https://codeforces.com/contest/1148/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],po[N+2],n;
vector<pair<int,int> >v;
void _make(int i,int j)
{
  if(i==j)return ;
  if(abs(i-j)*2<n)assert(0);
  v.push_back({i,j});swap(aa[i],aa[j]);
  po[aa[i]]=i,po[aa[j]]=j;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i],po[aa[i]]=i;
  for(int i=1;i<=n/2;i++)
  {
    if(po[i]<=n/2)
    {
      _make(po[i],n);_make(i,n);
    }
    else
    {
      _make(1,po[i]);_make(1,n);
      _make(i,n);_make(1,po[1]);
    }
  }
  for(int i=n/2+1;i<=n;i++)
  {
    _make(1,po[i]);_make(1,i);
    _make(1,po[1]);
  }
  cout<<v.size()<<"\n";
  for(auto x:v)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}