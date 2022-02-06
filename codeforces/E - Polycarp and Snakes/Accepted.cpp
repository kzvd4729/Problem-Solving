/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2019 02:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 57200 KB                             
*  problem: https://codeforces.com/contest/1185/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
char mt[N+2][N+2],tmp[N+2][N+2];
int aa[N+2],bb[N+2],cc[N+2],dd[N+2],vis[30];
vector<pair<int,int> >v;
bool isHori(void)
{
  int ok=-1;
  for(auto x:v)
  {
    if(ok==-1)ok=x.second;
    if(x.second!=ok)return false;
  }
  return true;
}
bool isVerti(void)
{
  int ok=-1;
  for(auto x:v)
  {
    if(ok==-1)ok=x.first;
    if(x.first!=ok)return false;
  }
  return true;
}
void colorHori(int a,int b,int c,char d)
{
  for(int i=a;i<=b;i++)
    tmp[i][c]=d;
}
void colorVerti(int a,int b,int c,char d)
{
  for(int i=a;i<=b;i++)
    tmp[c][i]=d;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;int f=0,pt;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
      string s;cin>>s;
      for(int j=1;j<=m;j++)
        mt[i][j]=s[j-1],tmp[i][j]='.';
    }
    int mx=0;
    for(char ch='a';ch<='z';ch++)
    {
      v.clear();pt=ch-'a'+1;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          if(mt[i][j]==ch)
            v.push_back({i,j});
        }
      }
      if(v.size()==0)continue;vis[pt]=1;
      mx=pt;
      if(isHori())
      {
        int a=1e9,b=0,c;c=v[0].second;
        for(auto x:v)
        {
          a=min(a,x.first);
          b=max(b,x.first);
        }
        colorHori(a,b,c,ch);
        aa[pt]=a,bb[pt]=c,cc[pt]=b,dd[pt]=c;
      }
      else if(isVerti())
      {
        int a=1e9,b=0,c;c=v[0].first;
        for(auto x:v)
        {
          a=min(a,x.second);
          b=max(b,x.second);
        }
        colorVerti(a,b,c,ch);
        aa[pt]=c,bb[pt]=a,cc[pt]=c,dd[pt]=b;
      }
      else f=1;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(mt[i][j]!=tmp[i][j])
          f=1;
      }
    }
    if(f){cout<<"NO"<<"\n";continue;}
    int x,y;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(mt[i][j]-'a'+1==mx)
          x=i,y=j;
      }
    }
    cout<<"YES"<<"\n";
    cout<<mx<<"\n";
    for(int i=1;i<=mx;i++)
    {
      if(vis[i])cout<<aa[i]<<" "<<bb[i]<<" "<<cc[i]<<" "<<dd[i]<<"\n";
      else cout<<x<<" "<<y<<" "<<x<<" "<<y<<"\n";
    }
  }
  return 0;
}