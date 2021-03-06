/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2019 19:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1183/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>q;
  while(q--)
  {
    int n;cin>>n;vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    reverse(v.begin(),v.end());
    int ans=v[0];n=v.size();
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        if(v[i]%v[j])
        {
          ans=max(ans,v[i]+v[j]);
          break;
        }
      }
    }
    for(int i=0;i<n;i++)
    {
      if(3*v[i]<=ans)break;
      for(int j=i+1;j<n;j++)
      {
        if(v[i]+2*v[j]<=ans)break;
        if(v[i]%v[j]==0)continue;
        for(int k=j+1;k<n;k++)
        {
          if(v[i]+v[j]+v[k]<=ans)break;
          if(v[i]%v[k]==0||v[j]%v[k]==0)continue;
          ans=v[i]+v[j]+v[k];
          break;
        }
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}