/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2019 13:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 3000 KB                              
*  problem: https://codeforces.com/contest/1267/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;
char mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,l,k;cin>>n>>l>>k;
   string s;cin>>s;sort(s.begin(),s.end());
   for(int i=1;i<=n;i++)
    for(int j=1;j<=l;j++)mt[i][j]='.';
   int pr=1,pt=0;char ls='.';
  for(int j=1;j<=l;j++)
  {
    for(int i=pr;i<=k;i++)
    {
      char c=s[pt++];mt[i][j]=c;
      if(c!=ls)ls=c,pr=i;
    }
    ls='.';
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=l;j++)
    {
      if(mt[i][j]=='.')mt[i][j]=s[pt++];
      cout<<mt[i][j];
    }
    cout<<endl;
  }
  return 0;
}