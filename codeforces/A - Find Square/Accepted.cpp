/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/28/2018 09:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1028/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
char mat[120][120];
int mxr,mxc,mnr=1e7,mnc=1e7;
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n,m;cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  string s;cin>>s;
  for(int j=1;j<=m;j++)
  {
   mat[i][j]=s[j-1];
   if(mat[i][j]=='B')
   {
    mxr=max(mxr,i),mxc=max(mxc,j);
    mnr=min(mnr,i),mnc=min(mnc,j);
   }
  }
 }
 cout<<(mxr+mnr)/2<<" "<<(mxc+mnc)/2<<endl;
 return 0;
}