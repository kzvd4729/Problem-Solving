/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/22/2019 12:28                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1252/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2];
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long mx=0;
  for(int i=1;i<=n;i++)
  {
   cin>>aa[i]>>bb[i];
   if(aa[i]>bb[i])swap(aa[i],bb[i]);
   pp[i]={aa[i],bb[i]};
   mx=max(mx,1LL*aa[i]*bb[i]);
  }
  sort(pp+1,pp+n+1);multiset<int>st;
  // for(int i=1;i<=n;i++)
  //  cout<<pp[i].first<<" --> "<<pp[i].second<<endl;
  for(int i=1;i<=n;i++)st.insert(-pp[i].second);
   for(int i=1;i<n;i++)
  {
   auto it=st.begin();it++;
   mx=max(mx,-2LL*pp[i].first*(*it));
    st.erase(st.find(-pp[i].second));
  }
  cout<<setprecision(1)<<fixed<<(mx/2.0)<<endl;
    return 0;
}