/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/22/2020 19:40                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 857 ms                                          memory_used: 275600 KB                            
*  problem: https://codeforces.com/contest/932/problem/D
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
const int N=4e5;
const long inf=1e18;
pair<long,long>sp[N+2][20+2],dp[N+2][20+2];
void add(int nd,int p,int q)
{
  sp[nd][0]={p,q};
  for(int i=1;i<20;i++)
  {
    sp[nd][i]=sp[nd][i-1];
    if(sp[nd][i-1].first!=-1)
    {
      sp[nd][i]=sp[sp[nd][i-1].first][i-1];
      sp[nd][i].second=max(sp[nd][i].second,sp[nd][i-1].second);
    }
  }
  int u=sp[nd][0].first;
  for(int i=20-1;i>=0;i--)
  {
    if(sp[u][i].second<q)u=sp[u][i].first;
  }
  //cout<<nd<<" ** "<<u<<endl;
  dp[nd][0]={u,q};
  for(int i=1;i<20;i++)
  {
    dp[nd][i]=dp[nd][i-1];
    if(dp[nd][i-1].first!=-1)
    {
      dp[nd][i]=dp[dp[nd][i-1].first][i-1];
      dp[nd][i].second+=dp[nd][i-1].second;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;int last=0,nd=1;
  for(int i=0;i<20;i++)sp[0][i]={-1,inf},dp[0][i]={-1,inf};
  add(1,0,0);
  while(n--)
  {
    long ty,p,q;cin>>ty>>p>>q;p^=last;q^=last;
     if(ty==1)add(++nd,p,q);
    else
    {
      last=0;
      for(int i=20-1;i>=0;i--)
      {
        if(dp[p][i].second>q)continue;
        last+=(1<<i);q-=dp[p][i].second;p=dp[p][i].first;
      }
      cout<<last<<'\n';
    }
  }
  return 0;
}