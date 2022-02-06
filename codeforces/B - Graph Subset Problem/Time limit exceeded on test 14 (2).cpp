/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2020 20:45                        
*  solution_verdict: Time limit exceeded on test 14          language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 21400 KB                             
*  problem: https://codeforces.com/contest/1439/problem/B
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
const int N=2e5;
int d[N+2];
vector<int>ad[N+2];set<int>da[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++)d[i]=0,ad[i].clear();
    for(int i=1;i<=m;i++)
    {
      int a,b;cin>>a>>b;d[a]++,d[b]++;
      ad[a].push_back(b);ad[b].push_back(a);
    }
    set<pair<int,int> >st;
    for(int i=1;i<=n;i++)st.insert({d[i],i});
     while((int)st.size())
    {
      pair<int,int>p=*st.begin();
      if(p.first>=k)break;
       st.erase(p);
      for(auto x:ad[p.second])
      {
        if(st.find({d[x],x})==st.end())continue;
         st.erase({d[x],x});d[x]--;
        st.insert({d[x],x});
      }
    }
    if((int)st.size())
    {
      cout<<1<<" "<<(int)st.size()<<'\n';
      for(auto x:st)cout<<x.second<<" ";
        cout<<'\n';
      continue;
    }
    for(int i=1;i<=n;i++)
    {
      for(auto x:ad[i])da[i].insert(x);
    }
    for(int i=1;i<=n;i++)d[i]=da[i].size();
    st.clear();
     vector<int>ans;
    for(int i=1;i<=n;i++)st.insert({d[i],i});
    while((int)st.size())
    {
      pair<int,int>p=*st.begin();
      if(p.first==k-1)
      {
        vector<int>tr;tr.push_back(p.second);
        for(auto x:da[p.second])tr.push_back(x);
         int f=1;
        //for(auto x:tr)if((int)da[x].size()<k-1)f=0;
        for(auto a:tr)
        {
          if(f==0)break;
          for(auto b:tr)
          {
            if(a==b)continue;
            if(da[a].count(b)==0){f=0;break;}
          }
        }
        if(f==1){ans=tr;break;}
      }
       st.erase(p);
      for(auto x:da[p.second])
      {
        if(st.find({d[x],x})==st.end())continue;
         st.erase({d[x],x});d[x]--;
        st.insert({d[x],x});
        da[x].erase(p.second);
      }
    }
    if((int)ans.size()==0)cout<<-1<<'\n';
    else 
    {
      cout<<2<<'\n';
      for(auto x:ans)cout<<x<<" ";
        cout<<'\n';
    }
    for(int i=1;i<=n;i++)da[i].clear();
  }
  return 0;
}