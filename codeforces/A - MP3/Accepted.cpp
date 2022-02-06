/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/02/2019 09:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 717 ms                                          memory_used: 17700 KB                             
*  problem: https://codeforces.com/contest/1198/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
map<int,int>fr;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,b,k;cin>>n>>b;b*=8;vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i],fr[v[i]]++;
  sort(v.begin(),v.end());
  for(k=0;k<=20;k++)
    if(n*(k+1)>b)break;
  k=(1<<k);
  set<int>st;int pt=0,ans=1e9;
  for(int i=0;i<n;i++)
  {
    while(pt<n)
    {
      st.insert(v[pt]);
      if(st.size()>k)
      {
        st.erase(v[pt]);
        break;
      }
      else pt++;
    }
    ans=min(ans,n-(pt-i));
    fr[v[i]]--;
    if(!fr[v[i]])st.erase(v[i]);
  }
  cout<<ans<<endl;
  return 0;
}