/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/12/2019 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1169 ms                                         memory_used: 218600 KB                            
*  problem: https://codeforces.com/contest/1272/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int ds[200+2][200+2][200+2];
vector<int>pt[200+2][200+2][200+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;int n=a.size(),m=b.size();
  a.push_back('#'),b.push_back('#');
   for(int bl=0;bl<=200;bl++)
  {
    for(int i=0;i<=n;i++)
      for(int j=0;j<=m;j++)ds[bl][i][j]=inf;
  }
  queue<vector<int> >q;q.push({0,0,0});ds[0][0][0]=0;
  while(q.size())
  {
    vector<int>v=q.front();q.pop();
    if(v[0]<200)
    {
      int bl=v[0]+1,i=v[1]+(a[v[1]]=='('),j=v[2]+(b[v[2]]=='(');
      if(ds[v[0]][v[1]][v[2]]+1<ds[bl][i][j])
      {
        ds[bl][i][j]=ds[v[0]][v[1]][v[2]]+1;
        q.push({bl,i,j}); 
         pt[bl][i][j]=v;
      }
    }
    if(v[0]>0)
    {
      int bl=v[0]-1,i=v[1]+(a[v[1]]==')'),j=v[2]+(b[v[2]]==')');
      if(ds[v[0]][v[1]][v[2]]+1<ds[bl][i][j])
      {
        ds[bl][i][j]=ds[v[0]][v[1]][v[2]]+1;
        q.push({bl,i,j}); 
         pt[bl][i][j]=v;
      }
    }
  }
  string ans;int bl=0,i=n,j=m;
  while(true)
  {
    if(bl==0&&i==0&&j==0)break;
    vector<int>v=pt[bl][i][j];
    if(bl>v[0])ans.push_back('(');
    else ans.push_back(')');
     bl=v[0],i=v[1],j=v[2];
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  return 0;
}