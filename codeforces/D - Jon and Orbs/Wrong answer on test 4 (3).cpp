/****************************************************************************************
*  @author: kzvd4729                                         created: May/01/2020 19:56                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 70700 KB                             
*  problem: https://codeforces.com/contest/768/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
double dp[3000+2][3000+2];
const double eps=1e-7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   dp[1][1]=1;
  for(int d=2;d<=3000;d++)
  {
    for(int i=1;i<=d;i++)
    {
      dp[d][i]=dp[d-1][i]*((i*1.0)/(d*1.0))+dp[d-1][i-1]*(((d-i+1)*1.0)/(d*1.0));
    }
  }
  for(int d=1;d<=3000;d++)
  {
    for(int i=d;i>=1;i--)
      dp[d][i]+=dp[d][i+1];
  }
  cout<<setprecision(3)<<fixed;
  /*for(int i=1;i<=5;i++)
  {
    for(int j=1;j<=i;j++)cout<<dp[i][j]<<" ";
      cout<<endl;
  }*/
  int k,q;cin>>k>>q;
  while(q--)
  {
    double p;cin>>p;p=p/2000.0;
    int d;
    for(d=1; ;d++)
      if(dp[d][k]-eps>=p)break;
    cout<<d<<"\n";
  }
  return 0;
}