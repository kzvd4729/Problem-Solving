/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/04/2020 18:39                        
*  solution_verdict: Wrong answer on test 15                 language: GNU C++17                               
*  run_time: 93 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1261/problem/E
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
const int N=1e3+10;
int a[N+2],r,c;
bitset<N+8>bt[N+8];
void print()
{
  //cout<<r<<" "<<c<<endl;
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)cout<<bt[i][j];
      cout<<"\n";
  }
  exit(0);
}
bool ck(int j)
{
  /*for(int i=0;i<r;i++)
  {
    if(i==j)continue;
    if(bt[i]==bt[j])return false;
  }
  return true;*/
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<r;j++)
    {
      if(i==j)continue;
      if(bt[i]==bt[j])return false;
    }
  }return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int mx=0;
  for(int i=0;i<n;i++)cin>>a[i],mx=max(mx,a[i]);
   cout<<++mx<<endl;
  for(int c=0;c<n;c++)
  {
    for(int i=c+1;i<mx+mx+mx;i++)
    {
      if(a[c])bt[i%mx][c]=1,a[c]--;
    }
  }
  //for(int c=0;c<n;c++)cout<<a[c]<<" ";cout<<endl;
  /*for(int i=0;i<mx;i++)
  {
    for(int j=0;j<n;j++)cout<<bt[i][j];
      cout<<endl;
  }*/
  for(int i=0;i<mx-1;i++)
  {
    for(int j=i+1;j<mx-1;j++)if(bt[i]==bt[j])assert(0);
  }
  r=mx,c=n;int f=0;
  for(int i=0;i<mx-1;i++)
  {
    if(bt[i]==bt[mx-1])f=1;
  }
  if(ck(0))print();
   for(int i=0;i<mx-1;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(bt[i][j]!=bt[mx-1][j])
      {
        bool x=bt[i][j],y=bt[mx-1][j];
        bt[i][j]=y;bt[mx-1][j]=x;
        if(ck(mx-1)&&ck(i))print();
        bt[i][j]=x;bt[mx-1][j]=y;
      }
    }
  }
  assert(0);
    return 0;
}