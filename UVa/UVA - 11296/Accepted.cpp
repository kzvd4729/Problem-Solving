/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 20:01:21                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11296
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;
  while(cin>>n)
  {
    n=n/2+1;
    n=(n*(n+1))/2;
    cout<<n<<endl;
  }
  return 0;
}