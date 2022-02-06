/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/04/2020 18:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/1284/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int ascent=0;vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;int mn=inf,mx=0,f=0;
    while(x--)
    {
      int z;cin>>z;if(z>mn)f=1;
      mx=max(mx,z),mn=min(mn,z);
    }
    if(f)ascent++;
    else v.push_back({mn,mx});
  }
  long ans=1LL*ascent*ascent+2LL*ascent*(n-ascent);
   sort(v.begin(),v.end());
  vector<int>tmp;
  for(auto x:v)tmp.push_back(x.second);
  sort(tmp.begin(),tmp.end());
   for(auto x:v)
  {
    int id=upper_bound(tmp.begin(),tmp.end(),x.first)-tmp.begin();
    ans+=((tmp.size()-id)*1LL);
  }
  cout<<ans<<endl;
  return 0;
}