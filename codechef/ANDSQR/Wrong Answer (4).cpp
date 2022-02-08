/****************************************************************************************
*  @author: kzvd4729                                         created: 16-09-2018 20:46:10                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/SEPT18A/problems/ANDSQR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int arr[N+2];
map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<=45000;i++)mp[i*i]=1;
  int t;cin>>t;
  while(t--)
  {
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];
    }
    while(q--)
    {
      int l,r;cin>>l>>r;int ans=0;
      for(int i=l;i<=r;i++)
      {
        int tmp=arr[i];
        for(int j=i;j<=r;j++)
        {
          tmp=(tmp&arr[j]);
          if((sqrt(tmp)*sqrt(tmp))==tmp)ans++;
        }
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}