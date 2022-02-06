/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/09/2019 17:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 11100 KB                             
*  problem: https://codeforces.com/contest/1106/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],cc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    cin>>cc[i];st.insert({cc[i],i});
  }
  while(m--)
  {
    int ty,dj;cin>>ty>>dj;long sum=0;
    int x=min(aa[ty],dj);sum+=(x*1LL)*cc[ty];
    dj-=x;aa[ty]-=x;
    while(dj)
    {
      if(st.size()==0)break;
      pair<int,int>p=*st.begin();
      int x=min(aa[p.second],dj);sum+=(x*1LL)*cc[p.second];
      dj-=x;aa[p.second]-=x;
      if(aa[p.second]==0)st.erase(p);
    }
    if(!dj)cout<<sum<<"\n";
    else cout<<0<<"\n";
  }
  return 0;
}