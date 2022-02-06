/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2020 13:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 11100 KB                             
*  problem: https://codeforces.com/contest/1327/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],c[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    set<int>st;int n,id=-1;cin>>n;
    for(int i=1;i<=n;i++)st.insert(i),a[i]=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      for(int j=1;j<=x;j++)cin>>c[j];
      for(int j=1;j<=x;j++)
      {
        if(st.find(c[j])==st.end())continue;
        st.erase(c[j]);a[i]=1;break;
      }
      if(!a[i])id=i;
    }
    if(id==-1)cout<<"OPTIMAL\n";
    else cout<<"IMPROVE\n"<<id<<" "<<*st.begin()<<"\n";
  }
  return 0;
}