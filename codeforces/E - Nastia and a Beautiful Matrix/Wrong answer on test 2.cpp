/****************************************************************************************
*  @author: kzvd4729                                         created: May/08/2021 00:01                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 19900 KB                             
*  problem: https://codeforces.com/contest/1521/problem/E
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
 pair<int,int>p[N+2],tmp[N+2];
int m,k;
 bool isOk(int i,int j,int x,vector<vector<int> >&v)
{
  if(v[i-1][j-1]==x)return false;
  if(v[i+1][j-1]==x)return false;
  if(v[i-1][j+1]==x)return false;
  if(v[i+1][j+1]==x)return false;
   return true;
}
 int nxt(int pt)
{
  while(pt<=k)
  {
    if(tmp[pt].first==0)pt++;
    else break;
  }
  return pt;
}
 bool ck(int n)
{
  if(n*n<m)return false;
   vector<pair<int,int> >bad,good;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if((i+j)%2)bad.push_back({i,j});
      else if(i%2)good.push_back({i,j});
    }
  }
  vector<vector<int> >v(n+4,vector<int>(n+4,0));
   int pt=1;
  for(int i=1;i<=k;i++)tmp[i]=p[i];
  for(int i=1;i<=n;i+=2)
  {
    for(int j=2;j<=n;j+=2)
    {
      pt=nxt(pt);
      if(pt<=k)v[i][j]=tmp[pt].second,tmp[pt].first--;
    }
  }
   pt=1;
  for(int i=2;i<=n;i+=2)
  {
    for(int j=1;j<=n;j+=2)
    {
      pt=nxt(pt);if(pt>k)continue;
            while(pt<=k)
      {
        if(isOk(i,j,tmp[pt].second,v))
        {
          v[i][j]=tmp[pt].second;
          tmp[pt].first--;
          break;
        }
        else pt++;
      }
    }
  }
  for(int i=1;i<=k;i++)
  {
    int x=tmp[i].first;
    while(x--)
    {
      if((int)good.size()==0)return false;
       pair<int,int>p=good.back();good.pop_back();
      v[p.first][p.second]=tmp[i].second;
    }
  }
   cout<<n<<'\n';
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      cout<<v[i][j]<<" ";
    cout<<'\n';
  }
   return true;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    cin>>m>>k;
    for(int i=1;i<=k;i++)cin>>p[i].first,p[i].second=i;
     sort(p+1,p+k+1,greater<pair<int,int> >());
     for(int i=1; ;i++)if(ck(i))break;
   }
  return 0;
}