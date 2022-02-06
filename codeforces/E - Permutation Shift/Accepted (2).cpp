/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/10/2021 18:18                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 826 ms                                          memory_used: 27100 KB                             
*  problem: https://codeforces.com/contest/1553/problem/E
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 const int N=1e6,inf=1e9;
 int a[N+2],cnt[N+2],par[N+2];
 int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
void addEdge(int x,int y)
{
  int u=get(x),v=get(y);
  if(u==v)return ;
  par[u]=v;
}
 int vs[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
     for(int i=0;i<n;i++)cnt[i]=0;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
       int sh=(i-a[i]+n)%n;
      cnt[sh]++;
      //cout<<sh<<" ";
    }
    //cout<<endl;
     vector<pair<int,int> >v;
    for(int i=0;i<n;i++)v.push_back({cnt[i],i});
     sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
     vector<int>ans;
    for(int i=0;i<min(100,n);i++)
    {
      int sh=v[i].second;
      for(int j=1;j<=n;j++)par[j]=j;
       for(int j=1;j<=n;j++)
      {
        int rl=a[j]+sh;
        if(rl>n)rl-=n;
         addEdge(j,rl);
      }
       for(int j=1;j<=n;j++)vs[j]=0;
      for(int j=1;j<=n;j++)vs[get(j)]=1;
       int cnt=n;
      for(int j=1;j<=n;j++)cnt-=vs[j];
       if(cnt<=m)ans.push_back(v[i].second);
    }
    cout<<ans.size()<<" ";
    sort(ans.begin(),ans.end());
    for(auto x:ans)cout<<x<<" ";cout<<endl;
  }
    return 0;
}