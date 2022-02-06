/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/28/2020 14:35                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/1426/problem/D
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
int a[N+2],r[N+2];
long qm[N+2];
map<long,vector<int> >mp;
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++)qm[i]=qm[i-1]+a[i];
  for(int i=1;i<=n;i++)mp[qm[i]].push_back(i);
   for(auto x:mp)sort(x.second.begin(),x.second.end());
   for(int i=1;i<=n;i++)
  {
    long sm=qm[i-1];
    vector<int>&v=mp[sm];
    int id=upper_bound(v.begin(),v.end(),i)-v.begin();
     if(id<v.size())r[i]=v[id];
  }
  vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)if(r[i])v.push_back({i,r[i]});
  sort(v.begin(),v.end());
  int cnt=0,dn=-1;
  for(auto x:v)
  {
    if(x.first<=dn)continue;
    cnt++;dn=max(dn,x.second-1);
  }
  cout<<cnt<<endl;
  return 0;
}