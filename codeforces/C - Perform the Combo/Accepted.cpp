/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2020 15:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 4400 KB                              
*  problem: https://codeforces.com/contest/1311/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];long cnt[27];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    string s;cin>>s;aa[0]=0;
    for(int i=1;i<=n;i++)aa[i]=0;
    for(int i=1;i<=m;i++)
    {
      int x;cin>>x;aa[0]++;
      aa[x+1]--;
    }
    aa[0]++,aa[n+1]--;memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
      aa[i]+=aa[i-1];int c=s[i-1]-'a';
      cnt[c]+=aa[i];
    }
    for(int i=0;i<26;i++)
      cout<<cnt[i]<<" ";
    cout<<endl;
  }
  return 0;
}