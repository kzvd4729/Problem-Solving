/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-02-03 20:00:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 109                                        memory_used (MB): 3.2                             
*  problem: https://vjudge.net/problem/HDU-1506
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9;

int a[N+2],lft[N+2],rgt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  while(true)
  {
    int n;cin>>n;
    if(n==0)break;

    for(int i=1;i<=n;i++)cin>>a[i];

    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;

    stack<pair<int,int> >st;
    st.push({-inf,0});

    for(int i=1;i<=n;i++)
    {
      while(st.top().first>=a[i])st.pop();
      lft[i]=st.top().second+1;

      st.push({a[i],i});
    }

    while((int)st.size())st.pop();
    st.push({-inf,n+1});

    for(int i=n;i>=1;i--)
    {
      while(st.top().first>=a[i])st.pop();
      rgt[i]=st.top().second-1;

      st.push({a[i],i});
    }
    long ans=0;
    for(int i=1;i<=n;i++)
      ans=max(ans,1LL*(rgt[i]-lft[i]+1)*a[i]);
    cout<<ans<<endl;

  }
  return 0;
}