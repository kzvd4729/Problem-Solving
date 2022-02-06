/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2020 14:14                        
*  solution_verdict: Wrong answer on test 60                 language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 19800 KB                             
*  problem: https://codeforces.com/contest/808/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
map<long,long>mp1,mp2;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;long sm1=0,sm2=0;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i];mp2[aa[i]]=1;
    sm2+=aa[i];
  }
  for(long i=0;i<=n+1;i++)
  {
    sm1+=aa[i];sm2-=aa[i];
    if(aa[i])mp1[aa[i]]=1;mp2[aa[i]]=0;
    if(sm1==sm2)cout<<"YES\n",exit(0);
    if(sm1>sm2)
    {
      if((sm1-sm2)%2==0&&mp1[(sm1-sm2)/2])cout<<"YES\n",exit(0);
    }
    else
    {
      if((sm2-sm1)%2==0&&mp2[(sm2-sm1)/2])cout<<"YES\n",exit(0);
    }
  }
  cout<<"NO\n";
  return 0;
}