/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2020 11:56                        
*  solution_verdict: Wrong answer on test 16                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1332/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int mt[3+2][3+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int k;cin>>k;
  mt[1][2]=(1<<18);
  mt[2][1]=k;mt[1][1]=mt[1][2]|mt[2][1];
   mt[2][2]=mt[1][1];mt[3][3]=k;
  mt[2][3]=k,mt[3][2]=k;
   cout<<3<<" "<<3<<endl;
  for(int i=1;i<=3;i++)
  {
    for(int j=1;j<=3;j++)
      cout<<mt[i][j]<<" ";
    cout<<endl;
  }
   return 0;
}