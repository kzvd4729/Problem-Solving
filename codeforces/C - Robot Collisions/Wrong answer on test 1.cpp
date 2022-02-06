/****************************************************************************************
*  @author: kzvd4729#                                        created: May/26/2021 15:51                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1525/problem/C
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
const int N=1e6,inf=1e9,mod=998244353;
 int ans[N+2];
pair<int,char>p[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>p[i].first;
    for(int i=1;i<=n;i++)cin>>p[i].second;
     map<int,int>mp;
    for(int i=1;i<=n;i++)mp[p[i].first]=i;
    sort(p+1,p+n+1);
     //for(int i=1;i<=n;i++)cout<<p[i].first<<" ";cout<<endl;
     for(int i=1;i<=n;i++)ans[i]=-1;
     set<int>st[2];
    for(int i=1;i<=n;i++)
    {
      int pr=p[i].first%2;
      if(p[i].second=='R')st[pr].insert(p[i].first);
      else
      {
        if((int)st[pr].size()==0)st[pr].insert(-p[i].first);
        else
        {
          int cn=*st[pr].rbegin();st[pr].erase(cn);
          ans[mp[p[i].first]]=(p[i].first-cn)/2;
          ans[mp[abs(cn)]]=(p[i].first-cn)/2;
        }
      }
    }
    st[0].clear(),st[1].clear();
    for(int i=n;i>=1;i--)
    {
      if(ans[mp[p[i].first]]!=-1)continue;
      //cout<<p[i].first<<" "<<p[i].second<<endl;
      int pr=p[i].first%2;
      if(p[i].second=='L')st[pr].insert(p[i].first);
      else
      {
        if((int)st[pr].size()==0)st[pr].insert(m+m-p[i].first);
        else
        {
          //cout<<"HERE"<<endl;
          int cn=*st[pr].begin();st[pr].erase(cn);
          ans[mp[p[i].first]]=(cn-p[i].first)/2;
           int id;if(cn<=m)id=mp[cn];else id=mp[-cn+m+m];
          ans[id]=(p[i].first-cn)/2;
        }
      }
    }
    st[0].clear(),st[1].clear();
     for(int i=1;i<=n;i++)
    {
      if(ans[mp[p[i].first]]!=-1)continue;
      int pr=p[i].first%2;
      if(p[i].second=='L')st[pr].insert(-p[i].first);
    }
    for(int i=n;i>=1;i--)
    {
      if(ans[mp[p[i].first]]!=-1)continue;
      int pr=p[i].first%2;
      if(p[i].second=='R')
      {
        if((int)st[pr].size()==0)continue;
        int cn=m+m-p[i].first;
                int b=*st[pr].rbegin();st[pr].erase(b);
        ans[mp[p[i].first]]=(cn-b)/2;
        ans[mp[abs(b)]]=(cn-b)/2;
      }
    }
      for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  }
    return 0;
}