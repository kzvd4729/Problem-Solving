/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 21:06:25                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12463
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long a,b,c,d,e;
  while(cin>>a>>b>>c>>d>>e)
  {
    if(!(a+b+c+d+e))break;
    long ans=a*b*c*d*d*e*e;
    cout<<ans<<endl;
  }
  return 0;
}