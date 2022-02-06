/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/31/2019 22:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 685 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1144/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],mx,vl,fr[N+2],id;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];fr[aa[i]]++;
    if(fr[aa[i]]>mx)
    {
      mx=fr[aa[i]];vl=aa[i];
      id=i;
    }
  }
  cout<<n-mx<<endl;
  for(int i=id+1;i<=n;i++)
  {
    if(aa[i]==vl)continue;
    if(aa[i]>vl)
      cout<<2<<" "<<i<<" "<<i-1<<endl;
    else cout<<1<<" "<<i<<" "<<i-1<<endl;
  }
  for(int i=id-1;i>=1;i--)
  {
    if(aa[i]==vl)continue;
    if(aa[i]>vl)
      cout<<2<<" "<<i<<" "<<i+1<<endl;
    else cout<<1<<" "<<i<<" "<<i+1<<endl;
  }
  return 0;
}