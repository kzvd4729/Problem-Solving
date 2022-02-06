/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/17/2019 20:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1236/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=300;
int mt[N+2][N+2],al[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      mt[i][j]=i+(j-1)*n;
  }
 //  for(int i=1;i<=n;i++)
//  {
//    for(int j=1;j<=n;j++)
//    {
//      cout<<mt[i][j]<<" ";
//    }
//    cout<<endl;
//  }
  int nn=n;
  for(int i=1;i<=n;i++)
    al[i]=nn--;
  int hl=n/2;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=hl;j++)
    {
      cout<<mt[i][j]<<" ";
    }
    for(int j=hl+1;j<=n;j++)
    {
      cout<<mt[al[i]][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}