/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2021 13:26:39                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.12 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/APRIL21A/problems/KAVGMAT
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
const int N=1e6,inf=1e9,mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;
    vector<vector<long> >a(n+2);a[0].resize(m+2);
    for(int i=1;i<=n;i++)
    {
      a[i].resize(m+2);
      for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)a[i][j]+=a[i][j-1];
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)a[i][j]+=a[i-1][j];
    }
    // for(int i=1;i<=n;i++)
    // {
    //   for(int j=1;j<=m;j++)cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        int lo=0,hi=min(n-i,m-j),md;
        while(hi-lo>2)
        {
          md=(lo+hi)/2;
          int ii=i+md,jj=j+md;
          long sm=a[ii][jj]-a[ii][j-1]-a[i-1][jj]+a[i-1][j-1];
          if(sm>=1LL*k*(md+1)*(md+1))hi=md;
          else lo=md;
        }
        for(md=lo;md<=hi;md++)
        {
          int ii=i+md,jj=j+md;
          long sm=a[ii][jj]-a[ii][j-1]-a[i-1][jj]+a[i-1][j-1];
          if(sm>=1LL*k*(md+1)*(md+1))break;
        }
        ans+=min(n-i,m-j)-md+1;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}