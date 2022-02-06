/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2020 14:09                        
*  solution_verdict: Wrong answer on test 21                 language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 10500 KB                             
*  problem: https://codeforces.com/contest/808/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
map<int,int>mp1,mp2;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long sm1=0,sm2=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];mp2[aa[i]]=1;
    sm2+=aa[i];
  }
  for(int i=0;i<=n;i++)
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