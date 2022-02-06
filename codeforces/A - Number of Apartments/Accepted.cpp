/****************************************************************************************
*  @author: kzvd4729#                                        created: Mar/24/2021 19:41                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1430/problem/A
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
const int N=1000,inf=1e9,mod=998244353;
 int a[N+2],b[N+2],c[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   memset(a,-1,sizeof a);
  for(int i=0;i<=1000;i++)
  {
    if(i*3>1000)break;
    for(int j=0;j<=1000;j++)
    {
      if(i*3+j*5>1000)break;
      for(int k=0;k<=1000;k++)
      {
        int id=i*3+j*5+k*7;
        if(id>1000)break;
        a[id]=i,b[id]=j,c[id]=k;
      }
    }
  }
  int t;cin>>t;
  while(t--)
  {
    int x;cin>>x;
    if(a[x]==-1)cout<<-1<<endl;
    else cout<<a[x]<<" "<<b[x]<<" "<<c[x]<<endl;
  }
    return 0;
}