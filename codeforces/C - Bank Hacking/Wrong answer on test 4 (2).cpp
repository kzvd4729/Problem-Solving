/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/07/2020 12:35                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/796/problem/C
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
int aa[N+2],mx,nd;
vector<int>adj[N+2];
void dfs(int node,int p,int g)
{
  int c=2;c-=(g==-1);
  sort(adj[node].begin(),adj[node].end(),[&](int a,int b){
    return aa[a]>aa[b];
  });
  int ex=0;
  for(auto x:adj[node])
  {
    if(x==p)continue;
    if(c+ex+aa[x]>mx)mx=c+ex+aa[x],nd=x;
    dfs(x,node,p);ex++;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  mx=aa[1],nd=1;dfs(1,-1,-1);//cout<<nd<<endl;
  mx=aa[nd];dfs(nd,-1,-1);cout<<mx<<endl;
  return 0;
}