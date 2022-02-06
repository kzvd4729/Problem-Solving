/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 19:01                        
*  solution_verdict: Wrong answer on test 31                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4600 KB                              
*  problem: https://codeforces.com/contest/747/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,cnt=0;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<=n;i++)
  {
    if(aa[i]<0)cnt++;
  }
  k-=cnt;if(k<0)cout<<-1<<endl,exit(0);
   aa[n+1]=-1;int id;
  for(int i=n+1;i>=1;i--)
    if(aa[i]<0)id=i;
  if(id>n)cout<<0<<endl,exit(0);
   cnt=0;vector<vector<int> >v;
  for(int i=id;i<=n+1;i++)
  {
    if(aa[i]>=0)cnt++;
    else
    {
      if(cnt)v.push_back({cnt,i-cnt,i-1});
      cnt=0;
    }
  }
  sort(v.begin(),v.end());
  for(auto x:v)
  {
    if(x[0]>k)break;
    k-=x[0];
     for(int i=x[1];i<=x[2];i++)aa[i]=-1;
  }
  int ans=0,f=0;aa[0]=1;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]<0)aa[i]=-1;
    else aa[i]=1;
    ans+=(aa[i]!=aa[i-1]);
  }
  cout<<ans<<endl;
  return 0;
}