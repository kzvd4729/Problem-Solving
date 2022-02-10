/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-25 16:02:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 10                                         memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-ADDREV
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,a,b,c;
int rev(int x)
{
  int ret=0;
  while(x)
  {
    int r=x%10;
    ret=ret*10+r;
    x/=10;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>a>>b;

    c=rev(a)+rev(b);

    cout<<rev(c)<<endl;

  }
  return 0;
}