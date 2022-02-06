/****************************************************************************************
*  @author: jU_zQxRvd: iShibly, mh755628, kzvd4729           created: Apr/04/2021 14:59                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1510/problem/B
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
const int N=1e6,inf=1e9,mod=1e9+7;
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int d,n;cin>>d>>n;
    set<int>st;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    int b=0;
    for(auto x:s)b=b*2+(x-'0');
     st.insert(b);
  }
    vector<int>ans;
  int now=0;
   while((int)st.size())
  {
    int mn=inf;
    for(auto x:st)
    {
      if((now&x)==now)mn=min(mn,x);
    }
     if(mn==inf)
    {
      ans.push_back(-1);
      now=0;continue;
    }
    for(int i=0;i<d;i++)
    {
      if((mn&(1<<i)) && ((now&(1<<i))==0))
        ans.push_back(i);
    }
    now=mn;
    st.erase(now);
  }
  cout<<(int)ans.size()<<endl;
  for(auto x:ans)
  {
    if(x==-1)cout<<"R ";
    else cout<<d-1-x<<" ";
  }
  cout<<endl;
  return 0;
}