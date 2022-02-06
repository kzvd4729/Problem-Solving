/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2019 21:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1208/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int cnt=0;
   for(int i=1;i<=n;i+=4)
  {
    for(int j=1;j<=n;j+=4)
    {
      for(int ii=i;ii<i+4;ii++)
      {
        for(int jj=j;jj<j+4;jj++)
        {
          mt[ii][jj]=cnt++;
        }
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout<<mt[i][j]<<" ";
    }
    cout<<endl;
  }
  /*for(int j=1;j<=n;j++)
  {
    int xxr=0;
    for(int i=1;i<=n;i++)
    {
      xxr^=mt[i][j];
    }
    cout<<xxr<<endl;
  }*/
  return 0;
}