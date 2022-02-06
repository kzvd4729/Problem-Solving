/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2020 15:32                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 31200 KB                             
*  problem: https://codeforces.com/contest/1367/problem/F2
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
int a[N+2];
void compress(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(a[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
   for(int i=1;i<=n;i++)a[i]=mp[a[i]];
}
int bg[N+2],ed[N+2],par[N+2];
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
vector<int>po[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
     for(int i=1;i<=n;i++)cin>>a[i];
    compress(n);
     vector<int>v;
    for(int i=1;i<=n;i++)v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
     for(int i=1;i<=n;i++)
    {
      int x=a[i];if(bg[x]==0)bg[x]=i;ed[x]=i;
      par[i]=i;
    }
     for(int i=1;i<v.size();i++)
      if(ed[v[i-1]]<bg[v[i]])par[v[i]]=v[i-1];
     for(int i=1;i<=n;i++)a[i]=get(a[i]);
     /*for(int i=1;i<=n;i++)
      cout<<a[i]<<" ";
    cout<<endl;*/
     v.clear();
    for(int i=1;i<=n;i++)po[a[i]].push_back(i),v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
     int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,(int)po[i].size());
        for(int i=1;i<v.size();i++)
    {
      int x=v[i-1],y=v[i];
      for(int j=0;j<po[x].size();j++)
      {
        int id=upper_bound(po[y].begin(),po[y].end(),po[x][j])-po[y].begin();
        ans=max(ans,j+1+(int)po[y].size()-id);
      }
    }
    cout<<n-ans<<"\n";
     for(int i=1;i<=n;i++)po[i].clear(),bg[i]=0;
  }
  return 0;
}