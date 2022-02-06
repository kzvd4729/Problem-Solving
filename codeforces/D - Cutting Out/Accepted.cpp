/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/16/2018 21:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 4400 KB                              
*  problem: https://codeforces.com/contest/1077/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int fr[N+2],n,k;vector<int>ans;
priority_queue<pair<int,int> >pq;
bool ck(int x)
{
  priority_queue<pair<int,int> >tmp=pq;
  ans.clear();
  for(int i=1;i<=k;i++)
  {
    pair<int,int>p=tmp.top();tmp.pop();
    if(p.first<x)return false;
    p.first-=x;tmp.push(p);
    ans.push_back(p.second);
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;fr[x]++;
  }
  for(int i=1;i<=N;i++)
  {
    if(fr[i])
    {
      pq.push({fr[i],i});
    }
  }
  int lo=0,hi=N,md;
  while(hi-lo>3)
  {
    md=(lo+hi)/2;
    if(ck(md))lo=md;
    else hi=md;
  }
  for(md=hi;md>=lo;md--)
  {
    if(ck(md))break;
  }
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}