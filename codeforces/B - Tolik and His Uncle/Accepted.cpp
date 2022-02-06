/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2020 20:53                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 452 ms                                          memory_used: 42900 KB                             
*  problem: https://codeforces.com/contest/1179/problem/B
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
set<pair<int,int> >ans;
vector<pair<int,int> >pr;
void solve(int a,int b,int m)
{
  if(a==b)
  {
    int sgn=1;
    for(int i=m-1;i>=1;i--)
    {
      ans.insert({0,i*sgn});pr.push_back({0,i*sgn});
      sgn*=-1;
    }
    return ;
  }
  int l=m;
  for(int j=1;j<=m;j++)
  {
    ans.insert({b-a,l-j});pr.push_back({b-a,l-j});
    if(j<m)ans.insert({a-b,j+1-l}),pr.push_back({a-b,j+1-l});
    l--;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
   int a=1,b=n;
  while(true)
  {
    solve(a,b,m);if(b-a<=1)break;
    ans.insert({a+1-b,0}),pr.push_back({a+1-b,0});
    a++,b--;
  }
  a=1,b=1;cout<<a<<" "<<b<<endl;
  for(int i=0;i<pr.size();i++)
  {
    a+=pr[i].first,b+=pr[i].second;
    cout<<a<<" "<<b<<endl;
  }
  return 0;
}