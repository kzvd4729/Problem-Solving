/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-12-15 18:17:59                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 152 ms                                          memory_used: 9600 KB                              
*  problem: https://atcoder.jp/contests/agc029/tasks/agc029_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;multiset<int>st;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;st.insert(x);
  }
  int ans=0;
  while(st.size())
  {
    int x=*st.rbegin();
    st.erase(st.find(x));
     for(int i=30;i>=0;i--)
    {
      int z=(1<<i)-x;
      if(z<0)break;
      if(st.find(z)!=st.end())
      {
        ans++;st.erase(st.find(z));
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}