/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2021 18:27                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++17 (64)                          
*  run_time: 280 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/1500/problem/B
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
const int N=5e5,inf=1e9,mod=1e9+7;
 int a[N+2],b[N+2],fr[N+2];
vector<int>v[N+2];
deque<int>dq[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;long k;cin>>n>>m>>k;
   for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=m;i++)cin>>b[i];
   if(n<m)swap(n,m),swap(a,b);
  //cout<<endl;
  //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  //for(int i=1;i<=m;i++)cout<<b[i]<<" ";cout<<endl;
   int gc=__gcd(n,m);
  long lc=(1LL*n*m)/gc;
   for(int i=1;i<=n;i++)v[(i-1)%gc].push_back(a[i]);
  for(int i=0;i<gc;i++)sort(v[i].begin(),v[i].end());
   int cy=0;
  for(int i=1;i<=m;i++)
  {
    int id=(i-1)%gc;
    cy+=upper_bound(v[id].begin(),v[id].end(),b[i])-lower_bound(v[id].begin(),v[id].end(),b[i]);
  }
  cy=lc-cy;
  long d=(k-1)/cy;
  long ans=lc*d;k-=cy*d;//cout<<k<<endl;
    //cout<<ans<<endl,exit(0);
   long lo=1,hi=1LL*n*m,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
     long now=0;
    for(int i=0;i<gc;i++)dq[i].clear();
    for(int i=0;i<gc;i++)
    {
      for(int j=i;j<lc;j+=m)
      {
        dq[i].push_back(j+1);
      }
      //cout<<i<<" --> ";
      //for(auto x:dq[i])cout<<x<<" ";cout<<endl;
      int pt=-1;
      while(true)
      {
        if(pt+1<(int)dq[i].size() && dq[i][pt+1]<=md)
        {
          pt++;
          fr[a[(dq[i][pt]-1)%n+1]]++;
          //cout<<"*"<<dq[i][pt]%n+1<<endl;
        }
        else break;
      }
      int ls=dq[i][pt],sub=0;
      for(int j=i;j<m;j+=gc)
      {
        now+=fr[b[j+1]];
          int id=dq[i].back();dq[i].pop_back();
        fr[a[(id-1)%n+1]]++;
        dq[i].push_front(id);if(pt<(int)dq[i].size()-1)pt++;
         sub+=gc;
        if(dq[i][pt]+sub>md)
        {
          fr[a[(dq[i][pt]-1)%n+1]]--;
          pt--;
        }
       }
      for(int j=i;j<lc;j+=m)
      {
        fr[a[j%n+1]]=0;
      }
    }
    now=md-now;//cout<<md<<" "<<now<<endl;
    if(now>=k)hi=md;
    else lo=md;
     //exit(0);
  }
  for(md=lo;md<=hi;md++)
  {
    long now=0;
    for(int i=0;i<gc;i++)dq[i].clear();
    for(int i=0;i<gc;i++)
    {
      for(int j=i;j<lc;j+=m)
      {
        dq[i].push_back(j+1);
      }
      //cout<<i<<" --> ";
      //for(auto x:dq[i])cout<<x<<" ";cout<<endl;
      int pt=-1;
      while(true)
      {
        if(pt+1<(int)dq[i].size() && dq[i][pt+1]<=md)
        {
          pt++;
          fr[a[(dq[i][pt]-1)%n+1]]++;
          //cout<<"*"<<dq[i][pt]%n+1<<endl;
        }
        else break;
      }
      int ls=dq[i][pt],sub=0;
      for(int j=i;j<m;j+=gc)
      {
        now+=fr[b[j+1]];
          int id=dq[i].back();dq[i].pop_back();
        fr[a[(id-1)%n+1]]++;
        dq[i].push_front(id);if(pt<(int)dq[i].size()-1)pt++;
         sub+=gc;
        if(dq[i][pt]+sub>md)
        {
          fr[a[(dq[i][pt]-1)%n+1]]--;
          pt--;
        }
       }
      for(int j=i;j<lc;j+=m)
      {
        fr[a[j%n+1]]=0;
      }
    }
    now=md-now;
    if(now>=k)break;
  }
  cout<<ans+md<<endl;
  return 0;
}