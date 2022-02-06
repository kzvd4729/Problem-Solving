/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2020 19:47                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 405 ms                                          memory_used: 35900 KB                             
*  problem: https://codeforces.com/contest/1148/problem/E
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
#define endl "\n"
#define long long long  
using namespace std;
const int N=1e6;
pair<int,int>a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
  for(int i=1;i<=n;i++)cin>>b[i].first,b[i].second=i;
   sort(a+1,a+n+1);sort(b+1,b+n+1);
   vector<int>v;
  for(int i=1;i<=n;i++)
    if(a[i].first>b[i].first)v.push_back(i);
   vector<vector<int> >ans;
  int p=0;
  for(int i=1;i<=n;i++)
  {
    if(a[i].first>b[i].first)cout<<"NO"<<endl,exit(0);
    while(a[i].first<b[i].first)
    {
      if(p==v.size())cout<<"NO"<<endl,exit(0);
      int mn=min(b[i].first-a[i].first,a[v[p]].first-b[v[p]].first);
      if(mn==0){p++;continue;}
      ans.push_back({a[i].second,a[v[p]].second,mn});
      a[i].first+=mn;a[v[p]].first-=mn;
    }
  }
  cout<<"YES"<<endl<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
  return 0;
}