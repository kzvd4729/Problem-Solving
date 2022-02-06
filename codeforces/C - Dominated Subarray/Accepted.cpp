/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2019 22:42                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 140 ms                                          memory_used: 6000 KB                              
*  problem: https://codeforces.com/contest/1257/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
vector<int>pos[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<int>v;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;pos[x].push_back(i);
      v.push_back(x);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int mn=n+1;
    for(auto x:v)
    {
      for(int i=1;i<pos[x].size();i++)
        mn=min(mn,pos[x][i]-pos[x][i-1]+1);
      pos[x].clear();
    }
    if(mn>n)mn=-1;
    cout<<mn<<"\n";
   }
  return 0;
}