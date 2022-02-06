/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2020 14:13                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 639 ms                                          memory_used: 75600 KB                             
*  problem: https://codeforces.com/contest/1418/problem/G
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long 
using namespace std;
const int N=1e6;
int cnt[4*N+8],sm[4*N+8],dsm[4*N+8];
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lo>rt||hi<lt)return;
  if(lo>=lt&&hi<=rt)
  {
    cnt[node]+=vl;
    if(cnt[node])sm[node]=hi-lo+1;else sm[node]=dsm[node];
    return;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl),upd(node*2+1,md+1,hi,lt,rt,vl);
  dsm[node]=sm[node*2]+sm[node*2+1];
  if(cnt[node])sm[node]=hi-lo+1;else sm[node]=dsm[node];
}
int a[N+2];
vector<int>po[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)po[i].push_back(n+1);
  long ans=0;
  for(int i=n;i>=1;i--)
  {
    int sz=po[a[i]].size();
    upd(1,1,n,i,po[a[i]][sz-1]-1,1);
    if(sz-3>=0)upd(1,1,n,po[a[i]][sz-2],po[a[i]][sz-3]-1,-1);
    if(sz-4>=0)upd(1,1,n,po[a[i]][sz-3],po[a[i]][sz-4]-1,1);
     ans+=n-i+1-sm[1];po[a[i]].push_back(i);
  }
  cout<<ans<<endl;
  return 0;
}