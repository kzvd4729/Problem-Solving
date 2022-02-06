/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 12:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 12000 KB                             
*  problem: https://codeforces.com/contest/884/problem/F
****************************************************************************************/
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
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
pair<int,int>cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;int ans=0;
  for(int i=0;i<n;i++)cin>>aa[i],ans+=aa[i];
   for(int i=0;i<26;i++)cnt[i].second=i;int mn=0;
  for(int i=0;i<n/2;i++)
  {
    if(s[i]==s[n-1-i])cnt[s[i]-'a'].first++,mn+=min(aa[i],aa[n-1-i]);
  }
  sort(cnt,cnt+26);int tt=0;
  for(int i=0;i<25;i++)tt+=cnt[i].first;
   ans-=mn;priority_queue<int>pq;
  //cout<<ans<<endl;
  if(cnt[25].first>tt)
  {
    char c=cnt[25].second+'a';
    for(int i=0;i<n/2;i++)
    {
      if(s[i]==s[n-1-i])continue;
      if(s[i]==c||s[n-1-i]==c)continue;
      pq.push(-min(aa[i],aa[n-1-i]));
    }
    int df=cnt[25].first-tt;
    assert(pq.size()>=df);
    while(df)
    {
      int tp=pq.top();pq.pop();
      ans+=tp;df--;
    }
  }
  cout<<ans<<endl;
  return 0;
} 