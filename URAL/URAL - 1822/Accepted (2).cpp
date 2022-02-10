/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-02-03 20:30:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 78                                         memory_used (MB): 25.6                            
*  problem: https://vjudge.net/problem/URAL-1822
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9;

vector<int>ad[N+2];
int vl[N+2];

int dfs(int nd,double p)
{
  vector<int>v;
  for(auto x:ad[nd])
    v.push_back(dfs(x,p));

  sort(v.begin(),v.end());
  double sz=v.size();

  if((int)v.size()==0)return vl[nd];

  for(int i=0;i<(int)v.size();i++)
    if((((i+1)*1.0)/sz)*100.0>=p)return v[i]+vl[nd];

  
  return N+N;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n,t;cin>>n>>t;
  for(int i=2;i<=n;i++)
  {
    int p,x;cin>>p>>x;
    ad[p].push_back(i);vl[i]=x;
  }
  //cout<<dfs(1,70)<<endl;
  //return 0;
  double lo=0,hi=100,md;
  while(hi-lo>0.00000001)
  {
    md=(lo+hi)/2;
    //cout<<md<<" "<<dfs(1,md)<<endl;
    if(dfs(1,md)>t)hi=md;
    else lo=md;
  }
  cout<<setprecision(6)<<fixed<<md<<endl;
  
  return 0;
}