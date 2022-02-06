/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/01/2019 22:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 6600 KB                              
*  problem: https://codeforces.com/contest/1186/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;int n=b.size();
  int one=0;
  for(auto x:b)
    if(x=='1')one++;
  for(int i=0;i<a.size();i++)
    qm[i+1]=qm[i]+a[i]-'0';
  int ans=0;
  for(int i=n;i<=a.size();i++)
  {
    if((one-(qm[i]-qm[i-n]))%2==0)ans++;
    //cout<<(qm[i]-qm[i-n])<<endl;
    //cout<<(n-one-(qm[i]-qm[i-n]))<<endl;
  }
  cout<<ans<<endl;
  return 0;
}