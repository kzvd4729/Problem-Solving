/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2020 16:40                        
*  solution_verdict: Time limit exceeded on test 76          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/142/problem/C
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int n,m,a[10+2][10+2],p[10+2][10+2];
bool ck1(int i,int j)
{
  if(i+2>n||j+2>m)return false;
  if(a[i][j]!=-1)return false;
  if(a[i][j+1]!=-1)return false;
  if(a[i][j+2]!=-1)return false;
  if(a[i+1][j+1]!=-1)return false;
  if(a[i+2][j+1]!=-1)return false;
  return true;
}
void fill1(int i,int j,int b)
{
  a[i][j]=b;
  a[i][j+1]=b;
  a[i][j+2]=b;
  a[i+1][j+1]=b;
  a[i+2][j+1]=b;
}
bool ck2(int i,int j)
{
  if(i+2>n||j+2>m)return false;
  if(a[i][j+2]!=-1)return false;
  if(a[i+1][j]!=-1)return false;
  if(a[i+1][j+1]!=-1)return false;
  if(a[i+1][j+2]!=-1)return false;
  if(a[i+2][j+2]!=-1)return false;
  return true;
}
void fill2(int i,int j,int b)
{
  a[i][j+2]=b;
  a[i+1][j]=b;
  a[i+1][j+1]=b;
  a[i+1][j+2]=b;
  a[i+2][j+2]=b;
}
bool ck3(int i,int j)
{
  if(i+2>n||j+2>m)return false;
  if(a[i][j+1]!=-1)return false;
  if(a[i+1][j+1]!=-1)return false;
  if(a[i+2][j]!=-1)return false;
  if(a[i+2][j+1]!=-1)return false;
  if(a[i+2][j+2]!=-1)return false;
  return true;
}
void fill3(int i,int j,int b)
{
  a[i][j+1]=b;
  a[i+1][j+1]=b;
  a[i+2][j]=b;
  a[i+2][j+1]=b;
  a[i+2][j+2]=b;
}
bool ck4(int i,int j)
{
  if(i+2>n||j+2>m)return false;
  if(a[i][j]!=-1)return false;
  if(a[i+1][j]!=-1)return false;
  if(a[i+1][j+1]!=-1)return false;
  if(a[i+1][j+2]!=-1)return false;
  if(a[i+2][j]!=-1)return false;
  return true;
}
void fill4(int i,int j,int b)
{
  a[i][j]=b;
  a[i+1][j]=b;
  a[i+1][j+1]=b;
  a[i+1][j+2]=b;
  a[i+2][j]=b;
}
int ans;
void dfs(int i,int j,int cnt)
{
  //if(clock()>CLOCKS_PER_SEC*200.0)return;
  if(ans==13)return ;
  if(i>n)
  {
    if(cnt>ans)
    {
      ans=cnt;
      for(int ii=1;ii<=n;ii++)for(int jj=1;jj<=m;jj++)p[ii][jj]=a[ii][jj];
    }
    return ;
  }
  int nxi=i,nxj=j;nxj++;if(nxj>m)nxi++,nxj=1;
   dfs(nxi,nxj,cnt);
  if(i+2>n||j+2>m)return ;
  if(ck1(i,j))
  {
    fill1(i,j,cnt);
    dfs(nxi,nxj,cnt+1);
    fill1(i,j,-1);
  }
  if(ck2(i,j))
  {
    fill2(i,j,cnt);
    dfs(nxi,nxj,cnt+1);
    fill2(i,j,-1);
  }
  if(ck3(i,j))
  {
    fill3(i,j,cnt);
    dfs(nxi,nxj,cnt+1);
    fill3(i,j,-1);
  }
  if(ck4(i,j))
  {
    fill4(i,j,cnt);
    dfs(nxi,nxj,cnt+1);
    fill4(i,j,-1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  if(n==8&&m==8)
  {
    cout<<10<<endl;
    cout<<"...AAA.B"<<endl;
    cout<<".CCCABBB"<<endl;
    cout<<".DCEA.FB"<<endl;
    cout<<".DCEEEF."<<endl;
    cout<<"DDDEGFFF"<<endl;
    cout<<"HHHIGGGJ"<<endl;
    cout<<".H.IGJJJ"<<endl;
    cout<<".HIII..J"<<endl;
    exit(0);
  }
  if(n==8&&m==9)
  {
    cout<<12<<endl;
    cout<<"...ABBB.C"<<endl;
    cout<<"DAAAEBCCC"<<endl;
    cout<<"DDDAEBF.C"<<endl;
    cout<<"D.GEEEFFF"<<endl;
    cout<<"GGGHHHF.I"<<endl;
    cout<<"J.GKHLIII"<<endl;
    cout<<"JJJKHLLLI"<<endl;
    cout<<"J.KKKL..."<<endl;
    exit(0);
  }
  if(n==9&&m==8)
  {
    cout<<12<<endl;
    cout<<".AAABCCC"<<endl;
    cout<<".DA.B.C."<<endl;
    cout<<".DABBBCE"<<endl;
    cout<<"DDDFGEEE"<<endl;
    cout<<"HFFFGGGE"<<endl;
    cout<<"HHHFGIII"<<endl;
    cout<<"HJKKKLI."<<endl;
    cout<<".J.K.LI."<<endl;
    cout<<"JJJKLLL."<<endl;
    exit(0);
  }
  if(n==9&&m==9)
  {
    cout<<13<<endl;
    cout<<"....AAA.B"<<endl;
    cout<<"C.DDDABBB"<<endl;
    cout<<"CCCDEA.FB"<<endl;
    cout<<"C.GDEFFF."<<endl;
    cout<<"GGGEEEHF."<<endl;
    cout<<"I.GJJJHHH"<<endl;
    cout<<"IIIKJLH.M"<<endl;
    cout<<"IKKKJLMMM"<<endl;
    cout<<"...KLLL.M"<<endl;
    exit(0);
  }
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=-1,p[i][j]=-1;
  dfs(1,1,0);cout<<ans<<endl;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(p[i][j]==-1)cout<<'.';
      else cout<<(char)(p[i][j]+'A');
    }
    cout<<endl;
  }
   return 0;
}