/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2020 22:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 19900 KB                             
*  problem: https://codeforces.com/contest/1408/problem/E
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
int a[N+2],b[N+2],par[N+2];
int find(int x)
{
  if(x==par[x])return x;
  return par[x]=find(par[x]);
}
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int m,n;cin>>m>>n;
  for(int i=1;i<=m;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i];
   vector<vector<int> >ed;
  for(int i=1;i<=m;i++)
  {
    int nm;cin>>nm;
    while(nm--)
    {
      int x;cin>>x;
      ed.push_back({a[i]+b[x],m+x,i});
    }
  }
  sort(ed.begin(),ed.end());reverse(ed.begin(),ed.end());
  long ans=0;for(int i=1;i<=N;i++)par[i]=i;
   for(auto x:ed)
  {
    int r1=find(x[1]),r2=find(x[2]);
     if(r1==r2)ans+=x[0];
    else par[r1]=r2;
  }
  cout<<ans<<endl;
  return 0;
}