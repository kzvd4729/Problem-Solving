/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2020 17:46                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1129/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
void solve(int k)
{
  for(int l=2;l<=2000;l++)
  {
    for(int x=0;k<l-1;x++)
    {
      if((k+x*l)%(l-1))continue;
      int a=(k+x*l)/(l-1);
      int mx=(a+N-1)/N;if(x)mx++;
      if(mx>l)continue;
      cout<<l<<endl;
      for(int i=1;i<=l;i++)
      {
        if(a>N){cout<<N<<" ";a-=N;}
        else if(a){cout<<a<<" ";a=0;}
        else if(x){cout<<-x<<" ";x=0;}
        else cout<<0<<" ";
      }
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