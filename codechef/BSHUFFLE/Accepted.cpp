/****************************************************************************************
*  @author: kzvd4729                                         created: 07-09-2018 19:34:33                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/SEPT18A/problems/BSHUFFLE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  int d=n/2-1;
  for(int i=2;i<2+d;i++)
    cout<<i<<" ";
  cout<<1<<" ";
  for(int i=2+d+1;i<=n;i++)
    cout<<i<<" ";
  cout<<2+d<<endl;
  cout<<n<<" ";
  for(int i=1;i<n;i++)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}