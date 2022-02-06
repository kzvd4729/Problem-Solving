/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/28/2019 23:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1283/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;fr[x]++;
  }
  int mx=0,f=-1;
  for(int i=1;i<=n;i++)
  {
    if(fr[i]==0){if(f==1)f=0;else f=-1;}
    else if(fr[i]==1)mx++;
    else if(fr[i]==2){if(f==-1)mx+=2,f=0;else if(f==0)mx+=2,f=1;else mx++,f=1;}
    else {if(f==-1)mx+=3,f=1;else if(f==0)mx+=2,f=1;else mx++,f=1;}
  }
  int mn=0;f=-1;
  for(int i=1;i<=n;i++)
  {
    if(fr[i]==0){if(f==1)f=0;else f=-1;}
    else {if(f==-1)mn++,f=1;else if(f==0)f=-1;else f=0;}
  }
  cout<<mn<<" "<<mx<<endl;
  return 0;
}