/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 17:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/558/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int fr[N+2],ans[N+2],aa[N+2];
int mp[N+2];vector<int>v;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=0;i<=N;i++)mp[i]=N;
  for(int i=1;i<=n;i++)
  {
    v.clear();
    int x=aa[i];int cnt=0;
    while(x)
    {
      mp[x]=cnt;v.push_back(x);
      int y=x;int cntt=cnt;
      while(y<=N/2)
      {
        y*=2;cntt++;
        if(mp[y]<N)
          mp[y]=min(mp[y],cntt);
        else mp[y]=cntt,v.push_back(y);
      }
      x/=2;cnt++;
    }
    mp[aa[i]]=0;
    for(auto x:v)
    {
      fr[x]++,ans[x]+=mp[x];
      mp[x]=N;
    }
  }
  int pr=1e9;
  for(int i=1;i<=N;i++)
    if(fr[i]==n)pr=min(pr,ans[i]);
  cout<<pr<<endl;
  return 0;
}