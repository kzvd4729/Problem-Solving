/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2020 17:25                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++17                               
*  run_time: 4000 ms                                         memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/1366/problem/G
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
const int N=1e4;
string a,b;
int c[N+2],cs[N+2],rm[N+2];
int dfs(int i,int j,int d)
{
  if(i<0&&j<0)return d;
  if(i<0)return N+1;
  if(j<0)return cs[i]+max(rm[i],d)-min(rm[i],d);
   int ret=N+1,ex=c[i],nx=i-1-c[i];
   if(a[i]==b[j])ret=min(ret,d+dfs(nx,j-1,ex));
  if(d)ret=min(ret,dfs(nx,j,d-1+ex));
  else ret=min(ret,1+dfs(nx,j,ex));
   return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b;
   for(int i=a.size()-1;i>=0;i--)
  {
    if(a[i]=='.')continue;int cnt=0;
    for(int j=i-1;j>=0;j--)
    {
      if(a[j]=='.')cnt++;
      else break;
    }
    c[i]=cnt;
  }
  int sz=0,ex=0;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]=='.')
    {
      if(sz)sz--;else ex++;
    }
    else
    {
      sz++;
      rm[i]=sz,cs[i]=ex;
    }
  }
  //for(int i=0;i<a.size();i++)cout<<c[i];cout<<endl;
  int id,cnt=0;
  for(int i=a.size()-1;i>=0;i--)
  {
    if(a[i]=='.')cnt++;
    else {id=i;break;}
  }
  cout<<dfs(id,b.size()-1,cnt)<<endl;
   return 0;
}