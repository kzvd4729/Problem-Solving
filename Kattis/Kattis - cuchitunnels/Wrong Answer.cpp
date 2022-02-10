/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 17:39:01                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-cuchitunnels
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2],dg[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int sm=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;sm+=x;
    aa[i]=x;bb[i]=x;
  }
  if(sm!=n*2-2)cout<<"NO\n",exit(0);

  int nd=2;
  for(int i=1;i<=n;i++)
  {
    while(aa[i]--)
    {
      if(nd>n)cout<<"NO\n",exit(0);
      dg[i]++;dg[nd]++;aa[nd]--;
      nd++;
      //if(aa[nd]<0)cout<<"NO\n",exit(0);
    }
  }
  for(int i=1;i<=n;i++)
    if(bb[i]!=dg[i])cout<<"NO\n",exit(0);
  cout<<"YES\n";
  return 0;
}