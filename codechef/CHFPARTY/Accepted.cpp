/****************************************************************************************
*  @author: kzvd4729                                         created: 17-02-2019 21:36:46                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.08 sec                                        memory_used: 19.5M                                
*  problem: https://www.codechef.com/COOK103A/problems/CHFPARTY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    sort(aa+1,aa+n+1);int in=0;
    for(int i=1;i<=n;i++)
      if(in>=aa[i])in++;
    cout<<in<<endl;
  }
  return 0;
}