/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/07/2020 22:49                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1365/problem/A
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=50;
int a[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    memset(a,0,sizeof a);
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(a[i][j]==0)cnt++;
        //if(a[i][j]|a[i][j+1]|a[i][j-1]|a[i+1][j]|a[i-1][j])continue;
        //a[i][j]=1;cnt++;
      }
    }
    if(cnt%2)cout<<"Ashish"<<endl;
    else cout<<"Vivek"<<endl;
  }
   return 0;
}