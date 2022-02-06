/****************************************************************************************
*  @author: kzvd4729#                                        created: May/30/2020 10:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/821/problem/A
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
const int N=1e3;
int mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)cin>>mt[i][j];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(mt[i][j]==1)continue;
      int f=0;
      for(int s=1;s<=n;s++)
      {
        for(int t=1;t<=n;t++)
        {
          if(mt[s][j]+mt[i][t]==mt[i][j])f=1;
        }
      }
      if(!f)cout<<"NO"<<endl,exit(0);
    }
  }
  cout<<"YES"<<endl;
  return 0;
}