/****************************************************************************************
*  @author: kzvd4729                                         created: 08-10-2019 11:40:32                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.20 sec                                        memory_used: 18.7M                                
*  problem: https://www.codechef.com/OCT19A/problems/MSV
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int mx[N+2];
vector<int>v;
void divisors(int x)
{
  v.clear();int sq=sqrt(x+1);
  for(int i=1;i<=sq;i++)
  {
    if(x%i==0)
    {
      v.push_back(i);
      if(i!=x/i)v.push_back(x/i);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int ans=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;divisors(x);
      ans=max(ans,mx[x]);
      for(auto a:v)mx[a]++;
    }
    cout<<ans<<"\n";memset(mx,0,sizeof(mx));
  }
  return 0;
}