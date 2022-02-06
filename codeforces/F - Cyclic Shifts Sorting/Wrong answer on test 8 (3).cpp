/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/03/2020 16:02                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 600 KB                               
*  problem: https://codeforces.com/contest/1374/problem/F
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
const int N=5e2;
int a[N+2],n;
void print(vector<int>ans)
{
  for(int i=2;i<=n;i++)if(a[i]<a[i-1])assert(0);
  assert(ans.size()<=n*n);
  cout<<ans.size()<<"\n";
  for(auto x:ans)
    cout<<x<<" ";cout<<"\n";
}
void doIt(int i)
{
  swap(a[i],a[i+2]);swap(a[i+1],a[i+2]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>ans;
    while(true)//normalize
    {
      int f=0;
      for(int i=3;i<=n;i++)
      {
        if(a[i]<a[i-1]&&a[i]<a[i-2])
        {
          f=1;ans.push_back(i-2);
          doIt(i-2);
        }
      }
      if(f==0)break;
    }
    while(true)//pair
    {
      int f=0;
      for(int i=1;i<=n-2;i++)
      {
        if(a[i+1]<a[i])
        {
          f=1;ans.push_back(i);ans.push_back(i);
          doIt(i);doIt(i);
        }
      }
      if(f==0)break;
    }
    for(int i=2;i<=n-1;i++)if(a[i]<a[i-1])assert(0);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    if(a[n]<a[n-1])
    {
      if(a[n]==a[n-2])
      {
        ans.push_back(n-2);doIt(n-2);
        print(ans);
      }
      else
      {
        int f=0;
        for(int i=n-2;i>=2;i--)
        {
          if(a[i]==a[i-1]){f=i-1;break;}
        }
        if(f)
        {
          int g=0;
          for(int i=n-3;i>=f;i-=2)
          {
            doIt(i);ans.push_back(i);
            if(i==f)g=1;
          }
          ans.push_back(f);doIt(f);
          //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
          int in=f+2;if(g)in=f+1;
          for(int i=in;i<=n-2;i+=2)
          {
            //cout<<'*'<<i<<endl;
            doIt(i);doIt(i);
            ans.push_back(i);ans.push_back(i);
          }
          print(ans);
        }
        else cout<<-1<<"\n";
      }
    }
    else print(ans);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" * ";cout<<endl;
      }
  return 0;
}