/****************************************************************************************
*  @author: kzvd4729                                         created: 28-07-2021 22:00:04                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK131A/problems/MATBEAUT
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
const int N=1e2,inf=1e9,mod=1e9+7;
int a[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    vector<vector<int> >v;
    for(int c=1;c<m;c++)
    {
      for(int r=1;r<n;r++)
      {
        if(a[r][c]==r)continue;
        int id=-1;
        for(int i=r+1;i<=n;i++)if(a[i][c]==r)id=i;
        if(id==-1)assert(0);
        v.push_back({r,c,id,c+1});
        swap(a[r][c],a[id][c]);
        swap(a[r][c+1],a[id][c+1]);
      }
    }
    int f=0;
    for(int r=1;r<=n;r++)
    {
      for(int c=1;c<=m;c++)if(a[r][c]!=r)f=1;
    }
    if(f)cout<<-1<<endl;
    else
    {
      cout<<v.size()<<endl;
      for(auto x:v)cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<endl;
    }
  }
  return 0;
}