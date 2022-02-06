/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2020 13:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 23900 KB                             
*  problem: https://codeforces.com/contest/670/problem/E
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
int pr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,p;cin>>n>>m>>p;string s;cin>>s;
  stack<pair<int,char> >sk;
  for(int i=1;i<=n;i++)
  {
    if(s[i-1]==')')
    {
      pr[i]=sk.top().first;pr[sk.top().first]=i;
      sk.pop();
    }
    else sk.push({i,s[i-1]});
  }
  string z;cin>>z;set<int>st;
  for(int i=1;i<=n;i++)st.insert(i);
   for(auto x:z)
  {
    auto it=st.find(p);
    if(x=='L')
    {
      it--;p=*it;
    }
    else if(x=='R')
    {
      it++;p=*it; 
    }
    else
    {
      int l=min(p,pr[p]),r=max(p,pr[p]);
      auto it=st.lower_bound(l);
       vector<int>bf;
      while(it!=st.end())
      {
        if(*it>r)break;
        bf.push_back(*it);it++;
      }
      for(auto b:bf)st.erase(b);
       it=st.lower_bound(r);
      if(it==st.end())it--;
      p=*it;
    }
  }
  for(auto x:st)cout<<s[x-1];cout<<endl;
  return 0;
}