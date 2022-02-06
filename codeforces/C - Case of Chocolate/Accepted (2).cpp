/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 00:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 467 ms                                          memory_used: 12700 KB                             
*  problem: https://codeforces.com/contest/555/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=2e5;
const int inv=2e9;
int n,q;
map<int,int>vis;
set<pair<int,int> >up,lt;
set<pair<int,int> >::iterator it,ti;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   up.insert({-inv,-inv});
  lt.insert({-inv,-inv});
   cin>>n>>q;
  while(q--)
  {
    int x,y;char c;cin>>x>>y>>c;
    swap(x,y);
    if(vis[x])
    {
      cout<<0<<endl;
      continue;
    }
    vis[x]=1;
    int a,b;
    if(c=='U')
    {
      it=up.lower_bound({y,-1});
      if(it==up.end())
      {
        it=lt.lower_bound({x,-1});it--;
        if(it->first==-inv)
        {
          cout<<x<<endl;
          up.insert({y,x});
        }
        else
        {
          cout<<x-it->first<<endl;
          up.insert({y,x-it->first});
        }
      }
      else
      {
        a=n+1-it->first-it->second+1;
        b=n+1-it->first;
        it=lt.lower_bound({x,-1});it--;
        if(it->first>b)
          a=it->first+1;
        cout<<x-a+1<<endl;
        up.insert({y,x-a+1});
      }
    }
    else
    {
      it=lt.lower_bound({x,-1});
      if(it==lt.end())
      {
        it=up.lower_bound({y,-1});it--;
        if(it->first==-inv)
        {
          cout<<y<<endl;
          lt.insert({x,y});
        }
        else
        {
          cout<<y-it->first<<endl;
          lt.insert({x,y-it->first});
        }
      }
      else
      {
        a=n+1-it->first-it->second+1;
        b=n+1-it->first;
        it=up.lower_bound({y,-1});it--;
        if(it->first>b)
          a=it->first+1;
        cout<<y-a+1<<endl;
        lt.insert({x,y-a+1});
      }
    }
  }
  return 0;
}