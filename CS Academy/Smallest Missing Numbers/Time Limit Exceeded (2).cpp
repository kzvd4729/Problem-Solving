/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time: 1095 ms                                         memory_used: 5112 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,x;
set<int>st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    st.insert(x);
  }
  st.insert(2e9);
  int now=1;
  long sum=0;
  while(m)
  {
    if(now==*st.begin())
    {
      st.erase(*st.begin());
      now++;
    }
    else
    {
      sum+=(now*1LL);
      now++;
      m--;
    }
  }
  cout<<sum<<endl;
  return 0;
}