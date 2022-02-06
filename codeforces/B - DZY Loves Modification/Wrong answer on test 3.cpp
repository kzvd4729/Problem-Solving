/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/05/2020 16:36                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7900 KB                              
*  problem: https://codeforces.com/contest/446/problem/B
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
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e3;
long aa[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,k,p;cin>>n>>m>>k>>p;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)cin>>aa[i][j];
  }
  priority_queue<long>row,col;
  for(int i=1;i<=n;i++)
  {
    long sm=0;
    for(int j=1;j<=m;j++)
      sm+=aa[i][j];
    row.push(sm);
  }
  for(int j=1;j<=m;j++)
  {
    long sm=0;
    for(int i=1;i<=n;i++)
      sm+=aa[i][j];
    col.push(sm);
  }
  long ans=0,cr=0,cl=0;
  for(int i=1;i<=k;i++)
  {
    if(row.top()-p*cl>col.top()-p*cr)
    {
      long tp=row.top();row.pop();
      ans+=tp-p*cl;row.push(tp-p*n);
      cr++;
    }
    else
    {
      long tp=col.top();col.pop();
      ans+=tp-p*cr;col.push(tp-p*m);
      cl++;
    }
  }
  cout<<ans<<endl;
  return 0;
}