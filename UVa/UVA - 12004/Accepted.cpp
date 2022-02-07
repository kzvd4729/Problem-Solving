/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 16:50:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12004
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
long up[N+2],dw[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  up[1]=0;dw[1]=1;up[2]=1;dw[2]=2;
  for(int i=3;i<=N;i++)
    dw[i]=2,up[i]=up[i-1]+(i-1)*1LL;
  int t,tc=0;cin>>t;
  while(t--)
  {
    cout<<"Case "<<++tc<<": ";
    int i;cin>>i;
    if(up[i]%dw[i]==0)cout<<up[i]/dw[i]<<"\n";
    else cout<<up[i]<<"/"<<dw[i]<<"\n";
  }
  return 0;
}