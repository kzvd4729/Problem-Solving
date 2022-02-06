/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/01/2020 20:39                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1408/problem/F
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
vector<pair<int,int> >v;
void solve(int l,int r)
{
  int p=1;
  for(int lp=1;lp<=20;lp++)
  {
    for(int i=l;i+p+p-1<=r;i+=p+p)
    {
      for(int j=i;j<i+p;j++)
      {
        //cout<<j<<" "<<j+p<<endl;
        v.push_back({j,j+p});
      }
    }
    p*=2;
  }
}
vector<int>xx[N+2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int l=1,cnt=0;set<pair<int,int> >st;
  for(int i=20;i>=0;i--)
  {
    if(l+(1<<i)-1<=n)
    {
      solve(l,l+(1<<i)-1);
      ++cnt;
      for(int j=l;j<l+(1<<i);j++)
        xx[cnt].push_back(j);
      st.insert({(1<<i),cnt});
      l+=(1<<i);
    }
  }
  while(st.size()>2)
  {
    pair<int,int>s1=*st.begin();st.erase(s1);
    pair<int,int>s2=*st.begin();st.erase(s2);
    pair<int,int>s3=*st.rbegin();st.erase(s3);
     if(s1.first==s2.first)
    {
      for(int i=0;i<s1.first;i++)
        v.push_back({xx[s1.second][i],xx[s2.second][i]});
      for(auto x:xx[s1.second])xx[s2.second].push_back(x);
      st.insert({s1.first+s2.first,s2.second});
      st.insert(s3);
    }
    else if(s2.first==s3.first)
    {
      for(int i=0;i<s2.first;i++)
        v.push_back({xx[s2.second][i],xx[s3.second][i]});
      for(auto x:xx[s2.second])xx[s3.second].push_back(x);
      st.insert({s2.first+s3.first,s3.second});
      st.insert(s1); 
    }
    else
    {
      int mx=min(s1.first,s2.first-s1.first);
      int id=0;
      while(mx--)
      {
        v.push_back({xx[s3.second].back(),xx[s1.second][id]});
        xx[s1.second].push_back(xx[s3.second].back());
        xx[s3.second].pop_back();s3.first--;s1.first++;
      }
      st.insert(s1);st.insert(s2);st.insert(s3);
    }
  }
  for(auto x:v)cout<<x.first<<" "<<x.second<<'\n';
  return 0;
}