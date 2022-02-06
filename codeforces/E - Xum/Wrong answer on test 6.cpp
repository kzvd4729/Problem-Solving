/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2020 00:19                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 373 ms                                          memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1427/problem/E
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
const int N=1e6,inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   vector<vector<int> >ans;
   int n;cin>>n;
  set<int>st;st.insert(n);st.insert(n+n);st.insert(0);
  ans.push_back({n,0,n});ans.push_back({n,1,n});
  for(int lp=1;lp<=1000000;lp++)
  {
    if(st.size()>100000-10)break;
    int op=rng()%2;
    if(op)
    {
      int a,b;
      auto x=st.upper_bound(1+rng()%inf);x--;
      auto nx=x,pr=x;nx++;pr--;
      a=*x;if(nx!=st.end())b=*nx;else b=*pr;
      if(a<=inf&&b<=inf&&st.find(a+b)==st.end())
      {
        st.insert(a+b);
        ans.push_back({a,1,b});
      }
    }
    else
    {
      int a,b;
      auto x=st.upper_bound(1+rng()%inf);x--;
      auto nx=x,pr=x;nx++;pr--;
      a=*x;if(nx!=st.end())b=*nx;else b=*pr;
      if(a<=inf&&b<=inf&&st.find((a^b))==st.end())
      {
        st.insert(a^b);
        ans.push_back({a,0,b});
      }
    }
  }
  vector<int>v(st.begin(),st.end());
  sort(v.begin(),v.end());int f=0;
  v.erase(unique(v.begin(),v.end()),v.end());
  //cout<<v.size()<<endl;
  for(int i=0;i<v.size()-1;i++)
  {
    if(v[i]+1==v[i+1])
    {
      ans.push_back({v[i],0,v[i+1]});
      break;
    }
  }
  cout<<ans.size()<<'\n';
  for(auto x:ans)
  {
    cout<<x[0];
    if(x[1])cout<<" + ";
    else cout<<" ^ ";
    cout<<x[2]<<'\n';
  }
   return 0;
}