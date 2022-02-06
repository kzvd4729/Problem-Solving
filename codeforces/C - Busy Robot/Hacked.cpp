/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2020 21:41                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1463/problem/C
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
const int N=1e6;
int tt[N+2],xx[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
      cin>>tt[i]>>xx[i];
    tt[n+1]=2e9;
     int cnt=0,ls=0,x1=0,x2=0;
    for(int i=1;i<=n;i++)
    {
      //cout<<ls<<" "<<x1<<" "<<x2<<endl;
      if(x1!=x2)
      {
        int df=tt[i]-1-ls;
        if(x1<x2)
        {
          if(x2-x1>df)x1+=df;
          else x1=x2;
        }
        else
        {
          if(x1-x2>df)x1-=df;
          else x1=x2;
        }
        ls=tt[i]-1;
      }
      if(x1==x2)
      {
        ls=tt[i]-1;x2=xx[i];
      }
      //cout<<ls<<" "<<x1<<" "<<x2<<endl;
      if(xx[i]>=min(x1,x2)&&xx[i]<=max(x1,x2))
      {
        if(abs(xx[i]-x1)<=tt[i+1]-tt[i])cnt++;
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}