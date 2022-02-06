/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/25/2020 20:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1468/problem/K
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
const int N=1e6;
int mn[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int x=0,y=0;vector<pair<int,int> >v;
    string s;cin>>s;
    for(auto z:s)
    {
      if(z=='L')x--;else if(z=='R')x++;
      else if(z=='D')y--;else y++;
       if(x==0&&y==0);
      else v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
     int px=0,py=0;
    for(auto p:v)
    {
      x=0,y=0;
      for(auto z:s)
      {
        int xx=x,yy=y;
        if(z=='L')x--;else if(z=='R')x++;
        else if(z=='D')y--;else y++;
         if(x==p.first&&y==p.second)x=xx,y=yy;
      }
      if(x==0&&y==0)px=p.first,py=p.second;
    }
    cout<<px<<" "<<py<<'\n';
  }
  return 0;
}