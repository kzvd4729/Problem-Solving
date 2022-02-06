/****************************************************************************************
*  @author: kzvd4729#                                        created: May/30/2020 10:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 3000 KB                              
*  problem: https://codeforces.com/contest/821/problem/C
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
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;stack<pair<int,int> >st;int now=0,srt=0,pr=0,ans=0;
  for(int i=1;i<=n+n;i++)
  {
    string s;cin>>s;
    if(s=="add")
    {
      int x;cin>>x;
      now++;st.push({now,x});
    }
    else
    {
      while(st.size())
      {
        pair<int,int>pp=st.top();
        if(pp.second<=pr)st.pop();
        else break;
      }
      pr++;
      if(st.top().second==pr)st.pop();
      else if(st.top().first<=srt);
      else ans++,srt=now;
    }
  }
  cout<<ans<<endl;
  return 0;
}