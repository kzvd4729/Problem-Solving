/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2018 21:04                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/984/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,cnt[102][102];
string s;
char mat[102][102];
vector<pair<int,int> >v;
int dr[]={1,-1,0,0,1,-1,1,-1};
int dc[]={0,0,1,-1,1,1,-1,-1};
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    for(int j=1;j<=m;j++)
    {
      mat[i][j]=s[j-1];
      if(mat[i][j]=='*')
        v.push_back({i,j});
    }
  }
  for(auto x:v)
  {
    int r=x.first;
    int c=x.second;
    for(int i=0;i<8;i++)
      cnt[r+dr[i]][c+dc[i]]++;
  }
  int f=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(mat[i][j]=='.'&&cnt[i][j])f=1;
      int x=mat[i][j]-'0';
      if(x>=1&&x<=8&&cnt[i][j]!=x)f=1;
    }
  }
  if(f)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  return 0;
}