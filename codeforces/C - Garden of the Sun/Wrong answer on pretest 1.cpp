/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/10/2021 19:57                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 31300 KB                             
*  problem: https://codeforces.com/contest/1495/problem/C
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
 string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
     for(int i=0;i<n;i++)
    {
      if(i%2==0)
      {
        for(int j=0;j<m;j++)s[i][j]='X';
      }
      else
      {
        int f=0;
        for(int j=0;j<m;j++)if(s[i][j]=='X')f=1;
        if(f==0)s[i][0]='X';
      }
      cout<<s[i]<<'\n';
    }
  }
   return 0;
}