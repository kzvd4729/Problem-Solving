/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2020 21:12                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1416/problem/A
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
const int N=1e6;
vector<int>po[N+2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      po[i].clear();po[i].push_back(0);
    }
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      po[x].push_back(i);
    }
    for(int i=1;i<=n;i++)po[i].push_back(n+1);
    int mn=n+1,id=-1;
    for(int i=1;i<=n;i++)
    {
      int mx=0;
      for(int j=0;j<po[i].size()-1;j++)
      {
        mx=max(mx,po[i][j+1]-po[i][j]);
      }
      if(mx<mn)mn=mx,id=i;
    }
    for(int i=1;i<=n;i++)
    {
      if(i<mn)cout<<-1<<" ";
      else cout<<id<<" ";
    }
    cout<<'\n';
  }
  return 0;
}