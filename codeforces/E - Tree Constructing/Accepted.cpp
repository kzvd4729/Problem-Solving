/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2020 18:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 6200 KB                              
*  problem: https://codeforces.com/contest/1003/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
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
#include<random>
#define long long long
using namespace std;
const int N=1e6;
vector<pair<int,int> >ed;
int n,m,k,d;
void dfs(int u,int dg,int ds)
{
  if(ds==0||m==n)return;
   for(int i=dg+1;i<=k;i++)
  {
    if(m==n)break;
    ed.push_back({u,++m});
    dfs(m,1,ds-1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>d>>k;
  if(k==1)
  {
    if(n==2&&d==1)cout<<"YES\n"<<1<<" "<<2<<"\n";
    else cout<<"NO\n";exit(0);
  }
  if(d>=n)cout<<"NO\n",exit(0);
   for(int i=1;i<=d;i++)ed.push_back({i,i+1});
  m=d+1;
   for(int i=2;i<=d;i++)dfs(i,2,min(i-1,d-i+1));
   if(m!=n)cout<<"NO\n",exit(0);
   cout<<"YES\n";
  for(auto x:ed)cout<<x.first<<" "<<x.second<<'\n';
   return 0;
}