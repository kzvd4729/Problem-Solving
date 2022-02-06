/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/16/2019 20:19                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1174/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x;cin>>n>>x;
  if(n==1&&x==1)cout<<0<<endl,exit(0);
  if(x==1)aa[1]=2;else aa[1]=1;
  int pt=2;
  while(true)
  {
    int ff=0;
    for(int ii=1;ii<(1<<n);ii++)
    {
      int f=0;aa[pt]=ii;
      for(int i=1;i<=pt;i++)
      {
        int xx=0,g=0;
        for(int j=i;j<=pt;j++)
        {
          xx^=aa[j];
          if(xx==0||xx==x){g=1;break;}
        }
        if(g){f=1;break;}
      }
      if(!f){aa[pt++]=ii;ff=1;break;}
    }
    if(!ff)break;
  }
  cout<<pt-1<<endl;
  for(int i=1;i<pt;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}