/****************************************************************************************
*  @author: kzvd4729                                         created: 10-03-2021 01:31:26                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.18 sec                                        memory_used: 22.6M                                
*  problem: https://www.codechef.com/MARCH21A/problems/CONSADD
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e3,inf=1e9,mod=1e9+7;
long a[N+2][N+2],qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,x;cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        int x;cin>>x;
        a[i][j]-=x;
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m+1;j++)qm[j]=0;
      for(int j=1;j<=m;j++)
      {
        qm[j]+=qm[j-1];
        a[i][j]+=qm[j];
        if(j+x-1>m)continue;
        qm[j]-=a[i][j],qm[j+x]+=a[i][j];
        a[i][j]=0;
      }
    }
    for(int j=1;j<=m;j++)
    {
      for(int i=1;i<=n+1;i++)qm[i]=0;
      for(int i=1;i<=n;i++)
      {
        qm[i]+=qm[i-1];
        a[i][j]+=qm[i];
        if(i+x-1>n)continue;
        qm[i]-=a[i][j],qm[i+x]+=a[i][j];
        a[i][j]=0;
      }
    }
    int f=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)if(a[i][j]!=0)f=0;
    }
    if(f)cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
  }
  return 0;
}