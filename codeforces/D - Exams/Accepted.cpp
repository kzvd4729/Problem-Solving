/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2018 21:29                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 77 ms                                           memory_used: 7700 KB                              
*  problem: https://codeforces.com/contest/732/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e9;
int arr[N+2],tim[N+2],n,m,ans,cnt,lo,hi,md;
bool check(int hr)
{
  int po[N+2];
  memset(po,0,sizeof(po));
  set<pair<int,int> >st;
  set<pair<int,int> >::iterator it;
  for(int i=1;i<=hr;i++)po[arr[i]]=i;
  for(int i=1;i<=m;i++)if(po[i]==0)return false;
  for(int i=1;i<=m;i++)st.insert({po[i],i});
  cnt=0;
  for(it=st.begin();it!=st.end();it++)
  {
    if(tim[it->second]+cnt>=it->first)return false;
    cnt+=tim[it->second]+1;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<=m;i++)cin>>tim[i];
  lo=1;
  hi=n;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(check(md))hi=md;
    else lo=md;
  }
  for(int i=lo;i<=hi;i++)
  {
    if(check(i))
    {
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}