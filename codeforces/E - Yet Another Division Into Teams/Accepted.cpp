/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/09/2019 13:01                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 311 ms                                          memory_used: 13400 KB                             
*  problem: https://codeforces.com/contest/1256/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
pair<int,int>pp[N+2];
int dp[N+2],ans[N+2],seg[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>pp[i].first;pp[i].second=i;
  }
  sort(pp+1,pp+n+1);
   set<pair<int,int> >st;
   int pt=1;dp[1]=1e9,dp[2]=1e9;
  for(int i=3;i<=n;i++)
  {
    st.insert({dp[pt-1]-pp[pt].first,pt});pt++;
     pair<int,int>p=*st.begin();
    dp[i]=p.first+pp[i].first;seg[i]=p.second;
    //cout<<p.second<<" --> "<<i<<endl;
  }
  pt=n;
  while(pt)
  {
    for(int i=seg[pt];i<=pt;i++)
      ans[pp[i].second]=pt;
    pt=seg[pt]-1;
  }
  vector<int>v;
  for(int i=1;i<=n;i++)
    v.push_back(ans[i]);
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   int cnt=0;map<int,int>mp;
  for(auto x:v)mp[x]=++cnt;
  cout<<dp[n]<<" "<<cnt<<endl;
  for(int i=1;i<=n;i++)
    cout<<mp[ans[i]]<<" ";
  cout<<endl;
  return 0;
}