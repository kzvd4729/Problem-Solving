/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-23 20:12:40                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 3                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-8047
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=30;
int mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;
  while(cin>>m>>n)
  {
    memset(mt,0,sizeof(mt));
    while(m--)
    {
      char u,v;cin>>u>>v;
      mt[u-'a'][v-'a']=1;
    }
    for(int i=0;i<26;i++)
      mt[i][i]=1;
    for(int k=0;k<26;k++)
    {
      for(int i=0;i<26;i++)
      {
        for(int j=0;j<26;j++)
        {
          mt[i][j]|=(mt[i][k]&mt[k][j]);
        }
      }
    }
    while(n--)
    {
      string a,b;cin>>a>>b;
      if(a.size()!=b.size())
      {
        cout<<"no"<<endl;continue;
      }
      int f=0;
      for(int i=0;i<a.size();i++)
      {
        if(!mt[a[i]-'a'][b[i]-'a'])
          f=1;
      }
      if(f)cout<<"no"<<endl;
      else cout<<"yes"<<endl;
    }
  }
  return 0;
}