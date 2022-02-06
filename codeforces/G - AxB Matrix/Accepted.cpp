/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2020 19:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/1360/problem/G
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
const int N=50;
string s[N+2];
void solve()
{
  int n,m,a,b;cin>>n>>m>>a>>b;
  if(n*a!=m*b){cout<<"NO"<<endl;return ;}
  cout<<"YES"<<endl;
   for(int i=0;i<n;i++)
  {
    s[i].clear();
    for(int j=0;j<m;j++)s[i].push_back('0');
  }
  int pt=0;
  for(int i=0;i<n;i++)
  {
    for(int j=1;j<=a;j++)
    {
      s[i][pt]='1';pt=(pt+1)%m;
    }
  }
  for(int i=0;i<n;i++)cout<<s[i]<<endl;
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