/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2020 17:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1129/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
void solve(int k)
{
  for(int l=2;l<=2000;l++)
  {
    for(int x=1;x<l-1;x++)
    {
      if((k+x*l)%(l-1))continue;
      int a=(k+x*l)/(l-1);
      if(a>N)continue;
      int mx=(a+N-1)/N;if(x)mx++;
      if(mx>l)continue;
      cout<<l<<endl;
      for(int i=1;i<=l;i++)
      {
        if(a>N){aa[i]=N;a-=N;}
        else if(a){aa[i]=a;a=0;}
        else if(x){aa[i]=-x;x=0;}
        else aa[i];
      }
      for(int i=l;i>=1;i--)cout<<aa[i]<<" ";
      cout<<endl;return ;
    }
  }
  cout<<-1<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>k;solve(k);
   return 0;
}