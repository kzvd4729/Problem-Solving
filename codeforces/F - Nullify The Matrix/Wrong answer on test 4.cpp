/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2020 19:40                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1451/problem/F
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e2;
int a[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
     int f=0,x=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=min(i,m);j++)
      {
        int rw=i-j+1,cl=j;
        x^=a[rw][cl];f|=a[rw][cl];
      }
      if(f)break;
    }
    if(f)
    {
      if(x)cout<<"Ashish"<<endl;else cout<<"Jeel"<<endl;
      continue;
    }
    for(int i=2;i<=m;i++)
    {
      for(int j=i;j<=min(m,i+n-1);j++)
      {
        int rw=n-(j-i),cl=j;
        x^=a[rw][cl];f|=a[rw][cl];
      }
      if(f)break;
    }
    if(x)cout<<"Ashish"<<endl;else cout<<"Jeel"<<endl;
  }
  return 0;
}