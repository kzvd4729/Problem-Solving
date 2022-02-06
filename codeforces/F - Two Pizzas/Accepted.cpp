/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/15/2020 21:20                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 280 ms                                          memory_used: 6300 KB                              
*  problem: https://codeforces.com/contest/1185/problem/F
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=(1<<10)+2;
int msk[100000+2],sub[N+2];
vector<pair<int,int> >v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int f;cin>>f;int now=0;
    while(f--)
    {
      int x;cin>>x;
      now|=(1<<(x-1));
    }
    msk[i]=now;
  }
  for(int i=0;i<(1<<9);i++)
  {
    for(int j=1;j<=n;j++)
      if((i&msk[j])==msk[j])sub[i]++;
  }
  for(int i=1;i<=m;i++)
  {
    int p,f;cin>>p>>f;int now=0;
    while(f--)
    {
      int x;cin>>x;
      now|=(1<<(x-1));
    }
    v[now].push_back({p,i});
  }
  for(int i=0;i<(1<<9);i++)
    sort(v[i].begin(),v[i].end());
   int mx=-1,a=1,b=2,p=0;
  for(int i=0;i<(1<<9);i++)
  {
    if(v[i].size()>=2)
    {
      if(sub[i]>mx)mx=sub[i],p=v[i][0].first+v[i][1].first,a=v[i][0].second,b=v[i][1].second;
      else if(sub[i]==mx&&v[i][0].first+v[i][1].first<p)
        p=v[i][0].first+v[i][1].first,a=v[i][0].second,b=v[i][1].second;
    }
    if(v[i].size()==0)continue;
    for(int j=i+1;j<(1<<9);j++)
    {
      if(v[j].size()==0)continue;
       if(sub[(i|j)]>mx)mx=sub[(i|j)],p=v[i][0].first+v[j][0].first,a=v[i][0].second,b=v[j][0].second;
      else if(sub[(i|j)]==mx&&v[i][0].first+v[j][0].first<p)
        p=v[i][0].first+v[j][0].first,a=v[i][0].second,b=v[j][0].second;
    }
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}