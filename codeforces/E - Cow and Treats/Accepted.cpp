/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2020 21:30                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 373 ms                                          memory_used: 98200 KB                             
*  problem: https://codeforces.com/contest/1307/problem/E
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
const int N=5e3;
int n,a[N+2],sm[N+2][N+2];
vector<int>v[N+2];
const int mod=1e9+7;
pair<int,int>cal(int md)
{
  int way=1,ret=0,sk=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<v[i].size();j++)
    {
      //cout<<sm[md][i]<<" "<<v[i][j]<<endl;
      if(a[md]==i&&sm[md][i]==v[i][j]);
      else continue;
       int cnt=0;
      for(int l=0;l<v[i].size();l++)
      {
        if(l==j)continue;
        if(v[i][l]<=sm[n][i]-sm[md][i])cnt++;
      }
      if(cnt==0)ret++;
      else ret+=2,way=cnt;
      sk=i;break;
    }
    if(sk)break;
  }
  if(sk==0&&md)return {-1,-1};
  for(int i=1;i<=n;i++)
  {
    if(v[i].size()==0||i==sk)continue;
    int now=0,lft=sm[md][i],rgt=sm[n][i]-sm[md][i];if(lft>rgt)swap(lft,rgt);
    if(v[i].size()==1)
    {
      if(v[i][0]>rgt)continue;ret++;
      if(v[i][0]<=lft)now++;
      if(v[i][0]<=rgt)now++;
       way=(1LL*way*now)%mod;
    }
    else
    {
      if(v[i][0]<=lft&&v[i][1]<=rgt)
      {
        ret+=2;int id;
        for(id=0;id<v[i].size();id++)if(v[i][id]>rgt)break;
        way=(1LL*way*(id-1))%mod;
        for(id=0;id<v[i].size();id++)if(v[i][id]>lft)break;
        way=(1LL*way*id)%mod;
      }
      else if(v[i][0]<=rgt)
      {
        ret++;int id;
        for(id=0;id<v[i].size();id++)if(v[i][id]>rgt)break;
        way=(1LL*way*id)%mod;
        for(id=0;id<v[i].size();id++)if(v[i][id]>lft)break;
        way=(1LL*way*(id+1))%mod;
      }
    }
  }
  return {ret,way};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    for(int j=1;j<=n;j++)sm[i][j]=sm[i-1][j];
    sm[i][a[i]]++;
  }
  for(int i=1;i<=m;i++)
  {
    int x,y;cin>>x>>y;
    v[x].push_back(y);
  }
  for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
   pair<int,int>ans;ans={-1,-1};
  for(int md=0;md<=n;md++)
  {
    pair<int,int>p=cal(md);
    if(ans.first==p.first)ans.second=(ans.second+p.second)%mod;
    else if(p.first>ans.first)ans=p;
  }
  //assert(ans.first>-1);
  cout<<ans.first<<" "<<ans.second<<endl;
  return 0;
}