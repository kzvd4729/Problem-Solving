/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2019 21:12                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1209/problem/E1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int mt[5][N+2],mx[N+2],n,sm[5],print;
void rotate(int j)
{
  int tmp=mt[1][j];
  for(int i=1;i<n;i++)
    mt[i][j]=mt[i+1][j];
  mt[n][j]=tmp;
}
int mxx(int a,int b,int c,int d)
{
  return max(max(max(a,b),c),d);
}
int cal(vector<pair<int,int> >v)
{
  int a=v[0].second,b=v[1].second,c=v[2].second,d=v[3].second;
  int tmp;
  for(int i=1;i<=5;i++)
  {
    rotate(a);
    for(int j=1;j<=5;j++)
    {
      rotate(b);
      for(int k=1;k<=5;k++)
      {
        rotate(c);
        for(int l=1;l<=5;l++)
        {
          rotate(d);int sm=0;
          for(int id=1;id<=n;id++)
            sm+=mxx(mt[id][a],mt[id][b],mt[id][c],mt[id][d]);
          print=max(print,sm);
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int m;cin>>n>>m;
    memset(mt,0,sizeof(mt));
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
        cin>>mt[i][j];
    }
    memset(mx,0,sizeof(mx));
    vector<pair<int,int> >v;
    if(m<4)m=4;
    for(int j=1;j<=m;j++)
    {
      for(int i=1;i<=n;i++)
      {
        mx[j]=max(mx[j],mt[i][j]);
      }
      v.push_back({mx[j],j});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    print=0;
    cout<<cal(v)<<"\n";
  }
  return 0;
}