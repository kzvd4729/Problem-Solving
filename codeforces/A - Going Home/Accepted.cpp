/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2021 15:55                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 77 ms                                           memory_used: 59500 KB                             
*  problem: https://codeforces.com/contest/1500/problem/A
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
const int N=3e6,inf=1e9,mod=1e9+7;
 int a[200000+2],fr[N+2];
pair<int,int>ans[N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;int M=0;
  for(int i=1;i<=n;i++)cin>>a[i],fr[a[i]]++,M=max(M,a[i]);
   int vl=-1;
  for(int i=1;i<=M;i++)
  {
    if(fr[i]>=4)vl=i;
  }
   if(vl!=-1)
  {
    cout<<"YES"<<endl;
    int cnt=4;
    for(int i=1;i<=n;i++)
    {
      if(a[i]==vl && cnt)
      {
        cnt--;cout<<i<<" ";
      }
    }
    cout<<endl;exit(0);
  }
   int vl1=-1,vl2=-1;
  for(int i=1;i<=M;i++)
  {
    if(fr[i]>=2)
    {
      if(vl1==-1)vl1=i;
      else vl2=i;
    }
  }
    if(vl2!=-1)
  {
    cout<<"YES"<<endl;
    int cnt=2;
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
      if(a[i]==vl1&&cnt)
      {
        cnt--;v.push_back(i);
      }
    }
    cnt=2;
    for(int i=1;i<=n;i++)
    {
      if(a[i]==vl2&&cnt)
      {
        cnt--;v.push_back(i);
      }
    }
    cout<<v[0]<<" "<<v[2]<<" "<<v[1]<<" "<<v[3];
    cout<<endl;exit(0);
  }
   if(vl1!=-1)
  {
    int id=-1;
    for(int i=1;i<=n;i++)
    {
      if(a[i]==vl1)continue;
      if(vl1*2-a[i]>0 && vl1*2-a[i]<=N && fr[vl1*2-a[i]])id=i;
    }
    if(id!=-1)
    {
      cout<<"YES"<<endl;
      int cnt=2;
      for(int i=1;i<=n;i++)
      {
        if(a[i]==vl1&&cnt)
        {
          cnt--;cout<<i<<" ";
        }
      }
      cout<<id<<" ";
      for(int i=1;i<=n;i++)
      {
        if(a[i]==vl1*2-a[id])
        {
          cout<<i<<endl,exit(0);
        }
      }
    }
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
      if(a[i]==vl1 && cnt)cnt--;
      else if(a[i]==vl1 && cnt==0)a[i]=-1;
    }
  }
  for(int i=1;i<=M+M;i++)ans[i]={-1,-1};
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(a[i]==-1||a[j]==-1)continue;
      int sm=a[i]+a[j];
       if(ans[sm].first!=-1)
      {
        cout<<"YES"<<endl;
        cout<<ans[sm].first<<" "<<ans[sm].second<<" "<<i<<" "<<j<<endl;
        exit(0);
      }
      ans[sm]={i,j};
    }
  }
  cout<<"NO"<<endl;
  return 0;
}