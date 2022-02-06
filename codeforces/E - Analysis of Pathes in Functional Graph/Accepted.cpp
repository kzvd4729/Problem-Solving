/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/08/2020 12:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 560 ms                                          memory_used: 98600 KB                             
*  problem: https://codeforces.com/contest/702/problem/E
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
const int N=1e5;
long sp[N+2][40+2][3];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long k;cin>>k;
  for(int i=1;i<=n;i++)cin>>sp[i][0][0],sp[i][0][0]++;
  //memset(sp,63,sizeof sp);
  for(int i=1;i<=n;i++)
  {
    cin>>sp[i][0][1];
    sp[i][0][2]=sp[i][0][1];
  }
  for(int j=1;j<=40;j++)
  {
    for(int i=1;i<=n;i++)
    {
      int nx=sp[i][j-1][0];
      sp[i][j][0]=sp[nx][j-1][0];
      sp[i][j][1]=sp[i][j-1][1]+sp[nx][j-1][1];
      sp[i][j][2]=min(sp[i][j-1][2],sp[nx][j-1][2]);
    }
  }
  /*for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=3;j++)cout<<sp[i][j][1]<<" ";
      cout<<endl;
  }*/
  for(int i=1;i<=n;i++)
  {
    long ok=k;int nd=i;long ad=0,mn=1e9;
    for(int j=40;j>=0;j--)
    {
      if((1LL<<j)>ok)continue;
      ad+=sp[nd][j][1];mn=min(mn,sp[nd][j][2]);
      nd=sp[nd][j][0];ok-=(1LL<<j);
    }
    cout<<ad<<" "<<mn<<"\n";
  }
  return 0;
}