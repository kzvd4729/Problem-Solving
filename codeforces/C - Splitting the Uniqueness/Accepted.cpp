/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/24/2020 18:14                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 186 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/297/problem/C
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
const int N=1e6;
pair<int,int>pp[N+2];
int a[N+2],b[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n;cin>>n;cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)cin>>pp[i].first,pp[i].second=i;
  sort(pp+1,pp+n+1);

  //for(int i=1;i<=n;i++)cout<<pp[i].first<<" ";cout<<endl;

  int sg=(n+2)/3;
  for(int i=1;i<=sg;i++)
  {
    a[pp[i].second]=pp[i].first;
    b[pp[i].second]=0;

    vis[i]=1;
  }
  for(int i=n;i>=1;i-=2)
  {
    if(vis[i])continue;vis[i]=1;

    b[pp[i].second]=pp[i].first;
    a[pp[i].second]=0;
  }
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    b[pp[i].second]=cnt;
    a[pp[i].second]=pp[i].first-cnt;cnt++;
  }
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
  return 0;
}