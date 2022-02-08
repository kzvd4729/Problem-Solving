/****************************************************************************************
*  @author: kzvd4729                                         created: 01-02-2019 15:53:09                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 18.5M                                
*  problem: https://www.codechef.com/FEB19B/problems/ARTBALAN
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
    string s;cin>>s;vector<int>cnt(26,0);
    for(auto x:s)cnt[x-'A']++;int n=s.size();
    sort(cnt.begin(),cnt.end());int ans=1e9;
    reverse(cnt.begin(),cnt.end());
    for(int i=1;i<=26;i++)
    {
      if(n%i)continue;int rq=n/i;int sum=0;
      for(int j=0;j<i;j++)
        sum+=min(cnt[j],rq);
      ans=min(ans,n-sum);
    }
    cout<<ans<<"\n";
  }
  return 0;
}