/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/28/2020 15:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1426/problem/E
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
const int N=1e6,mod=1e9+7;
int a[10+2],b[10+2];
int dfs(int a,int b,int c,int x,int y,int z)
{
  int f=0,mn,ret=mod;
   mn=min(a,x);
  if(mn)
  {
    f=1;
    ret=min(ret,dfs(a-mn,b,c,x-mn,y,z));
  }
   mn=min(a,z);
  if(mn)
  {
    f=1;
    ret=min(ret,dfs(a-mn,b,c,x,y,z-mn));
  }
   mn=min(b,x);
  if(mn)
  {
    f=1;
    ret=min(ret,dfs(a,b-mn,c,x-mn,y,z));
  }
   mn=min(b,y);
  if(mn)
  {
    f=1;
    ret=min(ret,dfs(a,b-mn,c,x,y-mn,z));
  }
   mn=min(c,y);
  if(mn)
  {
    f=1;
    ret=min(ret,dfs(a,b,c-mn,x,y-mn,z));
  }
   mn=min(c,z);
  if(mn)
  {
    f=1;
    ret=min(ret,dfs(a,b,c-mn,x,y,z-mn));
  }
   if(f==0)return a+b+c;
  else return ret;
}
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<3;i++)cin>>a[i];
  for(int i=0;i<3;i++)cin>>b[i];
   int mn=0,mx=0;
  for(int i=0;i<3;i++)
    mx+=min(a[i],b[(i+1)%3]);
   cout<<dfs(a[0],a[1],a[2],b[0],b[1],b[2])<<" "<<mx<<endl;
   return 0;
}