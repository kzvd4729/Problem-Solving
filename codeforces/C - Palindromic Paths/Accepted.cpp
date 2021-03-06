/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/20/2020 13:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1205/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int mt[N+2][N+2];
 int aa[3+2][3+2];
bool ans(int a,int b,int c,int d,vector<int>v)
{
  if(a==c&&b==d)
  {
    v.push_back(aa[a][b]);
    int f=0;
    for(int i=0;i<v.size();i++)
      if(v[i]!=v[v.size()-1-i])f=1;
    return !f;
  }
  v.push_back(aa[a][b]);int ret=0;
  if(a+1<=c)ret|=ans(a+1,b,c,d,v);
  if(b+1<=d)ret|=ans(a,b+1,c,d,v);
  return ret;
}
void inv()
{
  aa[1][2]^=1;aa[2][1]^=1;
  aa[2][3]^=1;aa[3][2]^=1;
}
vector<int>ck()
{
  for(int i=1;i<=3;i++)
  {
    for(int j=1;j<=3;j++)
    {
      for(int k=i;k<=3;k++)
      {
        for(int l=j;l<=3;l++)
        {
          if(i+j+2>k+l)continue;
          vector<int>v;
          int f=ans(i,j,k,l,v);
          inv();
          if(f!=ans(i,j,k,l,v))return {i,j,k,l,f};
          inv();
        }
      }
    }
  }
  assert(0);
}
int n;
bool solve(int a,int b,int c,int d)
{
  if(a>n||a<1||b>n||b<1||c>n||c<1||d>n||d<1)return false;
  if(mt[a][b]==-1&&mt[c][d]==-1)return false;
  if(mt[a][b]!=-1&&mt[c][d]!=-1)return false;
   cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
  int x;cin>>x;
   if(mt[a][b]==-1)
  {
    if(x)mt[a][b]=mt[c][d];
    else mt[a][b]=mt[c][d]^1;
  }
  else
  {
    if(x)mt[c][d]=mt[a][b];
    else mt[c][d]=mt[a][b]^1;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)mt[i][j]=-1;
  }
  mt[1][1]=1,mt[n][n]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      solve(i,j,i+2,j);solve(i,j,i,j+2);
      solve(i,j,i+1,j+1);
    }
  }
  for(int i=1;i<=n;i++)
  {
    int f=0;
    for(int j=1;j<=n;j++)
    {
      if(mt[i][j]==-1||i+2>n||j+2>n)continue;
      if(mt[i][j]==mt[i+2][j+2]&&mt[i+2][j]==mt[i+1][j+1]&&mt[i+1][j+1]==mt[i][j+2])
        continue;
      int a=0,b,c,d;
      cout<<"? "<<i<<" "<<j+1<<" "<<i+1<<" "<<j+2<<endl;
      int x;cin>>x;
      if(x==0)c=1;else c=0;
       cout<<"? "<<i<<" "<<j+1<<" "<<i+2<<" "<<j+1<<endl;
      cin>>x;
      if(x==0)d=1;else d=0;
       cout<<"? "<<i+1<<" "<<j<<" "<<i+2<<" "<<j+1<<endl;
      cin>>x;
      if(x==0)b=d^1;else b=d;
       aa[1][1]=mt[i][j];aa[1][2]=a;
      aa[1][3]=mt[i][j+2];aa[2][1]=b;
      aa[2][2]=mt[i+1][j+1];aa[2][3]=c;
      aa[3][1]=mt[i+2][j];aa[3][2]=d;
      aa[3][3]=mt[i+2][j+2];
       vector<int>v=ck();
       cout<<"? "<<i+v[0]-1<<" "<<j+v[1]-1<<" "<<i+v[2]-1<<" "<<j+v[3]-1<<endl;
      cin>>x;if(x!=v[4])a^=1,b^=1,c^=1,d^=1;
       mt[i][j+1]=a;mt[i+1][j]=b;
      mt[i+1][j+2]=c;mt[i+2][j+1]=d;
       f=1;break;
    }
    if(f)break;
  }
  while(true)
  {
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cnt+=solve(i,j,i+2,j);
        cnt+=solve(i,j,i,j+2);
        cnt+=solve(i,j,i+1,j+1);
      }
    }
    if(cnt==0)break;
  }
  cout<<"!"<<endl;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)cout<<mt[i][j];
      cout<<endl;
  }
  return 0;
}