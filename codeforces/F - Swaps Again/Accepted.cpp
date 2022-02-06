/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/15/2020 11:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1365/problem/F
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
const int N=500;
int a[N+2],b[N+2],vs[N+2];
void solve()
{
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i];
   if(n%2&&a[n/2+1]!=b[n/2+1]){cout<<"no\n";return;}
   memset(vs,0,sizeof vs);
  for(int i=1;i<=n/2;i++)
  {
    int f=0;
    for(int j=1;j<=n/2;j++)
    {
      if(vs[j])continue;
      if((b[i]==a[j]&&b[n-i+1]==a[n-j+1])||(b[i]==a[n-j+1]&&b[n-i+1]==a[j]))
      {
        vs[j]=1;f=1;break;
      }
    }
    if(!f){cout<<"no\n";return;}
  }
  cout<<"yes\n";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}