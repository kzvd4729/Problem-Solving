/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2021 21:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 6100 KB                              
*  problem: https://codeforces.com/contest/1479/problem/B1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int a[N+2],ans,p;
set<int>st;
void add(int x,int f)
{
  if(p==-1)
  {
    p=x;
    if(f==1)st.insert(-1);else st.insert(x);
    if(f==1)ans=1;else ans=2;
     return;
  }
  if(x==p)assert(0);
  if(f==1)
  {
    ans++;
    if(((int)st.size()>1)||(st.find(x)==st.end()))
      st.insert(p);
  }
  else
  {
    if(((int)st.size()>1)||(st.find(x)==st.end()))
    {
      st.clear();
      ans+=2;st.insert(x);
    }
    else
    {
      ans++;
    }
  }
  p=x;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;p=-1;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  int cnt=1;
  for(int i=2;i<=n;i++)
  {
    if(a[i]==a[i-1])cnt++;
    else
    {
      add(a[i-1],cnt);
      cnt=1;
    }
  }
  add(a[n],cnt);
  cout<<ans<<endl;
   return 0;
}