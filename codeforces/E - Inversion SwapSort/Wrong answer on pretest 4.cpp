/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/04/2020 22:03                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 23200 KB                             
*  problem: https://codeforces.com/contest/1375/problem/E
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
#define long long long  
using namespace std;
const int N=1e6;
int a[N+2],b[N+2];
vector<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
   sort(b+1,b+n+1);
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(a[i]>a[j])
      {
        adj[i].push_back(j);
      }
    }
  }
  vector<pair<int,int> >ans;
  for(int i=1;i<=n;i++)
  {
    int tr=b[i];
    if(adj[i].size()==0)
    {
      if(tr!=a[i])cout<<-1<<endl,exit(0);
      continue;
    }
    int f=-1;
    for(auto x:adj[i])
    {
      if(a[x]==tr)f=x;
    }
    if(f==-1)cout<<-1<<endl,exit(0);
    for(auto x:adj[i])
    {
      if(x==f)continue;ans.push_back({i,x});
      swap(a[i],a[x]);
    }
    ans.push_back({i,f});
    swap(a[i],a[f]);
     if(a[i]!=b[i])cout<<-1<<endl,exit(0);
  }
  cout<<ans.size()<<"\n";
  for(auto x:ans)cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}