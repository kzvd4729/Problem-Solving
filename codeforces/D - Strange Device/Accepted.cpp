/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2020 16:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/1270/problem/D
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
   if(k==1)cout<<"! "<<1<<endl,exit(0);
   cout<<"?";
  for(int i=1;i<=k;i++)cout<<" "<<i;cout<<endl;
  int ps,vl;cin>>ps>>vl;
   cout<<"?";
  for(int i=1;i<=k+1;i++)if(i!=ps)cout<<" "<<i;cout<<endl;
  int ps2,vl2;cin>>ps2>>vl2;
   vector<int>v;int fx,an;
  for(int i=1;i<=n;i++)if(v.size()<k-1&&i!=ps&&i!=ps2)v.push_back(i);
  if(vl<vl2)fx=ps,an=ps2;
  else fx=ps2,an=ps;
   int ans=1;
  for(int i=0;i<v.size();i++)
  {
    cout<<"? "<<fx<<" "<<an;
    for(int j=0;j<v.size();j++)if(i!=j)cout<<" "<<v[j];cout<<endl;
    int t1,t2;cin>>t1>>t2;if(t1!=fx)ans++;
  }
  cout<<"! "<<ans<<endl;
  return 0;
}