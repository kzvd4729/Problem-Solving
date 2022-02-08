/****************************************************************************************
*  @author: kzvd4729                                         created: 06-07-2019 12:04:23                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/JULY19A/problems/CIRMERGE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<long>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    long ans=0;
    while(n>1)
    {
      long mn=1e15;int id;
      for(int i=0;i<n;i++)
      {
        if(v[i]+v[(i+1)%n]<mn)
        {
          mn=v[i]+v[(i+1)%n];
          id=i;
        }
      }
      v[id]=mn;
      ans+=mn;v.erase(v.begin()+(id+1)%n);
      n--;
    }
    cout<<ans<<endl;
  }
  return 0;
}