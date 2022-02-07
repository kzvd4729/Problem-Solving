/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-10 16:01:35                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10173
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-9;
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
    double one=rgt-lft,two=up-dw;
    if(fabs(one<=eps))one=1.0;
    if(fabs(two<=eps))two=1.0;
    cout<<one*two<<endl;
  }
  return 0;
}