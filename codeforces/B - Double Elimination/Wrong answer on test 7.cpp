/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/30/2020 17:22                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 23200 KB                             
*  problem: https://codeforces.com/contest/1314/problem/B
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
int a[N+2],p1[N+2],p2[N+2],v1[N+2],v2[N+2];
int makeTree1(int h)
{
  int l=1,r=1;
  for(int i=2;i<=h;i++)
  {
    int cnt=l;
    for(int j=r+1; ;j+=2)
    {
      if(cnt>r)break;
      p1[j]=cnt,p1[j+1]=cnt;
      cnt++;
    }
    int df=r-l+1;
    l=r+1;r=r+df+df;
  }
  return l;
}
int makeTree2(int h)
{
  int l=2,r=2;p2[2]=1;
  for(int i=2;i<=h;i++)
  {
    int cnt=l;
    for(int j=r+1; ;j+=2)
    {
      if(cnt>r)break;
      p2[j]=cnt,p2[j+1]=cnt;
      cnt++;
    }
    int df=r-l+1;
    l=r+1;r=r+df+df;
     cnt=l;
    for(int j=r+1; ;j++)
    {
      if(cnt>r)break;p2[j]=cnt;
      cnt++;
    }
    df=r-l+1;
    l=r+1;r=r+df;
  }
  return l;
  cout<<l<<" "<<r<<endl;
}
int cal(int i,int j)
{
  int c1=0,c2=0;int r1=i,r2=j;
  while(i)
  {
    if(v1[i]==0)c1++;
    i=p1[i];
  }
  while(j)
  {
    if(v2[j]==0)c2++;
    j=p2[j];
  }
  i=r1,j=r2;
  if(c1>c2)
  {
    while(i)
    {
      v1[i]=1;i=p1[i];
    }
    return c1;
  }
  else 
  {
    while(j)
    {
      v2[j]=1;j=p2[j];
    }
    return c2;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=k;i++)
  {
    int x;cin>>x;a[x]=1;
  }
  int x=makeTree1(n-1),y=makeTree2(n-1);//cout<<x<<" "<<y<<endl;
  int ans=1;
  for(int i=1;i<=(1<<n);i+=2)
  {
    if(a[i]||a[i+1])
    {
      ans++;
      if(a[i])ans+=cal(x,y);
      if(a[i+1])ans+=cal(x,y);
    }
    if((i+1)%4==0)x++,y++;
  }
  cout<<ans<<endl;
  return 0;
}