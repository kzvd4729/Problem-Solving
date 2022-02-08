/****************************************************************************************
*  @author: kzvd4729                                         created: 01-03-2019 20:28:35                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/MARCH19A/problems/SUBPRNJL
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int aa[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;int ans=0;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)
    {
      int mx=-1;memset(fr,0,sizeof(fr));
      for(int j=i;j<=n;j++)
      {
        fr[aa[j]]++;
        mx=max(mx,aa[j]);int ln=(j-i+1);
        int m=(k+ln-1)/ln;
        int oc=fr[mx];
        if(fr[oc])
        {
          ans++;
          //cout<<i<<" "<<j<<endl;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}