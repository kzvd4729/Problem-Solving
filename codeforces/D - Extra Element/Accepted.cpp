/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2019 02:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/1185/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inv=2e9+2;
int aa[N+2],suf[N+2],pre[N+2];
pair<int,int>pp[N+2];
int cal(int n)
{
  if(suf[2]!=-1)return 1;
  if(pre[n-1]!=-1)return n;
  for(int i=2;i<n;i++)
  {
    int one=pre[i-1],two=suf[i+1],thr=aa[i+1]-aa[i-1];
    if(i==2)one=inv;if(i==n-1)two=inv;
    if(one==-1||two==-1)continue;
    if(one==inv&&two==inv)return i;
    if(one==inv)
    {
      if(two==thr)return i;
    }
    else if(two==inv)
    {
      if(one==thr)return i;
    }
    else
    {
      if(one==two&&one==thr)return i;
    }
  }
  return -1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>pp[i].first;pp[i].second=i;
  }
  sort(pp+1,pp+n+1);
  for(int i=1;i<=n;i++)aa[i]=pp[i].first;
  suf[n-1]=aa[n]-aa[n-1];
  for(int i=n-2;i>=1;i--)
  {
    if(suf[i+1]==-1)suf[i]=-1;
    else if(aa[i+1]-aa[i]!=suf[i+1])suf[i]=-1;
    else suf[i]=suf[i+1];
  }
  pre[2]=aa[2]-aa[1];
  for(int i=3;i<=n;i++)
  {
    if(pre[i-1]==-1)pre[i]=-1;
    else if(aa[i]-aa[i-1]!=pre[i-1])pre[i]=-1;
    else pre[i]=pre[i-1];
  }
  int id=cal(n);if(id==-1)cout<<-1<<endl,exit(0);
  cout<<pp[id].second<<endl;
  return 0;
}