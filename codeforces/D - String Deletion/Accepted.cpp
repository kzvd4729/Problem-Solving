/****************************************************************************************
*  @author: kzvd4729#                                        created: Mar/24/2021 20:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/1430/problem/D
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
const int N=2e5,inf=1e9,mod=998244353;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    string s;cin>>s;s="#"+s;
     int cnt=1;vector<int>v;
    for(int i=n-1;i>=1;i--)
    {
      if(s[i]==s[i+1])cnt++;
      else 
      {
        v.push_back(cnt);
        cnt=1;
      }
    }
    v.push_back(cnt);
        set<pair<int,int> >st;
    for(int i=0;i<(int)v.size();i++)
      if(v[i]>1)st.insert({i,v[i]});
     //for(int i=0;i<v.size();i++)cout<<v[i];cout<<endl;
     int ans=0;
    while((int)v.size())
    {
      int f=0;
      while((int)st.size())
      {
        pair<int,int>p=*st.rbegin();st.erase(p);
        if(p.first>=(int)v.size())continue;
         v[p.first]--;
        if(p.second-1>1)st.insert({p.first,p.second-1});
        f=1;break;
      }
      ans++;
      v.pop_back();
      if(f==0 && (int)v.size())v.pop_back();
    }
    cout<<ans<<endl;
  }
  return 0;
}