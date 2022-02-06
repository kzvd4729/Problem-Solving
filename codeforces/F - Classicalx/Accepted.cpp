/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2020 23:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 935 ms                                          memory_used: 81600 KB                             
*  problem: https://codeforces.com/contest/1285/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
int mb[N+2],vis[N+2];
void mobius()
{
  for(int i=1;i<=N;i++)mb[i]=1;
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      mb[j]*=-1;vis[j]=1;
      if(i<=30000&&(j%(i*i)==0))mb[j]=0;
    }
  }
}
vector<int>vv[N+2];
void divisors(void)
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
      vv[j].push_back(i);
  }
}
vector<int>ok[N+2];int cnt[N+2];
void upd(int z,int s)
{
  for(auto x:vv[z])
    cnt[x]+=s;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   mobius();divisors();
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int z;cin>>z;
    for(auto x:vv[z])ok[x].push_back(z/x);
  }
  long ans=0;
  for(int i=1;i<=N;i++)
  {
    stack<int>st;
    sort(ok[i].begin(),ok[i].end(),greater<int>());
    for(auto z:ok[i])
    {
      int coPrime=0;
      for(auto x:vv[z])coPrime+=(mb[x]*cnt[x]);
      if(coPrime==0)upd(z,1),st.push(z);
      while(coPrime)
      {
        if(__gcd(st.top(),z)==1)
        {
          ans=max(ans,1LL*st.top()*z*i);
          coPrime--;
        }
        upd(st.top(),-1);st.pop();
      }
    }
    while(st.size())
      upd(st.top(),-1),st.pop();
  }
  cout<<ans<<endl;
  return 0;
}