/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/08/2021 17:03                        
*  solution_verdict: Wrong answer on test 22                 language: GNU C++17 (64)                          
*  run_time: 171 ms                                          memory_used: 43700 KB                             
*  problem: https://codeforces.com/contest/1537/problem/F
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
 const int N=1e6,inf=1e9;
 int a[N+2],b[N+2],cl[N+2],sm[2];
vector<int>ad[N+2];
 int f;
 void dfs(int nd,int c)
{
  if(cl[nd]!=-1)
  {
    if(cl[nd]!=c)f=1;
    return ;
  }
  //cout<<nd<<" "<<c<<endl;
  cl[nd]=c;sm[c]+=a[nd]-b[nd];
   for(auto x:ad[nd])dfs(x,c^1);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
     for(int i=1;i<=n;i++)ad[i].clear(),cl[i]=-1;
      for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
      sm[0]=0,sm[1]=0,f=0;
    dfs(1,0);
     if(f)
    {
      if((sm[0]+sm[1])%2==0)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    else
    {
      if(sm[0]==sm[1])cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
  }
    return 0;
}