/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/31/2021 21:12                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 795 ms                                          memory_used: 67700 KB                             
*  problem: https://codeforces.com/contest/1555/problem/E
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
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
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  vector<vector<int> >v(n,vector<int>(3));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<3;j++)cin>>v[i][j];
    v[i][1]--;
  }
    sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
    return a[2]<b[2];
  });
    int ans=inf,p=0;
  for(int i=0;i<n;i++)
  {
    upd(1,1,m-1,v[i][0],v[i][1],+1);
     if(sm[1]<m-1)continue;
     while(true)
    {
      upd(1,1,m-1,v[p][0],v[p][1],-1);
      if(sm[1]<m-1)
      {
        upd(1,1,m-1,v[p][0],v[p][1],+1);
        break;
      }
      else p++;
    }
    ans=min(ans,v[i][2]-v[p][2]);
  }
   cout<<ans<<endl;
    return 0;
}