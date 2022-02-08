/****************************************************************************************
*  @author: kzvd4729                                         created: 08-10-2019 12:01:53                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 19.5M                                
*  problem: https://www.codechef.com/OCT19A/problems/MARM
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
    int n;long k;cin>>n>>k;
    for(int i=0;i<n;i++)cin>>aa[i];
    if(n%2&&k>n/2)aa[n/2]=0;
    k=k%(3*n);
    for(int i=0;i<k;i++)
    {
      int a=i%n,b=n-(i%n)-1;
      aa[a]^=aa[b];
    }
    for(int i=0;i<n;i++)
    {
      if(i)cout<<" ";
      cout<<aa[i];
    }
    cout<<endl;
  }
  return 0;
}