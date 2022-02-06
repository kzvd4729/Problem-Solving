/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2019 00:32                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 19700 KB                             
*  problem: https://codeforces.com/contest/1119/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;long ans=0;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i];
    ans+=aa[i]/3;aa[i]%=3;
  }
  set<pair<long,long> >st;
  st.insert({aa[n],n});
  for(long i=n-1;i>=1;i--)
  {
    if(aa[i]%2)
    {
      pair<long,long>p=*st.rbegin();
      if(p.first>1)
      {
        st.erase(p);st.insert({p.first-2,p.second});
        ans++;st.insert({aa[i]-1,i});
      }
      else st.insert({aa[i],i});
    }
    else st.insert({aa[i],i});
  }
  for(long i=1;i<=n;i++)
  {
    pair<long,long>p=*st.rbegin();
    st.erase(p);aa[p.second]=p.first;
  }
  int lt=1,rt=n;
  while(lt<=rt)
  {
    if(aa[rt]<2)rt--;if(aa[lt]<1)lt++;
    int mn=min(aa[lt],aa[rt]/2);
    ans+=mn;aa[lt]-=mn;aa[rt]-=mn*2;
  }
  cout<<ans<<endl;
  return 0;
}