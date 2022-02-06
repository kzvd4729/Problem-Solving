/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2020 17:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 19300 KB                             
*  problem: https://codeforces.com/contest/1198/problem/B
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
#define long long long
using namespace std;
const int N=1e6,inf=1e9+2;
int aa[N+2],bb[N+2];
pair<int,int>p[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int ty;cin>>ty;
    if(ty==2)cin>>bb[i];
    else 
    {
      int x,y;cin>>x>>y;
      p[x]={i,y};
    }
  }
  for(int i=q-1;i>=1;i--)bb[i]=max(bb[i],bb[i+1]);
  for(int i=1;i<=n;i++)
  {
    if(p[i].first!=0)
    {
      aa[i]=p[i].second;
      aa[i]=max(aa[i],bb[p[i].first]);
    }
    else aa[i]=max(aa[i],bb[1]);
    cout<<aa[i]<<" ";
  }
  cout<<endl;
  return 0;
}