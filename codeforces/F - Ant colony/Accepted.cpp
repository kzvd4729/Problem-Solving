/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/22/2018 18:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 29200 KB                             
*  problem: https://codeforces.com/contest/474/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],seg[5*N+2];
map<int,vector<int> >mp;
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]=aa[lo];return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=__gcd(seg[node*2],seg[node*2+1]);
}
int qry(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  int p1=qry(node*2,lo,md,lt,rt);
  int p2=qry(node*2+1,md+1,hi,lt,rt);
  return __gcd(p1,p2);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];mp[aa[i]].push_back(i);
  }
  build(1,1,n);int q;cin>>q;
  while(q--)
  {
    int lt,rt;cin>>lt>>rt;
    int gcd=qry(1,1,n,lt,rt);
    int fr=upper_bound(mp[gcd].begin(),mp[gcd].end(),rt)-lower_bound(mp[gcd].begin(),mp[gcd].end(),lt);
    cout<<rt-lt+1-fr<<"\n";
  }
  return 0;
}