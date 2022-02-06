/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/17/2020 20:26                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17                               
*  run_time: 218 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1398/problem/E
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long tt=0,sm=0;int mn=inf+1;
  set<int>st,a,b;st.insert(inf+1);a.insert(0);
  while(n--)
  {
    int ty,vl;cin>>ty>>vl;
    if(!ty)
    {
      if(vl>0)
      {
        st.insert(vl);a.insert(vl);tt+=vl;
        if(vl>mn)
        {
          sm+=vl-mn;mn=*st.lower_bound(mn+1);
        }
      }
      else
      {
        vl*=-1;
        st.erase(vl);a.erase(vl);tt-=vl;
        if(vl>=mn)
        {
          sm-=vl;
          auto it=st.lower_bound(mn);it--;
          sm+=*it;mn=*it;
        }
      }
    }
    else
    {
      if(vl>0)
      {
        st.insert(vl);b.insert(vl);tt+=vl;
        if(vl>mn)sm+=vl;
        else
        {
          auto it=st.lower_bound(mn);//assert(it!=st.begin());
          it--;
          sm+=*it;mn=*it;
        }
      }
      else
      {
        vl*=-1;
        st.erase(vl);b.erase(vl);tt-=vl;
        if(vl>=mn)sm-=vl;
        else
        {
          sm-=mn;mn=*st.lower_bound(mn+1);
        }
      }
    }
    long now=sm;
    if(b.size()&&mn<=*b.begin())
    {
      now-=*b.begin();
      auto it=a.lower_bound(mn);it--;
      now+=*it;
    }
    cout<<tt+now<<"\n";
  }
  return 0;
}