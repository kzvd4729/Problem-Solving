/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/23/2021 20:57                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 62 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1517/problem/B
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
const int N=1e2,inf=1e9,mod=1e9+7;
 int a[N+2][N+2];
vector<int>v[N+2];
deque<int>d[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
     for(int i=1;i<=n;i++)v[i].clear(),d[i].clear();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        int x;cin>>x;
        v[i].push_back(x);
      }
    }
     for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
    for(int i=1;i<=n;i++)for(auto x:v[i])d[i].push_back(x);
     for(int j=1;j<=m;j++)
    {
      int mn=inf+1,id;
      for(int i=1;i<=n;i++)
      {
        if(d[i].front()<mn)mn=d[i].front(),id=i;
      }
       for(int i=1;i<=n;i++)
      {
        if(i==id)
        {
          a[i][j]=d[i].front();d[i].pop_front();
        }
        else
        {
          a[i][j]=d[i].back();d[i].pop_back();
        }
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cout<<a[i][j]<<" ";
        cout<<endl;
    }
  }
  return 0;
} 