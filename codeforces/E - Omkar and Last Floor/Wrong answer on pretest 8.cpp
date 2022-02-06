/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/11/2020 22:27                        
*  solution_verdict: Wrong answer on pretest 8               language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1372/problem/E
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
const int N=1e2;
int l[N+2][N+2],r[N+2][N+2],mt[N+2][N+2],rm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int k;cin>>k;
    while(k--)
    {
      int a,b;cin>>a>>b;
      for(int j=a;j<=b;j++)l[i][j]=a,r[i][j]=b;
    }
  }
  set<pair<int,int> >st;
  for(int i=1;i<=m;i++)st.insert({n,i});
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)mt[i][j]=1;
  }
  for(int i=1;i<=m;i++)rm[i]=n;
   long ans=0;
  while(st.size())
  {
    pair<int,int>p=*st.rbegin();st.erase(p);
    ans+=1LL*p.first*p.first;
     int cl=p.second;
    for(int i=1;i<=n;i++)
    {
      if(mt[i][cl]==0)continue;
      mt[i][cl]=0;
      for(int j=l[i][cl];j<=r[i][cl];j++)
      {
        if(j==cl)continue;st.erase({rm[j],j});
        rm[j]--;mt[i][j]=0;
        if(rm[j])st.insert({rm[j],j});
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}