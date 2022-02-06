/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/25/2020 22:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 55300 KB                             
*  problem: https://codeforces.com/contest/1468/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
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
int a[N+2],bg[N+2],bit[N+2],n;
vector<int>bf[N+2];
void upd(int x,int vl)
{
  for( ;x<=n;x+=x&-x)bit[x]=max(bit[x],vl);
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret=max(ret,bit[x]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)bf[i].clear(),bit[i]=0,bg[i]=-1;
    stack<pair<int,int> >st;
    for(int i=1;i<=n;i++)
    {
      while((int)st.size()&&st.top().first<a[i])st.pop();
      if((int)st.size())bg[i]=st.top().second;
      st.push({a[i],i});
    }
    //for(int i=1;i<=n;i++)cout<<bg[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)
    {
      if(bg[i]!=-1)bf[bg[i]].push_back(a[i]);
    }
    map<pair<int,int>,int>mp;int ans=0;
    for(int i=1;i<=n;i++)
    {
      for(auto x:bf[i])mp[{i,x}]=get(x);
      int mx=0;
      if(bg[i]!=-1)
      {
        mx=mp[{bg[i],a[i]}]+2;
      }
      mx=max(mx,get(a[i])+1);
      ans=max(ans,mx);upd(a[i],mx);
    }
    cout<<ans<<'\n';
  }
  return 0;
}