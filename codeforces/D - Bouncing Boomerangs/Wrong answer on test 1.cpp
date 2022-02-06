/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/03/2020 16:10                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/1428/problem/D
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
const int N=5e5;
int a[N+2];
void no()
{
  cout<<-1<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   vector<pair<int,int> >v;vector<int>row,col;
  for(int i=n;i>=1;i--)
  {
    if(a[i]==0)continue;
    else if(a[i]==1)
    {
      v.push_back({i,i});
      row.push_back(i);col.push_back(i);
    }
    else if(a[i]==2)
    {
      if(row.size()==0)no();
      v.push_back({row.back(),i});
      row.pop_back();col.push_back(i);
    }
    else
    {
      v.push_back({i,i});if(col.size()==0)no();
      v.push_back({i,col.back()});col.pop_back();
      col.push_back(i);
    }
  }
  cout<<v.size()<<'\n';
  for(auto x:v)cout<<x.first<<" "<<x.second<<'\n';
  return 0;
}