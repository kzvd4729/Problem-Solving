/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-10 15:53:55                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10173
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cout<<setprecision(4)<<fixed;

  int n;
  while(cin>>n)
  {
    if(!n)break;
    double lft=1e9,rgt=-1e9,up=-1e9,dw=1e9;
    for(int i=1;i<=n;i++)
    {
      double x,y;cin>>x>>y;
      lft=min(lft,x);rgt=max(rgt,x);
      dw=min(dw,y);up=max(up,y);
    }
    cout<<(rgt-lft)*(up-dw)<<endl;
  }
  return 0;
}