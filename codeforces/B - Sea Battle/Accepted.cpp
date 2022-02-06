/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2019 21:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4400 KB                              
*  problem: https://codeforces.com/contest/737/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,a,b,k;cin>>n>>a>>b>>k;
  string s;cin>>s;
  int cnt=0;
  for(int i=n-1;i>=0;i--)
  {
    qm[i]=qm[i+1];
    if(s[i]=='0')cnt++;
    if(cnt==b)
    {
      qm[i]++;cnt=0;
    }
    if(s[i]=='1')cnt=0;
  }
  cout<<qm[0]-a+1<<endl;
  int pt=n-1;
  for(int i=1;i<=qm[0]-a+1;i++)
  {
    while(qm[pt]!=i)pt--;
    cout<<pt+1<<" ";
  }
  cout<<endl;
  return 0;
}