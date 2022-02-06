/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/25/2019 19:07                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 9500 KB                              
*  problem: https://codeforces.com/contest/1251/problem/E2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
pair<int,int>seg[5*N+2],pp[N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi){seg[node]={pp[lo].second,lo};return ;}
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi){seg[node].first=vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
pair<int,int>get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {2e9,0};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  pair<int,int>p1=get(node*2,lo,md,lt,rt);
  pair<int,int>p2=get(node*2+1,md+1,hi,lt,rt);
  return min(p1,p2);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>pp[i].first>>pp[i].second;
    sort(pp+1,pp+n+1);build(1,1,n);
     vector<int>buf;priority_queue<int>pq;
    for(int i=1;i<=n;i++)pq.push(0);
    int cnt=0;long ans=0;
    for(int i=1;i<=n;i++)
    {
      int f=1;
      while(cnt<pp[i].first)
      {
        pair<int,int>p=get(1,1,n,i,n);
        buf.push_back(p.first);upd(1,1,n,p.second,2e9);
        int tp=pq.top();pq.pop();
        ans+=p.first-tp;cnt++;f=0;
      }
      cnt+=f;
      for(auto x:buf)pq.push(x);buf.clear();
    }
    cout<<ans<<"\n";
  }
  return 0;
}