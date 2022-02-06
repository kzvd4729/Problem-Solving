/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2020 19:43                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17                               
*  run_time: 140 ms                                          memory_used: 6100 KB                              
*  problem: https://codeforces.com/contest/1251/problem/E2
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
const int N=2e5;
int vs[N+2];
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;for(int i=1;i<=n;i++)vs[i]=0;
    for(int i=1;i<=n;i++)cin>>pp[i].first>>pp[i].second;
    sort(pp+1,pp+n+1);priority_queue<int>tk;
    for(int i=1;i<=n;i++)tk.push(0);
     set<pair<int,int> >rm;
    for(int i=1;i<=n;i++)rm.insert({pp[i].second,i});
     //for(int i=1;i<=n;i++)cout<<pp[i].first<<" -- "<<pp[i].second<<endl;
     int sz=0;long ans=0;
    for(int i=1;i<=n;i++)
    {
      if(sz>=pp[i].first)
      {
        if(vs[i]){tk.push(pp[i].second);continue;}
        rm.erase({pp[i].second,i});
        sz++;continue;
      }
      pair<int,int>p=*rm.begin();rm.erase(p);i--;
      int an=tk.top();ans+=p.first-an;sz++;
      vs[p.second]=1;
    }
    cout<<ans<<"\n";
  }
  return 0;
}