/****************************************************************************************
*  @author: kzvd4729                                         created: 07-04-2019 21:43:52                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/ALKH2019/problems/CERSOL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;
    set<int>st;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      st.insert(x);
    }
    while(m--)
    {
      int u,v;cin>>u>>v;
    }
    if(st.size()==k)
      cout<<k<<"\n";
    else cout<<-1<<"\n";
  }
  return 0;
}