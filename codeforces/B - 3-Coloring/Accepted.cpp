/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2021 21:05                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 202 ms                                          memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1503/problem/B
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
  int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
   vector<pair<int,int> >v[2];
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      v[(i+j)%2].push_back({i,j});
    }
  }
  for(int i=1;i<=n*n;i++)
  {
    int x;cin>>x;
     if((int)v[0].size()==0)
    {
      pair<int,int>p=v[1].back();v[1].pop_back();
      if(x!=2)cout<<2<<" "<<p.first<<" "<<p.second<<endl;
      else cout<<3<<" "<<p.first<<" "<<p.second<<endl;
    }
    else if((int)v[1].size()==0)
    {
      pair<int,int>p=v[0].back();v[0].pop_back();
      if(x!=1)cout<<1<<" "<<p.first<<" "<<p.second<<endl;
      else cout<<3<<" "<<p.first<<" "<<p.second<<endl;
    }
    else
    {
      if(x!=1)
      {
        pair<int,int>p=v[0].back();v[0].pop_back();
        cout<<1<<" "<<p.first<<" "<<p.second<<endl;
      }
      else
      {
        pair<int,int>p=v[1].back();v[1].pop_back();
        cout<<2<<" "<<p.first<<" "<<p.second<<endl;
      }
    }
  }
  return 0;
}