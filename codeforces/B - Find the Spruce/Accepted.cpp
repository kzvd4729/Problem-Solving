/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/11/2020 20:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 1500 KB                              
*  problem: https://codeforces.com/contest/1461/problem/B
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
const int N=500;
int ln[N+2][N+2];
string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
     for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(s[i][j]=='.')ln[i][j]=0;
        else
        {
          int k;
          for(k=j+1;k<m;k++)if(s[i][k]=='.')break;
          k--;
          for(int l=j;l<=k;l++)ln[i][l]=min(l-j,k-l)+1;
          j=k;
        }
      }
    }
    /*for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)cout<<ln[i][j]<<" ";
        cout<<endl;
    }*/
    int ans=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        int mn=min(ln[i][j],i+1);
        for(int k=i-1;k>=0;k--)
          mn=min(mn,ln[k][j]+i-k);
        ans+=mn;
      }
    }
    cout<<ans<<" ";
  }
  return 0;
}