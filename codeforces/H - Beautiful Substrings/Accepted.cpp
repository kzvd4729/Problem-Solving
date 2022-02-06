/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/24/2019 01:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/gym/101972/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[26][26],cnt[26];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;
    string a,b;cin>>a>>b;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
      int j=(i+k-1);if(j>=n)break;
      vis[a[i]-'a'][a[j]-'a']=1;
    }
    long ans=0;memset(cnt,0,sizeof(cnt));
    for(int i=0;i<m;i++)
    {
      int c=b[i]-'a';cnt[c]++;
      for(int j=0;j<26;j++)
      {
        ans+=(cnt[j]*1LL)*vis[j][c];
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}