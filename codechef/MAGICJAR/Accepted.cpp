/****************************************************************************************
*  @author: kzvd4729                                         created: 01-02-2019 16:20:45                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/FEB19B/problems/MAGICJAR
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
    int n;cin>>n;long sum=0;
    for(int i=1;i<=n;i++)
    {
      long x;cin>>x;sum+=(x-1);
    }
    cout<<sum+1<<"\n";
  }
  return 0;
}