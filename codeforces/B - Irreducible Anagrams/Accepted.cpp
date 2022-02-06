/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/04/2020 18:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 20900 KB                             
*  problem: https://codeforces.com/contest/1290/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,inf=1e9;
int qm[26][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s;cin>>s;
  for(int i=1;i<=s.size();i++)
  {
    for(int j=0;j<26;j++)qm[j][i]=qm[j][i-1];
    qm[s[i-1]-'a'][i]++;
  }
  int q;cin>>q;
  while(q--)
  {
    int l,r;cin>>l>>r;
    if(l==r){cout<<"Yes\n";continue;}
    if(s[l-1]!=s[r-1]){cout<<"Yes\n";continue;}
    int cnt=0;
    for(int j=0;j<26;j++)
      cnt+=bool(qm[j][r]-qm[j][l-1]);
    if(cnt<=2)cout<<"No\n";
    else cout<<"Yes\n";
  }
  return 0;
}