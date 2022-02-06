/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/08/2019 20:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1238/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,r;cin>>n>>r;vector<int>aa(n);
    for(int i=0;i<n;i++)cin>>aa[i];
    sort(aa.begin(),aa.end());
    aa.erase(unique(aa.begin(),aa.end()),aa.end());
     int ans=0,ad=0;
    for(int i=aa.size()-1;i>=0;i--)
    {
      if(aa[i]-ad<=0)break;
      ans++;ad+=r;
      //cout<<"*"<<ad<<endl;
    }
    cout<<ans<<"\n";
  }
  return 0;
}