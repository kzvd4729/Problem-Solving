/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2020 12:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 122900 KB                            
*  problem: https://codeforces.com/contest/557/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
bool dp[N+2][N+2];
int n,mt[N+2][N+2];
string s;
int dfs(int i,int j)
{
  if(i==s.size()||j==s.size())return 0;
  if(s[i]!=s[j])return 0;
  if(mt[i][j]!=-1)return mt[i][j];
  return mt[i][j]=1+dfs(i+1,j+1);
}
int pt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s;n=s.size();int k;cin>>k;
  for(int i=0;i<n;i++)dp[i][i]=1;
  for(int i=0;i<n-1;i++)if(s[i]==s[i+1])dp[i][i+1]=1;
  for(int i=0;i<n-2;i++)if(s[i]==s[i+2])dp[i][i+2]=1;
  for(int i=0;i<n-3;i++)if(s[i]==s[i+3])dp[i][i+3]=1;
  for(int l=5;l<=n;l++)
  {
    for(int i=0; ;i++)
    {
      int j=i+l-1;if(j>=n)break;
      dp[i][j]=((s[i]==s[j])&dp[i+2][j-2]);
    }
  }
  vector<int>v;for(int i=0;i<n;i++)v.push_back(i);
  memset(mt,-1,sizeof(mt));
  sort(v.begin(),v.end(),[](int i,int j){
    int l=dfs(i,j);
    if(i==j)return true;
    if(i+l==n)return true;
    if(j+l==n)return false;
    return s[i+l]<s[j+l];
  });
  for(int i=0;i<v.size();i++)
  {
    int x=v[i];
    while(x+pt[i]<n)
    {
      int in=pt[i];
      for(int j=i;j<v.size();j++)
      {
        if(pt[j]<in)break;
        if(s[x+in]!=s[v[j]+pt[j]])break;
        pt[j]++;k-=dp[v[j]][v[j]+pt[j]-1];
        if(!k)cout<<s.substr(v[j],pt[j])<<endl,exit(0);
        //cout<<j<<" "<<pt[j]<<endl;
      }
    } 
  }
  assert(0);
  return 0;
}