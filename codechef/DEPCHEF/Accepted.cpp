/****************************************************************************************
*  @author: kzvd4729                                         created: 01-02-2019 15:39:48                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/FEB19B/problems/DEPCHEF
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
    int n;cin>>n;vector<int>aa(n+2),dd(n+2);
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)cin>>dd[i];
    aa[n+1]=aa[1];dd[n+1]=dd[1];
    aa[0]=aa[n];dd[0]=dd[n];int ans=-1;
    for(int i=1;i<=n;i++)
    {
      if(dd[i]>aa[i+1]+aa[i-1])
        ans=max(ans,dd[i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}