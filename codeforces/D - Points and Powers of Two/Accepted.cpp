/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/01/2018 22:00                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 2183 ms                                         memory_used: 10500 KB                             
*  problem: https://codeforces.com/contest/988/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int R=1e9;
const int N=2e5;
int pw[34],n;
int arr[N+2];
set<int>vis;
int a=R+1,b=R+1;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   pw[0]=1;
  for(int i=1;i<=30;i++)
    pw[i]=pw[i-1]*2;
   scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&arr[i]);
    vis.insert(arr[i]);
  }
  a=arr[1];
  for(int i=1;i<=n;i++)
  {
    for(int p=0;p<=30;p++)
    {
      int pp=pw[p];
      int f1=0,f2=0;
      if(vis.find(arr[i]+pp)!=vis.end())f1=1;
      if(vis.find(arr[i]-pp)!=vis.end())f2=1;
      if(f1&&f2)
      {
        cout<<3<<endl;
        cout<<arr[i]-pp<<" "<<arr[i]<<" "<<arr[i]+pp<<endl;
        return 0;
      }
      if(f1)
        a=arr[i],b=arr[i]+pp;
      if(f2)
        a=arr[i],b=arr[i]-pp;
    }
  }
  if(b==R+1)
  {
    cout<<1<<endl;
    cout<<a<<endl;
    return 0;
  }
  cout<<2<<endl;
  cout<<a<<" "<<b<<endl;
  return 0;
}