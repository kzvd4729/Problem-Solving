/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/25/2020 20:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 654 ms                                          memory_used: 35500 KB                             
*  problem: https://codeforces.com/contest/1468/problem/C
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
  int id=0;set<int>ord;set<pair<int,int> >st;
  int t;cin>>t;
  while(t--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int m;cin>>m;mn[++id]=m;
      ord.insert(id);st.insert({-m,id});
    }
    else if(ty==2)
    {
      int dl=*ord.begin();cout<<dl<<'\n';
      ord.erase(dl);st.erase({-mn[dl],dl});
    }
    else
    {
      pair<int,int>dl=*st.begin();cout<<dl.second<<'\n';
      st.erase(dl);ord.erase(dl.second);
    }
  }
  return 0;
}