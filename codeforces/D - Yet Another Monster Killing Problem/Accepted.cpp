/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2019 22:43                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 280 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1257/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2];
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,mx=0;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i],mx=max(mx,aa[i]);
    int m,f=0;cin>>m;
    for(int i=1;i<=m;i++)
    {
      cin>>pp[i].first>>pp[i].second;
      if(pp[i].first>=mx)f=1;
    }
    if(!f){cout<<-1<<endl;continue;}
    sort(pp+1,pp+m+1);
     vector<pair<int,int> >v;
    v.push_back(pp[m]);
    for(int i=m-1;i>=1;i--)
    {
      if(pp[i].second>v.back().second)
        v.push_back(pp[i]);
    }
    reverse(v.begin(),v.end());
     int cnt=0,ans=0,pt;mx=0;
    for(int i=1;i<=n;i++)
    {
      mx=max(mx,aa[i]);cnt++;
      pt=lower_bound(v.begin(),v.end(),make_pair(mx,-1))-v.begin();
      if(v[pt].second<cnt)
      {
        ans++,cnt=0,mx=0;
        i--;
      }
    }
    cout<<ans+1<<"\n";
  }
  return 0;
}