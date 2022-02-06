/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/08/2019 19:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/710/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int mat[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  int rw=1;
  for(int i=1;i<=n;i+=2)
  {
    for(int j=(n-i)/2+1;j<(n-i)/2+1+i;j++)
    {
      mat[rw][j]=1;
    }
    rw++;
  }
  for(int i=n-2;i>=1;i-=2)
  {
    for(int j=(n-i)/2+1;j<(n-i)/2+1+i;j++)
    {
      mat[rw][j]=1;
    }
    rw++;
  }
  int od=1,ev=2;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(mat[i][j])
      {
        cout<<od<<" ";
        od+=2;
      }
      else
      {
        cout<<ev<<" ";
        ev+=2;
      }
    }
    cout<<endl;
  }
  return 0;
}