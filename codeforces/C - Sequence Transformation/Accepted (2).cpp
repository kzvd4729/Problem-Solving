/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/24/2020 20:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 20000 KB                             
*  problem: https://codeforces.com/contest/1454/problem/C
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
vector<int>v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int id=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      if(a[id]==x)continue;
      a[++id]=x;
    }
    n=id;compress(n);
    if(n==1)
    {
      cout<<0<<endl;continue;
    }
    int mx=*max_element(a+1,a+n+1);
    for(int i=1;i<=n;i++)
      v[a[i]].push_back(i);
     //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
     int ans=N;
    for(int i=1;i<=mx;i++)
    {
      int now=(int)v[i].size()+1;//cout<<i<<" "<<v[i].size()<<endl;
      if(v[i][0]==1)now--;
      if(v[i].back()==n)now--;
      ans=min(ans,now);
       v[i].clear();
    }
    cout<<ans<<endl;
  }
  return 0;
}