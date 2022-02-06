/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 00:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 9500 KB                              
*  problem: https://codeforces.com/gym/101991/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>pp[N+2];
int main()
{
  freopen("icecream.in","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
      cin>>pp[i].first;
    for(int i=1;i<=n;i++)
      cin>>pp[i].second;
    sort(pp+1,pp+n+1);
    vector<pair<int,int> >v;
    int a=pp[k].first;
    for(int i=1;i<=n;i++)
    {
      if(pp[i].first<=a)
        v.push_back({pp[i].second,pp[i].first});
    }
    sort(v.begin(),v.end());
    long ans=0;
    while(k--)
    {
      ans+=v.back().first;
      v.pop_back();
    }
    cout<<a<<" "<<ans<<endl;
  }
  return 0;
}