/****************************************************************************************
*  @author: kzvd4729                                         created: May/01/2019 20:47                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1156/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int f=0,ans=0;
  for(int i=n-1;i>=1;i--)
  {
    if(aa[i+1]==1&&aa[i]==2)
    {
      ans+=3;
    }
    if(aa[i+1]==1&&aa[i]==3)
    {
      ans+=4;
    }
    if(aa[i+1]==2&&aa[i]==1)
    {
      ans+=3;
    }
    if(aa[i+1]==2&&aa[i]==3)
    {
      f=1;
    }
    if(aa[i+1]==3&&aa[i]==1)
    {
      ans+=4;
    }
    if(aa[i+1]==3&&aa[i]==2)
    {
      f=1;
    }
  }
  if(f)cout<<"Infinite"<<endl;
  else cout<<"Finite"<<endl<<ans<<endl;
  return 0;
}